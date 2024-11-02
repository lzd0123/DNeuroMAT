#ifndef PARAMETER_BUTTON_H
#define PARAMETER_BUTTON_H

#include "QtGui"
#include "QPushButton"
#include "qtpropertybrowser.h"
#include "qttreepropertybrowser.h"

class ParameterButton: public QPushButton{
    Q_OBJECT
signals:
    void changed(QtTreePropertyBrowser*);
private:
    QtTreePropertyBrowser* paraBrowser;

public slots:
    void sendChangeSignal() {emit changed(paraBrowser);}

public:
    ParameterButton(QWidget* parent = 0): QPushButton(parent), paraBrowser(nullptr){}
    ~ParameterButton(){};
    void setParaBrowser(QtTreePropertyBrowser* browser) {paraBrowser = browser;}
};


#endif //PARAMETER_BUTTON_H
