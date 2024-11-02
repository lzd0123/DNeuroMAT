#include "dialog.h"

InterfaceDialog::InterfaceDialog(V3DPluginCallback2 &callback) :
        ui(new Ui::Dialog),
        varFactory(new QtVariantEditorFactory(this)),
//        propertyManagers{new QtVariantPropertyManager(this),
//                         new QtVariantPropertyManager(this),
//                         new QtVariantPropertyManager(this)},
//        propertyBrowsers{nullptr, nullptr, nullptr},
//        methodLists{nullptr, nullptr, nullptr},
//        methodIndex{-1, -1, -1},
        dPos(0, 0), uiPos(0, 0), uiWidth(0), uiHeight(0),
        marginSize(10), dragFlag(0) {
    ui->setupUi(this);
    this->setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint);
    this->setAttribute(Qt::WA_TranslucentBackground);

    propertyManagers[0] = new QtVariantPropertyManager(this);
    propertyManagers[1] = new QtVariantPropertyManager(this);
    propertyManagers[2] = new QtVariantPropertyManager(this);

    propertyBrowsers[0] = ui->segParaBrowser;
    propertyBrowsers[1] = ui->traParaBrowser;
    propertyBrowsers[2] = ui->detParaBrowser;

    methodLists[0] = ui->segMethodList;
    methodLists[1] = ui->traMethodList;
    methodLists[2] = ui->detMethodList;

    methodIndex[0] = methodIndex[1] = methodIndex[2] = -1;

    ui->segParaBrowser->setHeaderVisible(false);
    ui->segParaBrowser->setFactoryForManager(propertyManagers[0], varFactory);

    ui->traParaBrowser->setHeaderVisible(false);
    ui->traParaBrowser->setFactoryForManager(propertyManagers[1], varFactory);

    ui->detParaBrowser->setHeaderVisible(false);
    ui->detParaBrowser->setFactoryForManager(propertyManagers[2], varFactory);

    auto buttonMenu = new QMenu(ui->selectImageButton);
    QAction *selectImageFileAct = buttonMenu->addAction(QIcon(":/src/pics/file-128.png"), "File");
    QAction *selectImageDirAct = buttonMenu->addAction(QIcon(":/src/pics/standardbutton-open-128.png"), "Directory");
    ui->selectImageButton->setMenu(buttonMenu);

    ui->segAddButton->setMethodList(ui->segMethodList);
    ui->segDelButton->setMethodList(ui->segMethodList);
    ui->segUpButton->setMethodList(ui->segMethodList);
    ui->segDownButton->setMethodList(ui->segMethodList);

    ui->traAddButton->setMethodList(ui->traMethodList);
    ui->traDelButton->setMethodList(ui->traMethodList);
    ui->traUpButton->setMethodList(ui->traMethodList);
    ui->traDownButton->setMethodList(ui->traMethodList);

    ui->detAddButton->setMethodList(ui->detMethodList);
    ui->detDelButton->setMethodList(ui->detMethodList);
    ui->detUpButton->setMethodList(ui->detMethodList);
    ui->detDownButton->setMethodList(ui->detMethodList);

    readCache();
    for (int i = ui->Tab->count() - 1; i >= 0; --i) {
        currentTab = i;
        if (methodLists[currentTab]->count()) {
            methodLists[currentTab]->setCurrentRow(0);
            readParameter();
        } else {
            methodLists[currentTab]->setCurrentRow(-1);
        }
    }
    ui->Tab->setCurrentIndex(0);

    v3dhandle curWin = callback.currentImageWindow();
    if (curWin) {
        QString imageName = callback.getImageName(curWin);
        ui->imagePath->setText(imageName);
        ui->imagePath->setEnabled(false);
        ui->selectImageButton->setEnabled(false);
    }

    connect(selectImageFileAct, SIGNAL(triggered(bool)), this, SLOT(selectImageFile()));
    connect(selectImageDirAct, SIGNAL(triggered(bool)), this, SLOT(selectImageDir()));
    connect(ui->editEnvButton, SIGNAL(clicked(bool)), this, SLOT(editPythonEnv()));
    connect(ui->selectOutputButton, SIGNAL(clicked(bool)), this, SLOT(selectOutputPath()));
    connect(ui->ok, SIGNAL(clicked(bool)), this, SLOT(accept()));
    connect(ui->cancel, SIGNAL(clicked(bool)), this, SLOT(reject()));

    connect(ui->segAddButton, SIGNAL(clicked(bool)), ui->segAddButton, SLOT(sendChangeSignal()));
    connect(ui->segAddButton, SIGNAL(changed(QListWidget * )), this, SLOT(addMethod(QListWidget * )));
    connect(ui->segDelButton, SIGNAL(clicked(bool)), ui->segDelButton, SLOT(sendChangeSignal()));
    connect(ui->segDelButton, SIGNAL(changed(QListWidget * )), this, SLOT(delMethod(QListWidget * )));
    connect(ui->segUpButton, SIGNAL(clicked(bool)), ui->segUpButton, SLOT(sendChangeSignal()));
    connect(ui->segUpButton, SIGNAL(changed(QListWidget * )), this, SLOT(moveUpMethod(QListWidget * )));
    connect(ui->segDownButton, SIGNAL(clicked(bool)), ui->segDownButton, SLOT(sendChangeSignal()));
    connect(ui->segDownButton, SIGNAL(changed(QListWidget * )), this, SLOT(moveDownMethod(QListWidget * )));

    connect(ui->traAddButton, SIGNAL(clicked(bool)), ui->traAddButton, SLOT(sendChangeSignal()));
    connect(ui->traAddButton, SIGNAL(changed(QListWidget * )), this, SLOT(addMethod(QListWidget * )));
    connect(ui->traDelButton, SIGNAL(clicked(bool)), ui->traDelButton, SLOT(sendChangeSignal()));
    connect(ui->traDelButton, SIGNAL(changed(QListWidget * )), this, SLOT(delMethod(QListWidget * )));
    connect(ui->traUpButton, SIGNAL(clicked(bool)), ui->traUpButton, SLOT(sendChangeSignal()));
    connect(ui->traUpButton, SIGNAL(changed(QListWidget * )), this, SLOT(moveUpMethod(QListWidget * )));
    connect(ui->traDownButton, SIGNAL(clicked(bool)), ui->traDownButton, SLOT(sendChangeSignal()));
    connect(ui->traDownButton, SIGNAL(changed(QListWidget * )), this, SLOT(moveDownMethod(QListWidget * )));

    connect(ui->detAddButton, SIGNAL(clicked(bool)), ui->detAddButton, SLOT(sendChangeSignal()));
    connect(ui->detAddButton, SIGNAL(changed(QListWidget * )), this, SLOT(addMethod(QListWidget * )));
    connect(ui->detDelButton, SIGNAL(clicked(bool)), ui->detDelButton, SLOT(sendChangeSignal()));
    connect(ui->detDelButton, SIGNAL(changed(QListWidget * )), this, SLOT(delMethod(QListWidget * )));
    connect(ui->detUpButton, SIGNAL(clicked(bool)), ui->detUpButton, SLOT(sendChangeSignal()));
    connect(ui->detUpButton, SIGNAL(changed(QListWidget * )), this, SLOT(moveUpMethod(QListWidget * )));
    connect(ui->detDownButton, SIGNAL(clicked(bool)), ui->detDownButton, SLOT(sendChangeSignal()));
    connect(ui->detDownButton, SIGNAL(changed(QListWidget * )), this, SLOT(moveDownMethod(QListWidget * )));

    ui->segAddParaButton->setParaBrowser(ui->segParaBrowser);
    ui->segDelParaButton->setParaBrowser(ui->segParaBrowser);
    ui->segEditNameButton->setParaBrowser(ui->segParaBrowser);

    ui->traAddParaButton->setParaBrowser(ui->traParaBrowser);
    ui->traDelParaButton->setParaBrowser(ui->traParaBrowser);
    ui->traEditNameButton->setParaBrowser(ui->traParaBrowser);

    ui->detAddParaButton->setParaBrowser(ui->detParaBrowser);
    ui->detDelParaButton->setParaBrowser(ui->detParaBrowser);
    ui->detEditNameButton->setParaBrowser(ui->detParaBrowser);

    connect(ui->segAddParaButton, SIGNAL(clicked(bool)), ui->segAddParaButton, SLOT(sendChangeSignal()));
    connect(ui->segAddParaButton, SIGNAL(changed(QtTreePropertyBrowser * )), this,
            SLOT(addParameter(QtTreePropertyBrowser * )));
    connect(ui->segDelParaButton, SIGNAL(clicked(bool)), ui->segDelParaButton, SLOT(sendChangeSignal()));
    connect(ui->segDelParaButton, SIGNAL(changed(QtTreePropertyBrowser * )), this,
            SLOT(delParameter(QtTreePropertyBrowser * )));
    connect(ui->segEditNameButton, SIGNAL(clicked(bool)), ui->segEditNameButton, SLOT(sendChangeSignal()));
    connect(ui->segEditNameButton, SIGNAL(changed(QtTreePropertyBrowser * )), this,
            SLOT(editParameterName(QtTreePropertyBrowser * )));

    connect(ui->traAddParaButton, SIGNAL(clicked(bool)), ui->traAddParaButton, SLOT(sendChangeSignal()));
    connect(ui->traAddParaButton, SIGNAL(changed(QtTreePropertyBrowser * )), this,
            SLOT(addParameter(QtTreePropertyBrowser * )));
    connect(ui->traDelParaButton, SIGNAL(clicked(bool)), ui->traDelParaButton, SLOT(sendChangeSignal()));
    connect(ui->traDelParaButton, SIGNAL(changed(QtTreePropertyBrowser * )), this,
            SLOT(delParameter(QtTreePropertyBrowser * )));
    connect(ui->traEditNameButton, SIGNAL(clicked(bool)), ui->traEditNameButton, SLOT(sendChangeSignal()));
    connect(ui->traEditNameButton, SIGNAL(changed(QtTreePropertyBrowser * )), this,
            SLOT(editParameterName(QtTreePropertyBrowser * )));

    connect(ui->detAddParaButton, SIGNAL(clicked(bool)), ui->detAddParaButton, SLOT(sendChangeSignal()));
    connect(ui->detAddParaButton, SIGNAL(changed(QtTreePropertyBrowser * )), this,
            SLOT(addParameter(QtTreePropertyBrowser * )));
    connect(ui->detDelParaButton, SIGNAL(clicked(bool)), ui->detDelParaButton, SLOT(sendChangeSignal()));
    connect(ui->detDelParaButton, SIGNAL(changed(QtTreePropertyBrowser * )), this,
            SLOT(delParameter(QtTreePropertyBrowser * )));
    connect(ui->detEditNameButton, SIGNAL(clicked(bool)), ui->detEditNameButton, SLOT(sendChangeSignal()));
    connect(ui->detEditNameButton, SIGNAL(changed(QtTreePropertyBrowser * )), this,
            SLOT(editParameterName(QtTreePropertyBrowser * )));

    connect(methodLists[0], SIGNAL(itemClicked(QListWidgetItem * )), this, SLOT(readParameter()));
    connect(methodLists[0], SIGNAL(itemDoubleClicked(QListWidgetItem * )), this,
            SLOT(editMethodName(QListWidgetItem * )));
    connect(methodLists[1], SIGNAL(itemClicked(QListWidgetItem * )), this, SLOT(readParameter()));
    connect(methodLists[1], SIGNAL(itemDoubleClicked(QListWidgetItem * )), this,
            SLOT(editMethodName(QListWidgetItem * )));
    connect(methodLists[2], SIGNAL(itemClicked(QListWidgetItem * )), this, SLOT(readParameter()));
    connect(methodLists[2], SIGNAL(itemDoubleClicked(QListWidgetItem * )), this,
            SLOT(editMethodName(QListWidgetItem * )));
    connect(ui->closeButton, SIGNAL(clicked(bool)), this, SLOT(close()));
    connect(ui->Tab, SIGNAL(currentChanged(int)), this, SLOT(saveParameter()));
    connect(this, SIGNAL(finished(int)), this, SLOT(saveCache()));
    connect(this, SIGNAL(finished(int)), this, SLOT(saveParameter()));

}

InterfaceDialog::~InterfaceDialog() {
    delete ui;
}

bool InterfaceDialog::readCache() {
    QFile methodFile("../../vaa3d_tools/released_plugins/v3d_plugins/DNeuroMAT/cache/methods.cache");
    if (!methodFile.open(QFile::ReadWrite)) return false;
    QTextStream methodStream(&methodFile);
    int tabIndex = -1;
    QString methodName;
    while (!methodStream.atEnd()) {
        methodStream >> tabIndex;
        methodStream >> methodName;
        if (methodName.isEmpty()) continue;
        QListWidgetItem *item = new QListWidgetItem(methodName, methodLists[tabIndex]);
    }
    methodFile.close();
    QFile envFile("../../vaa3d_tools/released_plugins/v3d_plugins/DNeuroMAT/cache/envs.cache");
    if (!envFile.open(QFile::ReadWrite)) return false;
    QTextStream envStream(&envFile);
    QString envName;
    while (!envStream.atEnd()) {
        envStream >> envName;
        if (envName.isEmpty()) continue;
        else if (envName == "Current") {
            int index;
            envStream >> index;
            ui->venvBox->setCurrentIndex(index);
            continue;
        }
        ui->venvBox->addItem(envName);
    }
    envFile.close();
    return true;
}

bool InterfaceDialog::saveParameters(const QString &savePath) {
    QFile segParaFile(savePath + "/segmentation.yaml");
    if (segParaFile.exists()) segParaFile.remove();
    if (!segParaFile.open(QFile::ReadWrite)) return false;
    QTextStream segTextStream(&segParaFile);
    segTextStream << "Method: " << ui->segMethodList->currentItem()->text() << endl;
    for (QtProperty *prop: parameterLists[0]) {
        int valueType = dynamic_cast<QtVariantProperty *>(prop)->valueType();
        if (valueType == QVariant::Bool) {
            segTextStream << prop->propertyName() << ": " << (prop->valueText() == "True") << endl;
        } else segTextStream << prop->propertyName() << ": " << prop->valueText() << endl;
    }
    segParaFile.close();

    if (currentTab == 1) {
        QFile traParaFile(savePath + "/reconstruction.yaml");
        if (traParaFile.exists()) traParaFile.remove();
        if (!traParaFile.open(QFile::ReadWrite)) return false;
        QTextStream traTextStream(&traParaFile);
        traTextStream << "Method: " << ui->traMethodList->currentItem()->text() << endl;
        for (QtProperty *prop: parameterLists[1]) {
            int valueType = dynamic_cast<QtVariantProperty *>(prop)->valueType();
            if (valueType == QVariant::Bool) {
                traTextStream << prop->propertyName() << ": " << (prop->valueText() == "True") << endl;
            } else traTextStream << prop->propertyName() << ": " << prop->valueText() << endl;
        }
        traParaFile.close();
    } else if (currentTab == 2) {
        QFile detParaFile(savePath + "/detection.yaml");
        if (detParaFile.exists()) detParaFile.remove();
        if (!detParaFile.open(QFile::ReadWrite)) return false;
        QTextStream detTextStream(&detParaFile);
        detTextStream << "Method: " << ui->detMethodList->currentItem()->text() << endl;
        for (QtProperty *prop: parameterLists[2]) {
            int valueType = dynamic_cast<QtVariantProperty *>(prop)->valueType();
            if (valueType == QVariant::Bool) {
                detTextStream << prop->propertyName() << ": " << (prop->valueText() == "True") << endl;
            } else detTextStream << prop->propertyName() << ": " << prop->valueText() << endl;
        }
        detParaFile.close();
    }
    return true;
}

void InterfaceDialog::selectImageFile() {
    QString temp = QFileDialog::getOpenFileName(this, "Select Input Image", "", "*.tif");
    if (temp.isEmpty()) return;
    ui->imagePath->setText(temp);
}

void InterfaceDialog::selectImageDir() {
    QString temp = QFileDialog::getExistingDirectory(this, "Select Image Directory");
    if (temp.isEmpty()) return;
    ui->imagePath->setText(temp);
}

void InterfaceDialog::selectOutputPath() {
    QString temp = QFileDialog::getExistingDirectory(this, "Select Output Directory");
    if (temp.isEmpty()) return;
    ui->outputPath->setText(temp);
}

void InterfaceDialog::editPythonEnv() {
    QDialog editEnvsDialog(this);
    editEnvsDialog.setWindowTitle("Edit Python Virtual Environments");
    QGridLayout layout(&editEnvsDialog);
    QPushButton okButton("Ok", &editEnvsDialog);
    QPushButton cancelButton("Cancel", &editEnvsDialog);
    connect(&okButton, SIGNAL(clicked(bool)), &editEnvsDialog, SLOT(accept()));
    connect(&cancelButton, SIGNAL(clicked(bool)), &editEnvsDialog, SLOT(reject()));
    QTextEdit textEdit(&editEnvsDialog);
    layout.addWidget(&textEdit, 0, 0, 4, 2);
    layout.addWidget(&okButton, 4, 0, 1, 1);
    layout.addWidget(&cancelButton, 4, 1, 1, 1);
    for (int i = 0; i < ui->venvBox->count(); ++i) {
        textEdit.append(ui->venvBox->itemText(i));
    }
    if (editEnvsDialog.exec() != QDialog::Accepted) return;
    QStringList envs = textEdit.toPlainText().split('\n');
    ui->venvBox->clear();
    for (QString &env: envs) {
        if (env.isEmpty()) continue;
        ui->venvBox->addItem(env);
    }
}

void InterfaceDialog::addMethod(QListWidget *methodList) {
    if (methodList == nullptr) return;
    QString methodName = QInputDialog::getText(this, "Add Method", "Input Method Name:");
    if (methodName.isEmpty()) return;
    auto methodItem = new QListWidgetItem(methodName, methodList);
    methodList->setCurrentRow(methodList->count() - 1);
    readParameter();
}

void InterfaceDialog::delMethod(QListWidget *methodList) {
    if (methodList == nullptr) return;
    QMessageBox::StandardButton ans = QMessageBox::question(this, "Delete Method",
                                                            "Are you sure to delete this method?",
                                                            QMessageBox::Yes | QMessageBox::No);
    if (ans != QMessageBox::Yes) return;
    int index = methodList->currentRow();
    QListWidgetItem *item = methodList->takeItem(index);
    QFile parameterFile(
            "../../vaa3d_tools/released_plugins/v3d_plugins/DNeuroMAT/cache/" + item->text() + ".parameter");
    if (parameterFile.exists()) parameterFile.remove();
    delete item;
    methodIndex[currentTab] = -1;
    readParameter();
}

void InterfaceDialog::moveUpMethod(QListWidget *methodList) {
    if (methodList == nullptr) return;
    int index = methodList->currentRow();
    if (index == 0) return;
    QListWidgetItem *item = methodList->takeItem(index--);
    methodList->insertItem(index, item);
    methodList->setCurrentRow(index);
    methodIndex[currentTab] = index;
}

void InterfaceDialog::moveDownMethod(QListWidget *methodList) {
    if (methodList == nullptr) return;
    int index = methodList->currentRow();
    if (index == methodList->count() - 1) return;
    QListWidgetItem *item = methodList->takeItem(index++);
    methodList->insertItem(index, item);
    methodList->setCurrentRow(index);
    methodIndex[currentTab] = index;
}

void InterfaceDialog::editMethodName(QListWidgetItem *item) {
    QString newName = QInputDialog::getText(this, "Edit Method Name", "Input new name for the method",
                                            QLineEdit::Normal, item->text());
    if (newName.isEmpty()) return;
    item->setText(newName);
}

void InterfaceDialog::addParameter(QtTreePropertyBrowser *paraBrowser) {
    QtVariantPropertyManager *varManager = propertyManagers[currentTab];
    QSet<QString> *paraSet = &(parameterSets[currentTab]);
    QList<QtProperty *> *paraList = &(parameterLists[currentTab]);
    if (!varManager || !paraSet || !paraList) return;
    while (true) {
        QString paraName = QInputDialog::getText(this, "Parameter Name", "Input Parameter Name:");
        if (paraName.isEmpty()) break;
        if (paraSet->find(paraName) != paraSet->end()) {
            QMessageBox::information(this, "Information", "Existing Parameter.");
            break;
        }
        bool ok = false;
        QString paraType = QInputDialog::getItem(this, "Parameter Type", "Input Parameter Type:",
                                                 QStringList() << "int" << "double" << "bool" << "string", 0, false,
                                                 &ok);
        if (!ok) break;
        QtVariantProperty *prop = nullptr;
        if (paraType == "int") {
            ok = false;
            int defaultValue = QInputDialog::getInt(this, "Parameter Default Value", "Input Default Value:",
                                                    1, 1, 256, 1, &ok);
            if (!ok) break;
            prop = varManager->addProperty(QVariant::Int, paraName);
            prop->setValue(defaultValue);
        } else if (paraType == "double") {
            ok = false;
            double defaultValue = QInputDialog::getDouble(this, "Parameter Default Value", "Input default value:",
                                                          0.0, 0.0, 256.0, 3, &ok);
            if (!ok) break;
            prop = varManager->addProperty(QVariant::Double, paraName);
            prop->setAttribute("decimals", 3);
            prop->setAttribute("singleStep", 0.1);
            prop->setValue(defaultValue);
        } else if (paraType == "bool") {
            ok = false;
            QString item = QInputDialog::getItem(this, "Parameter Default Value", "Input default value:",
                                                 QStringList() << "true" << "false", 0, false, &ok);
            if (!ok) break;
            prop = varManager->addProperty(QVariant::Bool, paraName);
            prop->setValue(item == "true");
        } else if (paraType == "string") {
            ok = false;
            QString defaultValue = QInputDialog::getText(this, "Parameter Default Value", "Input default value:",
                                                         QLineEdit::Normal, QString(), &ok);
            if (!ok) break;
            prop = varManager->addProperty(QVariant::String, paraName);
            prop->setValue(defaultValue);
        }
        if (!prop) break;
        paraBrowser->addProperty(prop);
        paraSet->insert(paraName);
        paraList->push_back(prop);
    }
}

void InterfaceDialog::delParameter(QtTreePropertyBrowser *paraBrowser) {
    QMessageBox::StandardButton ans = QMessageBox::question(this, "Delete Parameter",
                                                            "Are you sure to delete this parameter?",
                                                            QMessageBox::Yes | QMessageBox::No);
    if (ans != QMessageBox::Yes) return;
    QtVariantPropertyManager *varManager = propertyManagers[currentTab];
    QSet<QString> *paraSet = &(parameterSets[currentTab]);
    QList<QtProperty *> *paraList = &(parameterLists[currentTab]);
    if (!varManager || !paraSet || !paraList) return;
    QtBrowserItem *item = paraBrowser->currentItem();
    if (!item) return;
    QtProperty *prop = item->property();
    if (!prop) return;
    paraBrowser->removeProperty(prop);
    paraSet->remove(prop->propertyName());
    paraList->removeOne(prop);
}

void InterfaceDialog::editParameterName(QtTreePropertyBrowser *paraBrowser) {
    QtBrowserItem *item = paraBrowser->currentItem();
    if (!item) return;
    QtProperty *prop = item->property();
    if (!prop) return;
    QString oldName = prop->propertyName();
    QString newName = QInputDialog::getText(this, "Edit Parameter Name", "Input new name for the parameter",
                                            QLineEdit::Normal, oldName);
    if (newName.isEmpty()) return;
    QSet<QString> *paraSet = &parameterSets[currentTab];
    if (paraSet->find(newName) != paraSet->end()) {
        QMessageBox::warning(this, "Warning", "Existing parameter.");
        return;
    }
    paraSet->remove(oldName);
    paraSet->insert(newName);
    prop->setPropertyName(newName);
}

void InterfaceDialog::saveParameter() {
    QListWidgetItem *item = methodLists[currentTab]->item(methodIndex[currentTab]);
    if (!item) return;
    QFile outFile(
            "../../vaa3d_tools/released_plugins/v3d_plugins/DNeuroMAT/cache/" + item->text() + ".parameter");
    if (outFile.exists()) outFile.remove();
    outFile.open(QFile::ReadWrite);
    QTextStream textStream(&outFile);
    for (QtProperty *prop: parameterLists[currentTab]) {
        int valueType = dynamic_cast<QtVariantProperty *>(prop)->valueType();
        textStream << prop->propertyName() << " " << valueType << " ";
        if (valueType == QVariant::Bool) textStream << (prop->valueText() == "True");
        else textStream << prop->valueText();
        textStream << " " << prop->isEnabled() << endl;
    }
    currentTab = ui->Tab->currentIndex();
    outFile.close();
}

void InterfaceDialog::readParameter() {
    saveParameter();
    propertyBrowsers[currentTab]->clear();
    propertyManagers[currentTab]->clear();
    parameterSets[currentTab].clear();
    parameterLists[currentTab].clear();
    methodIndex[currentTab] = methodLists[currentTab]->currentRow();
    QListWidgetItem *item = methodLists[currentTab]->item(methodIndex[currentTab]);
    if (!item) return;
    QFile infile(
            "../../vaa3d_tools/released_plugins/v3d_plugins/DNeuroMAT/cache/" + item->text() + ".parameter");
    if (!infile.open(QFile::ReadWrite)) return;
    QTextStream textStream(&infile);
    QString paraName, paraValue;
    int paraType = -1, paraEditable = 0;
    while (!textStream.atEnd()) {
        textStream >> paraName;
        if (paraName.isEmpty()) break;
        textStream >> paraType;
        textStream >> paraValue;
        textStream >> paraEditable;
        QtVariantProperty *prop = propertyManagers[currentTab]->addProperty(paraType, paraName);
        if (paraType == QVariant::Int || paraType == QVariant::Bool) {
            prop->setValue(paraValue.toInt());
        } else if (paraType == QVariant::Double) {
            prop->setAttribute("decimals", 3);
            prop->setAttribute("singleStep", 0.1);
            prop->setValue(paraValue.toDouble());
        } else if (paraType == QVariant::String) {
            prop->setValue(paraValue);
        } else {
            qDebug() << "Unsupported parameter type.";
            return;
        }
        prop->setEnabled(paraEditable);
        propertyBrowsers[currentTab]->addProperty(prop);
        parameterLists[currentTab].push_back(prop);
        parameterSets[currentTab].insert(prop->propertyName());
    }
    infile.close();
}

void InterfaceDialog::saveCache() {
    QFile methodFile("../../vaa3d_tools/released_plugins/v3d_plugins/DNeuroMAT/cache/methods.cache");
    if (methodFile.exists()) methodFile.remove();
    methodFile.open(QFile::ReadWrite);
    QTextStream methodStream(&methodFile);
    for (int i = 0; i < ui->Tab->count(); ++i) {
        for (int j = 0; j < methodLists[i]->count(); ++j) {
            methodStream << i << " " << methodLists[i]->item(j)->text() << endl;
        }
    }
    methodFile.close();
    QFile envFile("../../vaa3d_tools/released_plugins/v3d_plugins/DNeuroMAT/cache/envs.cache");
    if (envFile.exists()) envFile.remove();
    envFile.open(QFile::ReadWrite);
    QTextStream envStream(&envFile);
    for (int i = 0; i < ui->venvBox->count(); ++i) {
        envStream << ui->venvBox->itemText(i) << endl;
    }
    envStream << "Current " << ui->venvBox->currentIndex() << endl;
    envFile.close();
}

void InterfaceDialog::mousePressEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        dPos = event->globalPos() - this->pos();
        uiPos.setX(this->pos().x());
        uiPos.setY(this->pos().y());
        uiWidth = this->width();
        uiHeight = this->height();
    }
}

void InterfaceDialog::mouseMoveEvent(QMouseEvent *event) {
    if (event->buttons() & Qt::LeftButton) {
        if (dragFlag == 0) {
            this->move(event->globalPos() - dPos);
            return;
        }
        int width = uiWidth + uiPos.x() - event->globalX();
        int height = uiHeight + uiPos.y() - event->globalY();
        if (dragFlag == dragLeft) {
            this->resize(width, this->height());
            if (width < this->minimumWidth()) return;
            this->move(event->globalX(), this->y());
        } else if (dragFlag == dragRight) {
            this->resize(event->globalX() - uiPos.x(), this->height());
        } else if (dragFlag == dragUp) {
            this->resize(this->width(), height);
            if (height < this->minimumHeight()) return;
            this->move(this->x(), event->globalY());
        } else if (dragFlag == dragDown) {
            this->resize(this->width(), event->globalY() - uiPos.y());
        } else if (dragFlag == dragLeftUp) {
            this->resize(width, height);
            this->move((width > this->minimumWidth())? event->globalX(): this->x(),
                       (height > this->minimumHeight())? event->globalY(): this->y());
        } else if (dragFlag == dragRightUp) {
            this->resize(event->globalX() - uiPos.x(), height);
            if (height < this->minimumHeight()) return;
            this->move(this->x(), event->globalY());
        } else if (dragFlag == dragLeftDown) {
            this->resize(width, event->globalY() - uiPos.y());
            if (width < this->minimumWidth()) return;
            this->move(event->globalX(), this->y());
        } else if (dragFlag == dragRightDown) {
            this->resize(event->globalX() - uiPos.x(), event->globalY() - uiPos.y());
        }
    } else {
        QPoint pos = event->pos();
        dragFlag = 0;
        dragFlag |= (this->height() - pos.y()) <= marginSize;
        dragFlag <<= 1;
        dragFlag |= (pos.y() <= marginSize);
        dragFlag <<= 1;
        dragFlag |= (this->width() - pos.x()) <= marginSize;
        dragFlag <<= 1;
        dragFlag |= (pos.x() <= marginSize);
        if (dragFlag == 0) {
            this->setCursor(QCursor(Qt::ArrowCursor));
        } else if (dragFlag == dragLeft) {
            this->setCursor(QCursor(Qt::SizeHorCursor));
        } else if (dragFlag == dragRight) {
            this->setCursor(QCursor(Qt::SizeHorCursor));
        } else if (dragFlag == dragUp) {
            this->setCursor(QCursor(Qt::SizeVerCursor));
        } else if (dragFlag == dragDown) {
            this->setCursor(QCursor(Qt::SizeVerCursor));
        } else if (dragFlag == dragLeftUp) {
            this->setCursor(QCursor(Qt::SizeFDiagCursor));
        } else if (dragFlag == dragRightUp) {
            this->setCursor(QCursor(Qt::SizeBDiagCursor));
        } else if (dragFlag == dragLeftDown) {
            this->setCursor(QCursor(Qt::SizeBDiagCursor));
        } else if (dragFlag == dragRightDown) {
            this->setCursor(QCursor(Qt::SizeFDiagCursor));
        }
    }
}

void InterfaceDialog::mouseReleaseEvent(QMouseEvent *event) {
    if (dragFlag == 0) return;
    QPoint pos = event->pos();
    dragFlag = 0;
    dragFlag |= (this->height() - pos.y()) <= marginSize;
    dragFlag <<= 1;
    dragFlag |= (pos.y() <= marginSize);
    dragFlag <<= 1;
    dragFlag |= (this->width() - pos.x()) <= marginSize;
    dragFlag <<= 1;
    dragFlag |= (pos.x() <= marginSize);
    if (dragFlag == 0) {
        this->setCursor(QCursor(Qt::ArrowCursor));
    } else if (dragFlag == dragLeft) {
        this->setCursor(QCursor(Qt::SizeHorCursor));
    } else if (dragFlag == dragRight) {
        this->setCursor(QCursor(Qt::SizeHorCursor));
    } else if (dragFlag == dragUp) {
        this->setCursor(QCursor(Qt::SizeVerCursor));
    } else if (dragFlag == dragDown) {
        this->setCursor(QCursor(Qt::SizeVerCursor));
    } else if (dragFlag == dragLeftUp) {
        this->setCursor(QCursor(Qt::SizeFDiagCursor));
    } else if (dragFlag == dragRightUp) {
        this->setCursor(QCursor(Qt::SizeBDiagCursor));
    } else if (dragFlag == dragLeftDown) {
        this->setCursor(QCursor(Qt::SizeBDiagCursor));
    } else if (dragFlag == dragRightDown) {
        this->setCursor(QCursor(Qt::SizeFDiagCursor));
    }
}