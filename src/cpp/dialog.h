#ifndef __DIALOG_H__
#define __DIALOG_H__

#include <QtGui>
#include <v3d_interface.h>
#include <QWidget>
#include <iostream>
#include <QApplication>
#include <QDateTime>
#include <qtpropertybrowser.h>
#include <qtpropertymanager.h>
#include <qtvariantproperty.h>
#include <qttreepropertybrowser.h>
#include <QSet>
#include "surf_objs.h"
#include <unordered_set>
#include "ui_dialog.h"

using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui
{
    class Dialog;
}
QT_END_NAMESPACE

class InterfaceDialog: public QDialog
{
    Q_OBJECT
public:
    explicit InterfaceDialog(V3DPluginCallback2& callback);
    ~InterfaceDialog();
    bool readCache();
    bool saveParameters(const QString& savePath);
    int getFunctionIndex() {return ui->Tab->currentIndex();}
    QString getSegMethodName() {return ui->segMethodList->currentItem()->text();}
    QString getTraMethodName() {return ui->traMethodList->currentItem()->text();}
    QString getDetMethodName() {return ui->detMethodList->currentItem()->text();}
    QString getImagePath() {return ui->imagePath->text();}
    QString getOutputPath() {return ui->outputPath->text();}
    QString getPythonEnv() {return ui->venvBox->currentText();}
    bool isTracingWithSegmentation() {return ui->traWithSegButton->isChecked();}
    bool isDetectionWithSegmentation() {return ui->detWithSegButton->isChecked();}
    bool isEnvsEmpty() {return ui->venvBox->count() == 0;}

private slots:
    void selectImageFile();
    void selectImageDir();
    void selectOutputPath();
    void editPythonEnv();
    void addMethod(QListWidget* methodList);
    void delMethod(QListWidget* methodList);
    void moveUpMethod(QListWidget* methodList);
    void moveDownMethod(QListWidget* methodList);
    void editMethodName(QListWidgetItem* item);
    void addParameter(QtTreePropertyBrowser* paraBrowser);
    void delParameter(QtTreePropertyBrowser* paraBrowser);
    void editParameterName(QtTreePropertyBrowser* paraBrowser);
    void saveParameter();
    void readParameter();
    void saveCache();

protected:
    void mousePressEvent (QMouseEvent * event ) override;
    void mouseMoveEvent (QMouseEvent * event ) override;
    void mouseReleaseEvent (QMouseEvent * event ) override;

private:
    Ui::Dialog* ui;
    QtVariantEditorFactory* varFactory;
    QtVariantPropertyManager* propertyManagers[3];
    QtTreePropertyBrowser* propertyBrowsers[3];
    QListWidget* methodLists[3];
    QSet<QString> parameterSets[3];
    QList<QtProperty*> parameterLists[3];
    int methodIndex[3];
    int currentTab;
    QPoint dPos, uiPos;
    int uiWidth, uiHeight;
    int marginSize;
    int dragFlag;
    enum {
        dragLeft = 0x01,
        dragRight = 0x02,
        dragUp = 0x04,
        dragDown = 0x08,
        dragLeftUp = dragLeft | dragUp,
        dragRightUp = dragRight | dragUp,
        dragLeftDown = dragLeft | dragDown,
        dragRightDown = dragRight | dragDown
    };
};

#endif //__DIALOG_H__

