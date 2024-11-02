/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListWidget>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTabWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include "method_button.h"
#include "parameter_button.h"
#include "qttreepropertybrowser.h"

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QVBoxLayout *verticalLayout_5;
    QFrame *frame;
    QVBoxLayout *verticalLayout_2;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_4;
    QLabel *titleLabel;
    QSpacerItem *horizontalSpacer;
    QWidget *widget_8;
    QVBoxLayout *verticalLayout_3;
    QGroupBox *groupBox_4;
    QVBoxLayout *verticalLayout_12;
    QPushButton *closeButton;
    QGroupBox *funcGroupBox;
    QVBoxLayout *verticalLayout;
    QTabWidget *Tab;
    QWidget *segmentTab;
    QHBoxLayout *horizontalLayout_17;
    QGroupBox *segMethodBox;
    QVBoxLayout *verticalLayout_4;
    QListWidget *segMethodList;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_12;
    MethodButton *segAddButton;
    MethodButton *segDelButton;
    QSpacerItem *horizontalSpacer_5;
    MethodButton *segUpButton;
    MethodButton *segDownButton;
    QSpacerItem *horizontalSpacer_13;
    QGroupBox *segParaBox;
    QVBoxLayout *verticalLayout_10;
    QtTreePropertyBrowser *segParaBrowser;
    QWidget *widget_5;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_16;
    ParameterButton *segAddParaButton;
    ParameterButton *segDelParaButton;
    QSpacerItem *horizontalSpacer_7;
    ParameterButton *segEditNameButton;
    QSpacerItem *horizontalSpacer_20;
    QWidget *tracingTab;
    QHBoxLayout *horizontalLayout_6;
    QGroupBox *traMethodBox;
    QVBoxLayout *verticalLayout_9;
    QListWidget *traMethodList;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_10;
    MethodButton *traAddButton;
    MethodButton *traDelButton;
    QSpacerItem *horizontalSpacer_6;
    MethodButton *traUpButton;
    MethodButton *traDownButton;
    QSpacerItem *horizontalSpacer_11;
    QGroupBox *traParaBox;
    QVBoxLayout *verticalLayout_8;
    QtTreePropertyBrowser *traParaBrowser;
    QWidget *widget_6;
    QHBoxLayout *horizontalLayout_7;
    QSpacerItem *horizontalSpacer_4;
    ParameterButton *traAddParaButton;
    ParameterButton *traDelParaButton;
    QSpacerItem *horizontalSpacer_17;
    QRadioButton *traWithSegButton;
    ParameterButton *traEditNameButton;
    QSpacerItem *horizontalSpacer_3;
    QWidget *detectionTab;
    QHBoxLayout *horizontalLayout_11;
    QGroupBox *detMethodBox;
    QVBoxLayout *verticalLayout_6;
    QListWidget *detMethodList;
    QWidget *widget_4;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_14;
    MethodButton *detAddButton;
    MethodButton *detDelButton;
    QSpacerItem *horizontalSpacer_9;
    MethodButton *detUpButton;
    MethodButton *detDownButton;
    QSpacerItem *horizontalSpacer_15;
    QGroupBox *detParaBox;
    QVBoxLayout *verticalLayout_11;
    QtTreePropertyBrowser *detParaBrowser;
    QWidget *widget_7;
    QHBoxLayout *horizontalLayout_8;
    QSpacerItem *horizontalSpacer_8;
    ParameterButton *detAddParaButton;
    ParameterButton *detDelParaButton;
    QSpacerItem *horizontalSpacer_18;
    QRadioButton *detWithSegButton;
    ParameterButton *detEditNameButton;
    QSpacerItem *horizontalSpacer_19;
    QGroupBox *settingGroupBox;
    QGridLayout *gridLayout_2;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *selectOutputButton;
    QLabel *label_4;
    QLabel *label;
    QPushButton *selectImageButton;
    QLabel *label_3;
    QComboBox *venvBox;
    QLineEdit *imagePath;
    QPushButton *editEnvButton;
    QLineEdit *outputPath;
    QPushButton *cancel;
    QPushButton *ok;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->resize(1144, 1062);
        QFont font;
        font.setFamily(QString::fromUtf8("Times New Roman"));
        Dialog->setFont(font);
        Dialog->setMouseTracking(true);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/src/pics/v3dIcon128.png"), QSize(), QIcon::Normal, QIcon::Off);
        Dialog->setWindowIcon(icon);
        Dialog->setStyleSheet(QString::fromUtf8(""));
        verticalLayout_5 = new QVBoxLayout(Dialog);
        verticalLayout_5->setSpacing(12);
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        frame = new QFrame(Dialog);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setMouseTracking(true);
        frame->setStyleSheet(QString::fromUtf8("QFrame#frame{\n"
"	background-color: rgb(255, 255, 255);\n"
"	border-radius: 20px;\n"
"	border: 2px groove gray;\n"
"}"));
        frame->setFrameShape(QFrame::Box);
        frame->setFrameShadow(QFrame::Plain);
        verticalLayout_2 = new QVBoxLayout(frame);
        verticalLayout_2->setContentsMargins(12, 12, 12, 12);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        widget = new QWidget(frame);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout_4 = new QHBoxLayout(widget);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(5, 0, 0, 0);
        titleLabel = new QLabel(widget);
        titleLabel->setObjectName(QString::fromUtf8("titleLabel"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Times New Roman"));
        font1.setPointSize(12);
        font1.setBold(true);
        font1.setItalic(true);
        font1.setUnderline(false);
        font1.setWeight(75);
        titleLabel->setFont(font1);

        horizontalLayout_4->addWidget(titleLabel);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);

        widget_8 = new QWidget(widget);
        widget_8->setObjectName(QString::fromUtf8("widget_8"));
        verticalLayout_3 = new QVBoxLayout(widget_8);
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        groupBox_4 = new QGroupBox(widget_8);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setStyleSheet(QString::fromUtf8("QGroupBox{\n"
"	border: none;\n"
"}"));
        groupBox_4->setFlat(false);
        groupBox_4->setCheckable(false);
        verticalLayout_12 = new QVBoxLayout(groupBox_4);
        verticalLayout_12->setSpacing(12);
        verticalLayout_12->setContentsMargins(0, 0, 0, 0);
        verticalLayout_12->setObjectName(QString::fromUtf8("verticalLayout_12"));
        closeButton = new QPushButton(groupBox_4);
        closeButton->setObjectName(QString::fromUtf8("closeButton"));
        closeButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	height: 40px;\n"
"	width: 60px;\n"
"	border: none;\n"
"	background-color: rgb(255, 255, 255);\n"
"	image: url(:src/pics/close.png);\n"
"}\n"
"\n"
"QPushButton::hover{\n"
"	background: rgba(217, 0, 0, 200);\n"
"	image: url(:src/pics/close-white.png);\n"
"}\n"
"\n"
"QPushButton::pressed{\n"
"	background: rgba(217, 0, 0, 150);\n"
"}"));
        closeButton->setFlat(false);

        verticalLayout_12->addWidget(closeButton);


        verticalLayout_3->addWidget(groupBox_4);


        horizontalLayout_4->addWidget(widget_8);


        verticalLayout_2->addWidget(widget);

        funcGroupBox = new QGroupBox(frame);
        funcGroupBox->setObjectName(QString::fromUtf8("funcGroupBox"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Times New Roman"));
        font2.setPointSize(10);
        font2.setBold(true);
        font2.setItalic(true);
        font2.setWeight(75);
        funcGroupBox->setFont(font2);
        funcGroupBox->setStyleSheet(QString::fromUtf8("QGroupBox#funcGroupBox{\n"
"    border: none;\n"
"    margin-top: 10ex;\n"
"}\n"
"\n"
"QGroupBox#funcGroupBox::title{\n"
"    subcontrol-origin: margin;\n"
"    subcontrol-position: top left;\n"
"	left: 10px;\n"
"}\n"
"\n"
""));
        verticalLayout = new QVBoxLayout(funcGroupBox);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        Tab = new QTabWidget(funcGroupBox);
        Tab->setObjectName(QString::fromUtf8("Tab"));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Times New Roman"));
        font3.setPointSize(10);
        Tab->setFont(font3);
        Tab->setCursor(QCursor(Qt::ArrowCursor));
        Tab->setTabPosition(QTabWidget::North);
        Tab->setTabShape(QTabWidget::Rounded);
        segmentTab = new QWidget();
        segmentTab->setObjectName(QString::fromUtf8("segmentTab"));
        horizontalLayout_17 = new QHBoxLayout(segmentTab);
        horizontalLayout_17->setObjectName(QString::fromUtf8("horizontalLayout_17"));
        segMethodBox = new QGroupBox(segmentTab);
        segMethodBox->setObjectName(QString::fromUtf8("segMethodBox"));
        QFont font4;
        font4.setFamily(QString::fromUtf8("Times New Roman"));
        font4.setPointSize(10);
        font4.setItalic(true);
        segMethodBox->setFont(font4);
        segMethodBox->setStyleSheet(QString::fromUtf8("QGroupBox#segMethodBox{\n"
"    border: 1px groove gray;\n"
"    margin-top: 5ex;\n"
"}\n"
"\n"
"QGroupBox#segMethodBox::title{\n"
"    subcontrol-origin: margin;\n"
"    subcontrol-position: top left;\n"
"	left: 10px;\n"
"}\n"
""));
        verticalLayout_4 = new QVBoxLayout(segMethodBox);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        segMethodList = new QListWidget(segMethodBox);
        segMethodList->setObjectName(QString::fromUtf8("segMethodList"));

        verticalLayout_4->addWidget(segMethodList);

        widget_2 = new QWidget(segMethodBox);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        horizontalLayout = new QHBoxLayout(widget_2);
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer_12 = new QSpacerItem(40, 60, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_12);

        segAddButton = new MethodButton(widget_2);
        segAddButton->setObjectName(QString::fromUtf8("segAddButton"));
        segAddButton->setCursor(QCursor(Qt::PointingHandCursor));
        segAddButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	width: 60px;\n"
"	height: 60px;\n"
"	border-radius: 10px;\n"
"	border: 2px groove gray;\n"
"	border-style: outset;\n"
"}\n"
"QPushButton:hover{\n"
"	background-color:rgba(0, 170, 255, 128);\n"
"}\n"
"QPushButton::pressed{\n"
"	background-color: rgb(200, 200, 200);\n"
"	border-style: inset;\n"
"}"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/src/pics/plus.png"), QSize(), QIcon::Normal, QIcon::Off);
        segAddButton->setIcon(icon1);
        segAddButton->setIconSize(QSize(128, 128));

        horizontalLayout->addWidget(segAddButton);

        segDelButton = new MethodButton(widget_2);
        segDelButton->setObjectName(QString::fromUtf8("segDelButton"));
        segDelButton->setCursor(QCursor(Qt::PointingHandCursor));
        segDelButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	width: 60px;\n"
"	height: 60px;\n"
"	border-radius: 10px;\n"
"	border: 2px groove gray;\n"
"	border-style: outset;\n"
"}\n"
"QPushButton:hover{\n"
"	background-color:rgba(0, 170, 255, 128);\n"
"}\n"
"QPushButton::pressed{\n"
"	background-color: rgb(200, 200, 200);\n"
"	border-style: inset;\n"
"}"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/src/pics/minus.png"), QSize(), QIcon::Normal, QIcon::Off);
        segDelButton->setIcon(icon2);

        horizontalLayout->addWidget(segDelButton);

        horizontalSpacer_5 = new QSpacerItem(40, 60, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_5);

        segUpButton = new MethodButton(widget_2);
        segUpButton->setObjectName(QString::fromUtf8("segUpButton"));
        segUpButton->setCursor(QCursor(Qt::PointingHandCursor));
        segUpButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	width: 60px;\n"
"	height: 60px;\n"
"	border-radius: 10px;\n"
"	border: 2px groove gray;\n"
"	border-style: outset;\n"
"}\n"
"QPushButton:hover{\n"
"	background-color:rgba(0, 170, 255, 128);\n"
"}\n"
"QPushButton::pressed{\n"
"	background-color: rgb(200, 200, 200);\n"
"	border-style: inset;\n"
"}"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/src/pics/up.png"), QSize(), QIcon::Normal, QIcon::Off);
        segUpButton->setIcon(icon3);

        horizontalLayout->addWidget(segUpButton);

        segDownButton = new MethodButton(widget_2);
        segDownButton->setObjectName(QString::fromUtf8("segDownButton"));
        segDownButton->setCursor(QCursor(Qt::PointingHandCursor));
        segDownButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	width: 60px;\n"
"	height: 60px;\n"
"	border-radius: 10px;\n"
"	border: 2px groove gray;\n"
"	border-style: outset;\n"
"}\n"
"QPushButton:hover{\n"
"	background-color:rgba(0, 170, 255, 128);\n"
"}\n"
"QPushButton::pressed{\n"
"	background-color: rgb(200, 200, 200);\n"
"	border-style: inset;\n"
"}"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/src/pics/down.png"), QSize(), QIcon::Normal, QIcon::Off);
        segDownButton->setIcon(icon4);

        horizontalLayout->addWidget(segDownButton);

        horizontalSpacer_13 = new QSpacerItem(40, 60, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_13);


        verticalLayout_4->addWidget(widget_2);


        horizontalLayout_17->addWidget(segMethodBox);

        segParaBox = new QGroupBox(segmentTab);
        segParaBox->setObjectName(QString::fromUtf8("segParaBox"));
        segParaBox->setFont(font4);
        segParaBox->setStyleSheet(QString::fromUtf8("QGroupBox#segParaBox{\n"
"    border: 1px groove gray;\n"
"    margin-top: 5ex;\n"
"}\n"
"\n"
"QGroupBox#segParaBox::title{\n"
"    subcontrol-origin: margin;\n"
"    subcontrol-position: top left;\n"
"	left: 10px;\n"
"}"));
        verticalLayout_10 = new QVBoxLayout(segParaBox);
        verticalLayout_10->setObjectName(QString::fromUtf8("verticalLayout_10"));
        segParaBrowser = new QtTreePropertyBrowser(segParaBox);
        segParaBrowser->setObjectName(QString::fromUtf8("segParaBrowser"));

        verticalLayout_10->addWidget(segParaBrowser);

        widget_5 = new QWidget(segParaBox);
        widget_5->setObjectName(QString::fromUtf8("widget_5"));
        horizontalLayout_5 = new QHBoxLayout(widget_5);
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalSpacer_16 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_16);

        segAddParaButton = new ParameterButton(widget_5);
        segAddParaButton->setObjectName(QString::fromUtf8("segAddParaButton"));
        segAddParaButton->setCursor(QCursor(Qt::PointingHandCursor));
        segAddParaButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	width: 60px;\n"
"	height: 60px;\n"
"	border-radius: 10px;\n"
"	border: 2px groove gray;\n"
"	border-style: outset;\n"
"}\n"
"QPushButton:hover{\n"
"	background-color:rgba(0, 170, 255, 128);\n"
"}\n"
"QPushButton::pressed{\n"
"	background-color: rgb(200, 200, 200);\n"
"	border-style: inset;\n"
"}"));
        segAddParaButton->setIcon(icon1);
        segAddParaButton->setIconSize(QSize(128, 128));

        horizontalLayout_5->addWidget(segAddParaButton);

        segDelParaButton = new ParameterButton(widget_5);
        segDelParaButton->setObjectName(QString::fromUtf8("segDelParaButton"));
        segDelParaButton->setCursor(QCursor(Qt::PointingHandCursor));
        segDelParaButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	width: 60px;\n"
"	height: 60px;\n"
"	border-radius: 10px;\n"
"	border: 2px groove gray;\n"
"	border-style: outset;\n"
"}\n"
"QPushButton:hover{\n"
"	background-color:rgba(0, 170, 255, 128);\n"
"}\n"
"QPushButton::pressed{\n"
"	background-color: rgb(200, 200, 200);\n"
"	border-style: inset;\n"
"}"));
        segDelParaButton->setIcon(icon2);

        horizontalLayout_5->addWidget(segDelParaButton);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_7);

        segEditNameButton = new ParameterButton(widget_5);
        segEditNameButton->setObjectName(QString::fromUtf8("segEditNameButton"));
        segEditNameButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	width: 60px;\n"
"	height: 60px;\n"
"	border-radius: 10px;\n"
"	border: 2px groove gray;\n"
"	border-style: outset;\n"
"}\n"
"QPushButton:hover{\n"
"	background-color:rgba(0, 170, 255, 128);\n"
"}\n"
"QPushButton::pressed{\n"
"	background-color: rgb(200, 200, 200);\n"
"	border-style: inset;\n"
"}"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/src/pics/edit.png"), QSize(), QIcon::Normal, QIcon::Off);
        segEditNameButton->setIcon(icon5);

        horizontalLayout_5->addWidget(segEditNameButton);

        horizontalSpacer_20 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_20);


        verticalLayout_10->addWidget(widget_5);


        horizontalLayout_17->addWidget(segParaBox);

        Tab->addTab(segmentTab, QString());
        tracingTab = new QWidget();
        tracingTab->setObjectName(QString::fromUtf8("tracingTab"));
        horizontalLayout_6 = new QHBoxLayout(tracingTab);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        traMethodBox = new QGroupBox(tracingTab);
        traMethodBox->setObjectName(QString::fromUtf8("traMethodBox"));
        traMethodBox->setFont(font4);
        traMethodBox->setStyleSheet(QString::fromUtf8("QGroupBox#traMethodBox{\n"
"    border: 1px groove gray;\n"
"    margin-top: 5ex;\n"
"}\n"
"\n"
"QGroupBox#traMethodBox::title{\n"
"    subcontrol-origin: margin;\n"
"    subcontrol-position: top left;\n"
"	left: 10px;\n"
"}"));
        verticalLayout_9 = new QVBoxLayout(traMethodBox);
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        traMethodList = new QListWidget(traMethodBox);
        traMethodList->setObjectName(QString::fromUtf8("traMethodList"));

        verticalLayout_9->addWidget(traMethodList);

        widget_3 = new QWidget(traMethodBox);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        horizontalLayout_2 = new QHBoxLayout(widget_3);
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_10);

        traAddButton = new MethodButton(widget_3);
        traAddButton->setObjectName(QString::fromUtf8("traAddButton"));
        traAddButton->setCursor(QCursor(Qt::PointingHandCursor));
        traAddButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	width: 60px;\n"
"	height: 60px;\n"
"	border-radius: 10px;\n"
"	border: 2px groove gray;\n"
"	border-style: outset;\n"
"}\n"
"QPushButton:hover{\n"
"	background-color:rgba(0, 170, 255, 128);\n"
"}\n"
"QPushButton::pressed{\n"
"	background-color: rgb(200, 200, 200);\n"
"	border-style: inset;\n"
"}"));
        traAddButton->setIcon(icon1);
        traAddButton->setIconSize(QSize(128, 128));

        horizontalLayout_2->addWidget(traAddButton);

        traDelButton = new MethodButton(widget_3);
        traDelButton->setObjectName(QString::fromUtf8("traDelButton"));
        traDelButton->setCursor(QCursor(Qt::PointingHandCursor));
        traDelButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	width: 60px;\n"
"	height: 60px;\n"
"	border-radius: 10px;\n"
"	border: 2px groove gray;\n"
"	border-style: outset;\n"
"}\n"
"QPushButton:hover{\n"
"	background-color:rgba(0, 170, 255, 128);\n"
"}\n"
"QPushButton::pressed{\n"
"	background-color: rgb(200, 200, 200);\n"
"	border-style: inset;\n"
"}"));
        traDelButton->setIcon(icon2);

        horizontalLayout_2->addWidget(traDelButton);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_6);

        traUpButton = new MethodButton(widget_3);
        traUpButton->setObjectName(QString::fromUtf8("traUpButton"));
        traUpButton->setCursor(QCursor(Qt::PointingHandCursor));
        traUpButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	width: 60px;\n"
"	height: 60px;\n"
"	border-radius: 10px;\n"
"	border: 2px groove gray;\n"
"	border-style: outset;\n"
"}\n"
"QPushButton:hover{\n"
"	background-color:rgba(0, 170, 255, 128);\n"
"}\n"
"QPushButton::pressed{\n"
"	background-color: rgb(200, 200, 200);\n"
"	border-style: inset;\n"
"}"));
        traUpButton->setIcon(icon3);

        horizontalLayout_2->addWidget(traUpButton);

        traDownButton = new MethodButton(widget_3);
        traDownButton->setObjectName(QString::fromUtf8("traDownButton"));
        traDownButton->setCursor(QCursor(Qt::PointingHandCursor));
        traDownButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	width: 60px;\n"
"	height: 60px;\n"
"	border-radius: 10px;\n"
"	border: 2px groove gray;\n"
"	border-style: outset;\n"
"}\n"
"QPushButton:hover{\n"
"	background-color:rgba(0, 170, 255, 128);\n"
"}\n"
"QPushButton::pressed{\n"
"	background-color: rgb(200, 200, 200);\n"
"	border-style: inset;\n"
"}"));
        traDownButton->setIcon(icon4);

        horizontalLayout_2->addWidget(traDownButton);

        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_11);


        verticalLayout_9->addWidget(widget_3);


        horizontalLayout_6->addWidget(traMethodBox);

        traParaBox = new QGroupBox(tracingTab);
        traParaBox->setObjectName(QString::fromUtf8("traParaBox"));
        traParaBox->setFont(font4);
        traParaBox->setStyleSheet(QString::fromUtf8("QGroupBox#traParaBox{\n"
"    border: 1px groove gray;\n"
"    margin-top: 5ex;\n"
"}\n"
"\n"
"QGroupBox#traParaBox::title{\n"
"    subcontrol-origin: margin;\n"
"    subcontrol-position: top left;\n"
"	left: 10px;\n"
"}"));
        verticalLayout_8 = new QVBoxLayout(traParaBox);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        traParaBrowser = new QtTreePropertyBrowser(traParaBox);
        traParaBrowser->setObjectName(QString::fromUtf8("traParaBrowser"));
        QFont font5;
        font5.setFamily(QString::fromUtf8("Microsoft YaHei UI"));
        traParaBrowser->setFont(font5);

        verticalLayout_8->addWidget(traParaBrowser);

        widget_6 = new QWidget(traParaBox);
        widget_6->setObjectName(QString::fromUtf8("widget_6"));
        horizontalLayout_7 = new QHBoxLayout(widget_6);
        horizontalLayout_7->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_4);

        traAddParaButton = new ParameterButton(widget_6);
        traAddParaButton->setObjectName(QString::fromUtf8("traAddParaButton"));
        traAddParaButton->setCursor(QCursor(Qt::PointingHandCursor));
        traAddParaButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	width: 60px;\n"
"	height: 60px;\n"
"	border-radius: 10px;\n"
"	border: 2px groove gray;\n"
"	border-style: outset;\n"
"}\n"
"QPushButton:hover{\n"
"	background-color:rgba(0, 170, 255, 128);\n"
"}\n"
"QPushButton::pressed{\n"
"	background-color: rgb(200, 200, 200);\n"
"	border-style: inset;\n"
"}"));
        traAddParaButton->setIcon(icon1);
        traAddParaButton->setIconSize(QSize(128, 128));

        horizontalLayout_7->addWidget(traAddParaButton);

        traDelParaButton = new ParameterButton(widget_6);
        traDelParaButton->setObjectName(QString::fromUtf8("traDelParaButton"));
        traDelParaButton->setCursor(QCursor(Qt::PointingHandCursor));
        traDelParaButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	width: 60px;\n"
"	height: 60px;\n"
"	border-radius: 10px;\n"
"	border: 2px groove gray;\n"
"	border-style: outset;\n"
"}\n"
"QPushButton:hover{\n"
"	background-color:rgba(0, 170, 255, 128);\n"
"}\n"
"QPushButton::pressed{\n"
"	background-color: rgb(200, 200, 200);\n"
"	border-style: inset;\n"
"}"));
        traDelParaButton->setIcon(icon2);

        horizontalLayout_7->addWidget(traDelParaButton);

        horizontalSpacer_17 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_17);

        traWithSegButton = new QRadioButton(widget_6);
        traWithSegButton->setObjectName(QString::fromUtf8("traWithSegButton"));
        traWithSegButton->setFont(font3);
        traWithSegButton->setCursor(QCursor(Qt::PointingHandCursor));
        traWithSegButton->setStyleSheet(QString::fromUtf8("QRadioButton#traWithSegButton::indicator::checked{\n"
"	width: 64px;\n"
"	height: 64px;\n"
"	image: url(:/src/pics/greenStone.png);\n"
"}\n"
"\n"
"QRadioButton#traWithSegButton::indicator::unchecked{\n"
"	width: 64px;\n"
"	height: 64px;\n"
"	image: url(:/src/pics/grayStone.png);\n"
"}"));

        horizontalLayout_7->addWidget(traWithSegButton);

        traEditNameButton = new ParameterButton(widget_6);
        traEditNameButton->setObjectName(QString::fromUtf8("traEditNameButton"));
        traEditNameButton->setCursor(QCursor(Qt::PointingHandCursor));
        traEditNameButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	width: 60px;\n"
"	height: 60px;\n"
"	border-radius: 10px;\n"
"	border: 2px groove gray;\n"
"	border-style: outset;\n"
"}\n"
"QPushButton:hover{\n"
"	background-color:rgba(0, 170, 255, 128);\n"
"}\n"
"QPushButton::pressed{\n"
"	background-color: rgb(200, 200, 200);\n"
"	border-style: inset;\n"
"}"));
        traEditNameButton->setIcon(icon5);

        horizontalLayout_7->addWidget(traEditNameButton);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_3);


        verticalLayout_8->addWidget(widget_6);


        horizontalLayout_6->addWidget(traParaBox);

        Tab->addTab(tracingTab, QString());
        detectionTab = new QWidget();
        detectionTab->setObjectName(QString::fromUtf8("detectionTab"));
        horizontalLayout_11 = new QHBoxLayout(detectionTab);
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        detMethodBox = new QGroupBox(detectionTab);
        detMethodBox->setObjectName(QString::fromUtf8("detMethodBox"));
        detMethodBox->setFont(font4);
        detMethodBox->setStyleSheet(QString::fromUtf8("QGroupBox#detMethodBox{\n"
"    border: 1px groove gray;\n"
"    margin-top: 5ex;\n"
"}\n"
"\n"
"QGroupBox#detMethodBox::title{\n"
"    subcontrol-origin: margin;\n"
"    subcontrol-position: top left;\n"
"	left: 10px;\n"
"}"));
        verticalLayout_6 = new QVBoxLayout(detMethodBox);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        detMethodList = new QListWidget(detMethodBox);
        detMethodList->setObjectName(QString::fromUtf8("detMethodList"));
        detMethodList->setFont(font5);

        verticalLayout_6->addWidget(detMethodList);

        widget_4 = new QWidget(detMethodBox);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        horizontalLayout_3 = new QHBoxLayout(widget_4);
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer_14 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_14);

        detAddButton = new MethodButton(widget_4);
        detAddButton->setObjectName(QString::fromUtf8("detAddButton"));
        detAddButton->setCursor(QCursor(Qt::PointingHandCursor));
        detAddButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	width: 60px;\n"
"	height: 60px;\n"
"	border-radius: 10px;\n"
"	border: 2px groove gray;\n"
"	border-style: outset;\n"
"}\n"
"QPushButton:hover{\n"
"	background-color:rgba(0, 170, 255, 128);\n"
"}\n"
"QPushButton::pressed{\n"
"	background-color: rgb(200, 200, 200);\n"
"	border-style: inset;\n"
"}"));
        detAddButton->setIcon(icon1);
        detAddButton->setIconSize(QSize(128, 128));

        horizontalLayout_3->addWidget(detAddButton);

        detDelButton = new MethodButton(widget_4);
        detDelButton->setObjectName(QString::fromUtf8("detDelButton"));
        detDelButton->setCursor(QCursor(Qt::PointingHandCursor));
        detDelButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	width: 60px;\n"
"	height: 60px;\n"
"	border-radius: 10px;\n"
"	border: 2px groove gray;\n"
"	border-style: outset;\n"
"}\n"
"QPushButton:hover{\n"
"	background-color:rgba(0, 170, 255, 128);\n"
"}\n"
"QPushButton::pressed{\n"
"	background-color: rgb(200, 200, 200);\n"
"	border-style: inset;\n"
"}"));
        detDelButton->setIcon(icon2);

        horizontalLayout_3->addWidget(detDelButton);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_9);

        detUpButton = new MethodButton(widget_4);
        detUpButton->setObjectName(QString::fromUtf8("detUpButton"));
        detUpButton->setCursor(QCursor(Qt::PointingHandCursor));
        detUpButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	width: 60px;\n"
"	height: 60px;\n"
"	border-radius: 10px;\n"
"	border: 2px groove gray;\n"
"	border-style: outset;\n"
"}\n"
"QPushButton:hover{\n"
"	background-color:rgba(0, 170, 255, 128);\n"
"}\n"
"QPushButton::pressed{\n"
"	background-color: rgb(200, 200, 200);\n"
"	border-style: inset;\n"
"}"));
        detUpButton->setIcon(icon3);

        horizontalLayout_3->addWidget(detUpButton);

        detDownButton = new MethodButton(widget_4);
        detDownButton->setObjectName(QString::fromUtf8("detDownButton"));
        detDownButton->setCursor(QCursor(Qt::PointingHandCursor));
        detDownButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	width: 60px;\n"
"	height: 60px;\n"
"	border-radius: 10px;\n"
"	border: 2px groove gray;\n"
"	border-style: outset;\n"
"}\n"
"QPushButton:hover{\n"
"	background-color:rgba(0, 170, 255, 128);\n"
"}\n"
"QPushButton::pressed{\n"
"	background-color: rgb(200, 200, 200);\n"
"	border-style: inset;\n"
"}"));
        detDownButton->setIcon(icon4);

        horizontalLayout_3->addWidget(detDownButton);

        horizontalSpacer_15 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_15);


        verticalLayout_6->addWidget(widget_4);


        horizontalLayout_11->addWidget(detMethodBox);

        detParaBox = new QGroupBox(detectionTab);
        detParaBox->setObjectName(QString::fromUtf8("detParaBox"));
        detParaBox->setFont(font4);
        detParaBox->setStyleSheet(QString::fromUtf8("QGroupBox#detParaBox{\n"
"    border: 1px groove gray;\n"
"    margin-top: 5ex;\n"
"}\n"
"\n"
"QGroupBox#detParaBox::title{\n"
"    subcontrol-origin: margin;\n"
"    subcontrol-position: top left;\n"
"	left: 10px;\n"
"}"));
        verticalLayout_11 = new QVBoxLayout(detParaBox);
        verticalLayout_11->setObjectName(QString::fromUtf8("verticalLayout_11"));
        detParaBrowser = new QtTreePropertyBrowser(detParaBox);
        detParaBrowser->setObjectName(QString::fromUtf8("detParaBrowser"));
        detParaBrowser->setFont(font5);

        verticalLayout_11->addWidget(detParaBrowser);

        widget_7 = new QWidget(detParaBox);
        widget_7->setObjectName(QString::fromUtf8("widget_7"));
        horizontalLayout_8 = new QHBoxLayout(widget_7);
        horizontalLayout_8->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_8);

        detAddParaButton = new ParameterButton(widget_7);
        detAddParaButton->setObjectName(QString::fromUtf8("detAddParaButton"));
        detAddParaButton->setCursor(QCursor(Qt::PointingHandCursor));
        detAddParaButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	width: 60px;\n"
"	height: 60px;\n"
"	border-radius: 10px;\n"
"	border: 2px groove gray;\n"
"	border-style: outset;\n"
"}\n"
"QPushButton:hover{\n"
"	background-color:rgba(0, 170, 255, 128);\n"
"}\n"
"QPushButton::pressed{\n"
"	background-color: rgb(200, 200, 200);\n"
"	border-style: inset;\n"
"}"));
        detAddParaButton->setIcon(icon1);
        detAddParaButton->setIconSize(QSize(128, 128));

        horizontalLayout_8->addWidget(detAddParaButton);

        detDelParaButton = new ParameterButton(widget_7);
        detDelParaButton->setObjectName(QString::fromUtf8("detDelParaButton"));
        detDelParaButton->setCursor(QCursor(Qt::PointingHandCursor));
        detDelParaButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	width: 60px;\n"
"	height: 60px;\n"
"	border-radius: 10px;\n"
"	border: 2px groove gray;\n"
"	border-style: outset;\n"
"}\n"
"QPushButton:hover{\n"
"	background-color:rgba(0, 170, 255, 128);\n"
"}\n"
"QPushButton::pressed{\n"
"	background-color: rgb(200, 200, 200);\n"
"	border-style: inset;\n"
"}"));
        detDelParaButton->setIcon(icon2);

        horizontalLayout_8->addWidget(detDelParaButton);

        horizontalSpacer_18 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_18);

        detWithSegButton = new QRadioButton(widget_7);
        detWithSegButton->setObjectName(QString::fromUtf8("detWithSegButton"));
        detWithSegButton->setFont(font3);
        detWithSegButton->setCursor(QCursor(Qt::PointingHandCursor));
        detWithSegButton->setStyleSheet(QString::fromUtf8("QRadioButton#detWithSegButton::indicator::checked{\n"
"	width: 64px;\n"
"	height: 64px;\n"
"	image: url(:/src/pics/greenStone.png);\n"
"}\n"
"\n"
"QRadioButton#detWithSegButton::indicator::unchecked{\n"
"	width: 64px;\n"
"	height: 64px;\n"
"	image: url(:/src/pics/grayStone.png);\n"
"}"));

        horizontalLayout_8->addWidget(detWithSegButton);

        detEditNameButton = new ParameterButton(widget_7);
        detEditNameButton->setObjectName(QString::fromUtf8("detEditNameButton"));
        detEditNameButton->setCursor(QCursor(Qt::PointingHandCursor));
        detEditNameButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	width: 60px;\n"
"	height: 60px;\n"
"	border-radius: 10px;\n"
"	border: 2px groove gray;\n"
"	border-style: outset;\n"
"}\n"
"QPushButton:hover{\n"
"	background-color:rgba(0, 170, 255, 128);\n"
"}\n"
"QPushButton::pressed{\n"
"	background-color: rgb(200, 200, 200);\n"
"	border-style: inset;\n"
"}"));
        detEditNameButton->setIcon(icon5);

        horizontalLayout_8->addWidget(detEditNameButton);

        horizontalSpacer_19 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_19);


        verticalLayout_11->addWidget(widget_7);


        horizontalLayout_11->addWidget(detParaBox);

        Tab->addTab(detectionTab, QString());

        verticalLayout->addWidget(Tab);


        verticalLayout_2->addWidget(funcGroupBox);

        settingGroupBox = new QGroupBox(frame);
        settingGroupBox->setObjectName(QString::fromUtf8("settingGroupBox"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(settingGroupBox->sizePolicy().hasHeightForWidth());
        settingGroupBox->setSizePolicy(sizePolicy);
        settingGroupBox->setFont(font2);
        settingGroupBox->setStyleSheet(QString::fromUtf8("QGroupBox#settingGroupBox{\n"
"    border: none;\n"
"    margin-top: 10ex;\n"
"}\n"
"\n"
"QGroupBox#settingGroupBox::title{\n"
"    subcontrol-origin: margin;\n"
"    subcontrol-position: top left;\n"
"	left: 10px;\n"
"}\n"
"\n"
""));
        gridLayout_2 = new QGridLayout(settingGroupBox);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setVerticalSpacing(5);
        gridLayout_2->setContentsMargins(-1, -1, -1, 5);
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_2, 3, 1, 1, 1);

        selectOutputButton = new QPushButton(settingGroupBox);
        selectOutputButton->setObjectName(QString::fromUtf8("selectOutputButton"));
        selectOutputButton->setCursor(QCursor(Qt::PointingHandCursor));
        selectOutputButton->setStyleSheet(QString::fromUtf8("QPushButton{width: 70px;\n"
"			height:60px;\n"
"			border-radius: 20px;  border: 2px groove gray;\n"
"			border-style: outset;\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"	background-color:rgba(0, 170, 255, 128);\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"	background-color:rgb(200, 200, 200);\n"
"	border-style: inset;\n"
"}"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/src/pics/standardbutton-open-128.png"), QSize(), QIcon::Normal, QIcon::Off);
        selectOutputButton->setIcon(icon6);

        gridLayout_2->addWidget(selectOutputButton, 1, 3, 1, 1);

        label_4 = new QLabel(settingGroupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font3);
        label_4->setFrameShape(QFrame::NoFrame);
        label_4->setFrameShadow(QFrame::Plain);
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_4, 2, 0, 1, 1);

        label = new QLabel(settingGroupBox);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font6;
        font6.setFamily(QString::fromUtf8("Times New Roman"));
        font6.setPointSize(10);
        font6.setBold(false);
        font6.setWeight(50);
        label->setFont(font6);
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label, 0, 0, 1, 1);

        selectImageButton = new QPushButton(settingGroupBox);
        selectImageButton->setObjectName(QString::fromUtf8("selectImageButton"));
        selectImageButton->setCursor(QCursor(Qt::PointingHandCursor));
        selectImageButton->setStyleSheet(QString::fromUtf8("QPushButton{width: 70px;\n"
"			height: 60px;\n"
"			border-radius: 20px;  border: 2px groove gray;\n"
"			border-style: outset;\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"	background-color:rgba(0, 170, 255, 128);\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"	background-color:rgb(200, 200, 200);\n"
"	border-style: inset;\n"
"}"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/src/pics/file-128.png"), QSize(), QIcon::Normal, QIcon::Off);
        selectImageButton->setIcon(icon7);
        selectImageButton->setCheckable(false);

        gridLayout_2->addWidget(selectImageButton, 0, 3, 1, 1);

        label_3 = new QLabel(settingGroupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font3);
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_3, 1, 0, 1, 1);

        venvBox = new QComboBox(settingGroupBox);
        venvBox->setObjectName(QString::fromUtf8("venvBox"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(30);
        sizePolicy1.setHeightForWidth(venvBox->sizePolicy().hasHeightForWidth());
        venvBox->setSizePolicy(sizePolicy1);
        venvBox->setCursor(QCursor(Qt::PointingHandCursor));
        venvBox->setStyleSheet(QString::fromUtf8("QComboBox{\n"
"	height: 40px;\n"
"	border: 2px groove gray;\n"
"}\n"
"\n"
"QComboBox::hover{\n"
"	border-color:rgb(85, 170, 255);\n"
"}\n"
"QComboBox:!editable{\n"
"      background: white;\n"
"}\n"
""));
        venvBox->setInsertPolicy(QComboBox::InsertAtBottom);
        venvBox->setSizeAdjustPolicy(QComboBox::AdjustToContentsOnFirstShow);
        venvBox->setFrame(true);

        gridLayout_2->addWidget(venvBox, 2, 1, 1, 2);

        imagePath = new QLineEdit(settingGroupBox);
        imagePath->setObjectName(QString::fromUtf8("imagePath"));
        imagePath->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"		height: 40px;\n"
"		border-radius: 5px;\n"
"		border: 2px groove gray;\n"
"}\n"
"\n"
"QLineEdit::hover{\n"
"	border-color:rgb(85, 170, 255);\n"
"}\n"
""));

        gridLayout_2->addWidget(imagePath, 0, 1, 1, 2);

        editEnvButton = new QPushButton(settingGroupBox);
        editEnvButton->setObjectName(QString::fromUtf8("editEnvButton"));
        editEnvButton->setCursor(QCursor(Qt::PointingHandCursor));
        editEnvButton->setStyleSheet(QString::fromUtf8("QPushButton{width: 70px;\n"
"			height: 60px;\n"
"			border-radius: 20px;  border: 2px groove gray;\n"
"			border-style: outset;\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"	background-color:rgba(0, 170, 255, 128);\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"	background-color:rgb(200, 200, 200);\n"
"	border-style: inset;\n"
"}"));
        editEnvButton->setIcon(icon5);

        gridLayout_2->addWidget(editEnvButton, 2, 3, 1, 1);

        outputPath = new QLineEdit(settingGroupBox);
        outputPath->setObjectName(QString::fromUtf8("outputPath"));
        outputPath->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"		height: 40px;\n"
"		border-radius: 5px;\n"
"		border: 2px groove gray;\n"
"}\n"
"\n"
"QLineEdit::hover{\n"
"	border-color:rgb(85, 170, 255);\n"
"}"));

        gridLayout_2->addWidget(outputPath, 1, 1, 1, 2);

        cancel = new QPushButton(settingGroupBox);
        cancel->setObjectName(QString::fromUtf8("cancel"));
        cancel->setFont(font);
        cancel->setCursor(QCursor(Qt::PointingHandCursor));
        cancel->setStyleSheet(QString::fromUtf8("QPushButton{width:120px;\n"
"			height:60px;\n"
"			border-radius: 15px;\n"
"			border: 2px groove gray;\n"
"			border-style: outset;\n"
"\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"	background-color:rgba(0, 170, 255, 128);\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"	background-color:rgb(200, 200, 200);\n"
"	border-style: inset;\n"
"}\n"
""));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/src/pics/standardbutton-cancel-128.png"), QSize(), QIcon::Normal, QIcon::Off);
        cancel->setIcon(icon8);

        gridLayout_2->addWidget(cancel, 3, 2, 1, 1);

        ok = new QPushButton(settingGroupBox);
        ok->setObjectName(QString::fromUtf8("ok"));
        ok->setFont(font);
        ok->setCursor(QCursor(Qt::PointingHandCursor));
        ok->setStyleSheet(QString::fromUtf8("QPushButton{width:120px;\n"
"			height:60px;\n"
"			border-radius: 15px;\n"
"			border: 2px groove gray;\n"
"			border-style: outset;\n"
"\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"	background-color:rgba(0, 170, 255, 128);\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"	background-color:rgb(200, 200, 200);\n"
"	border-style: inset;\n"
"}\n"
""));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/src/pics/standardbutton-apply-128.png"), QSize(), QIcon::Normal, QIcon::Off);
        ok->setIcon(icon9);
        ok->setCheckable(false);

        gridLayout_2->addWidget(ok, 3, 3, 1, 1);


        verticalLayout_2->addWidget(settingGroupBox);


        verticalLayout_5->addWidget(frame);


        retranslateUi(Dialog);

        Tab->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Neuron Analysor based on Deep Learning", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        Dialog->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        titleLabel->setText(QApplication::translate("Dialog", "DNeuroMAT\357\274\232Deep-Learning Based Neuron Morphology Analysis Toolbox", 0, QApplication::UnicodeUTF8));
        groupBox_4->setTitle(QString());
        closeButton->setText(QString());
        funcGroupBox->setTitle(QApplication::translate("Dialog", "Modules", 0, QApplication::UnicodeUTF8));
        segMethodBox->setTitle(QApplication::translate("Dialog", "Methods", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        segMethodList->setToolTip(QApplication::translate("Dialog", "Double click to edit", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        segAddButton->setToolTip(QApplication::translate("Dialog", "Add method", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        segAddButton->setText(QString());
#ifndef QT_NO_TOOLTIP
        segDelButton->setToolTip(QApplication::translate("Dialog", "Delete method", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        segDelButton->setText(QString());
#ifndef QT_NO_TOOLTIP
        segUpButton->setToolTip(QApplication::translate("Dialog", "Move up", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        segUpButton->setText(QString());
#ifndef QT_NO_TOOLTIP
        segDownButton->setToolTip(QApplication::translate("Dialog", "Move down", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        segDownButton->setText(QString());
        segParaBox->setTitle(QApplication::translate("Dialog", "Parameters", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        segAddParaButton->setToolTip(QApplication::translate("Dialog", "Add parameter", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        segAddParaButton->setText(QString());
#ifndef QT_NO_TOOLTIP
        segDelParaButton->setToolTip(QApplication::translate("Dialog", "Delete parameter", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        segDelParaButton->setText(QString());
#ifndef QT_NO_TOOLTIP
        segEditNameButton->setToolTip(QApplication::translate("Dialog", "Edit name", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        segEditNameButton->setText(QString());
        Tab->setTabText(Tab->indexOf(segmentTab), QApplication::translate("Dialog", "Neuron Segmentation", 0, QApplication::UnicodeUTF8));
        traMethodBox->setTitle(QApplication::translate("Dialog", "Methods", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        traMethodList->setToolTip(QApplication::translate("Dialog", "Double click to edit", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        traAddButton->setToolTip(QApplication::translate("Dialog", "Add method", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        traAddButton->setText(QString());
#ifndef QT_NO_TOOLTIP
        traDelButton->setToolTip(QApplication::translate("Dialog", "Delete method", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        traDelButton->setText(QString());
#ifndef QT_NO_TOOLTIP
        traUpButton->setToolTip(QApplication::translate("Dialog", "Move up", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        traUpButton->setText(QString());
#ifndef QT_NO_TOOLTIP
        traDownButton->setToolTip(QApplication::translate("Dialog", "Move down", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        traDownButton->setText(QString());
        traParaBox->setTitle(QApplication::translate("Dialog", "Parameters", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        traAddParaButton->setToolTip(QApplication::translate("Dialog", "Add parameter", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        traAddParaButton->setText(QString());
#ifndef QT_NO_TOOLTIP
        traDelParaButton->setToolTip(QApplication::translate("Dialog", "Delete parameter", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        traDelParaButton->setText(QString());
#ifndef QT_NO_TOOLTIP
        traWithSegButton->setToolTip(QApplication::translate("Dialog", "Reconstruction with Segmentation (Green ON, Gray OFF)", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        traWithSegButton->setText(QString());
#ifndef QT_NO_TOOLTIP
        traEditNameButton->setToolTip(QApplication::translate("Dialog", "Edit name", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        traEditNameButton->setText(QString());
        Tab->setTabText(Tab->indexOf(tracingTab), QApplication::translate("Dialog", "Neuron Reconstruction", 0, QApplication::UnicodeUTF8));
        detMethodBox->setTitle(QApplication::translate("Dialog", "Methods", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        detMethodList->setToolTip(QApplication::translate("Dialog", "Double click to edit", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        detAddButton->setToolTip(QApplication::translate("Dialog", "Add method", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        detAddButton->setText(QString());
#ifndef QT_NO_TOOLTIP
        detDelButton->setToolTip(QApplication::translate("Dialog", "Delete method", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        detDelButton->setText(QString());
#ifndef QT_NO_TOOLTIP
        detUpButton->setToolTip(QApplication::translate("Dialog", "Move up", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        detUpButton->setText(QString());
#ifndef QT_NO_TOOLTIP
        detDownButton->setToolTip(QApplication::translate("Dialog", "Move down", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        detDownButton->setText(QString());
        detParaBox->setTitle(QApplication::translate("Dialog", "Parameters", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        detAddParaButton->setToolTip(QApplication::translate("Dialog", "Add parameter", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        detAddParaButton->setText(QString());
#ifndef QT_NO_TOOLTIP
        detDelParaButton->setToolTip(QApplication::translate("Dialog", "Delete parameter", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        detDelParaButton->setText(QString());
#ifndef QT_NO_TOOLTIP
        detWithSegButton->setToolTip(QApplication::translate("Dialog", "Detection with Segmentation (Green ON, Gray OFF)", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        detWithSegButton->setText(QString());
#ifndef QT_NO_TOOLTIP
        detEditNameButton->setToolTip(QApplication::translate("Dialog", "Edit name", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        detEditNameButton->setText(QString());
        Tab->setTabText(Tab->indexOf(detectionTab), QApplication::translate("Dialog", "Critical Points Detection", 0, QApplication::UnicodeUTF8));
        settingGroupBox->setTitle(QApplication::translate("Dialog", "I/O Settings", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        selectOutputButton->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        selectOutputButton->setText(QString());
        label_4->setText(QApplication::translate("Dialog", "python venv:", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Dialog", " image path:", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        selectImageButton->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        selectImageButton->setText(QString());
        label_3->setText(QApplication::translate("Dialog", "output path:", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        editEnvButton->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        editEnvButton->setText(QString());
        cancel->setText(QString());
        ok->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
