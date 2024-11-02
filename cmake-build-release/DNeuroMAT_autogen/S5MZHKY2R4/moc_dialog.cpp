/****************************************************************************
** Meta object code from reading C++ file 'dialog.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/cpp/dialog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_InterfaceDialog[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      17,   16,   16,   16, 0x08,
      35,   16,   16,   16, 0x08,
      52,   16,   16,   16, 0x08,
      71,   16,   16,   16, 0x08,
      98,   87,   16,   16, 0x08,
     122,   87,   16,   16, 0x08,
     146,   87,   16,   16, 0x08,
     173,   87,   16,   16, 0x08,
     207,  202,   16,   16, 0x08,
     252,  240,   16,   16, 0x08,
     289,  240,   16,   16, 0x08,
     326,  240,   16,   16, 0x08,
     368,   16,   16,   16, 0x08,
     384,   16,   16,   16, 0x08,
     400,   16,   16,   16, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_InterfaceDialog[] = {
    "InterfaceDialog\0\0selectImageFile()\0"
    "selectImageDir()\0selectOutputPath()\0"
    "editPythonEnv()\0methodList\0"
    "addMethod(QListWidget*)\0delMethod(QListWidget*)\0"
    "moveUpMethod(QListWidget*)\0"
    "moveDownMethod(QListWidget*)\0item\0"
    "editMethodName(QListWidgetItem*)\0"
    "paraBrowser\0addParameter(QtTreePropertyBrowser*)\0"
    "delParameter(QtTreePropertyBrowser*)\0"
    "editParameterName(QtTreePropertyBrowser*)\0"
    "saveParameter()\0readParameter()\0"
    "saveCache()\0"
};

void InterfaceDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        InterfaceDialog *_t = static_cast<InterfaceDialog *>(_o);
        switch (_id) {
        case 0: _t->selectImageFile(); break;
        case 1: _t->selectImageDir(); break;
        case 2: _t->selectOutputPath(); break;
        case 3: _t->editPythonEnv(); break;
        case 4: _t->addMethod((*reinterpret_cast< QListWidget*(*)>(_a[1]))); break;
        case 5: _t->delMethod((*reinterpret_cast< QListWidget*(*)>(_a[1]))); break;
        case 6: _t->moveUpMethod((*reinterpret_cast< QListWidget*(*)>(_a[1]))); break;
        case 7: _t->moveDownMethod((*reinterpret_cast< QListWidget*(*)>(_a[1]))); break;
        case 8: _t->editMethodName((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 9: _t->addParameter((*reinterpret_cast< QtTreePropertyBrowser*(*)>(_a[1]))); break;
        case 10: _t->delParameter((*reinterpret_cast< QtTreePropertyBrowser*(*)>(_a[1]))); break;
        case 11: _t->editParameterName((*reinterpret_cast< QtTreePropertyBrowser*(*)>(_a[1]))); break;
        case 12: _t->saveParameter(); break;
        case 13: _t->readParameter(); break;
        case 14: _t->saveCache(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData InterfaceDialog::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject InterfaceDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_InterfaceDialog,
      qt_meta_data_InterfaceDialog, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &InterfaceDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *InterfaceDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *InterfaceDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_InterfaceDialog))
        return static_cast<void*>(const_cast< InterfaceDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int InterfaceDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
