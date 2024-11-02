#ifndef __METHOD_BUTTON_H__
#define __METHOD_BUTTON_H__

#include "QPushButton"
#include "QListWidget"

class MethodButton: public QPushButton{
    Q_OBJECT
signals:
    void changed(QListWidget*);

private:
    QListWidget* methodList;
public slots:
    void sendChangeSignal() {emit changed(methodList);};

public:
    void setMethodList(QListWidget* p) {methodList = p;}
    MethodButton(QWidget* parent = nullptr): QPushButton(parent), methodList(nullptr) {}
    ~MethodButton(){}
};

#endif //__METHOD_BUTTON_H__
