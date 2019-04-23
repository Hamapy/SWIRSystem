/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_WorkerRGB_t {
    QByteArrayData data[4];
    char stringdata0[34];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_WorkerRGB_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_WorkerRGB_t qt_meta_stringdata_WorkerRGB = {
    {
QT_MOC_LITERAL(0, 0, 9), // "WorkerRGB"
QT_MOC_LITERAL(1, 10, 10), // "sendingRGB"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 11) // "acquringRGB"

    },
    "WorkerRGB\0sendingRGB\0\0acquringRGB"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_WorkerRGB[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   24,    2, 0x06 /* Public */,
       3,    1,   27,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QImage,    2,
    QMetaType::Void, QMetaType::QImage,    2,

       0        // eod
};

void WorkerRGB::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        WorkerRGB *_t = static_cast<WorkerRGB *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendingRGB((*reinterpret_cast< QImage(*)>(_a[1]))); break;
        case 1: _t->acquringRGB((*reinterpret_cast< QImage(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (WorkerRGB::*_t)(QImage );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&WorkerRGB::sendingRGB)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (WorkerRGB::*_t)(QImage );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&WorkerRGB::acquringRGB)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject WorkerRGB::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_WorkerRGB.data,
      qt_meta_data_WorkerRGB,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *WorkerRGB::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *WorkerRGB::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_WorkerRGB.stringdata0))
        return static_cast<void*>(const_cast< WorkerRGB*>(this));
    return QObject::qt_metacast(_clname);
}

int WorkerRGB::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void WorkerRGB::sendingRGB(QImage _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void WorkerRGB::acquringRGB(QImage _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
struct qt_meta_stringdata_WorkerSWIR_t {
    QByteArrayData data[4];
    char stringdata0[37];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_WorkerSWIR_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_WorkerSWIR_t qt_meta_stringdata_WorkerSWIR = {
    {
QT_MOC_LITERAL(0, 0, 10), // "WorkerSWIR"
QT_MOC_LITERAL(1, 11, 11), // "sendingSWIR"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 12) // "acquringSWIR"

    },
    "WorkerSWIR\0sendingSWIR\0\0acquringSWIR"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_WorkerSWIR[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   24,    2, 0x06 /* Public */,
       3,    1,   27,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QImage,    2,
    QMetaType::Void, QMetaType::QImage,    2,

       0        // eod
};

void WorkerSWIR::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        WorkerSWIR *_t = static_cast<WorkerSWIR *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendingSWIR((*reinterpret_cast< QImage(*)>(_a[1]))); break;
        case 1: _t->acquringSWIR((*reinterpret_cast< QImage(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (WorkerSWIR::*_t)(QImage );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&WorkerSWIR::sendingSWIR)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (WorkerSWIR::*_t)(QImage );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&WorkerSWIR::acquringSWIR)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject WorkerSWIR::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_WorkerSWIR.data,
      qt_meta_data_WorkerSWIR,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *WorkerSWIR::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *WorkerSWIR::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_WorkerSWIR.stringdata0))
        return static_cast<void*>(const_cast< WorkerSWIR*>(this));
    return QObject::qt_metacast(_clname);
}

int WorkerSWIR::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void WorkerSWIR::sendingSWIR(QImage _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void WorkerSWIR::acquringSWIR(QImage _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[24];
    char stringdata0[310];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 13), // "InitializeAll"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 10), // "ConnectRGB"
QT_MOC_LITERAL(4, 37, 11), // "ConnectSWIR"
QT_MOC_LITERAL(5, 49, 15), // "DisplayImageRGB"
QT_MOC_LITERAL(6, 65, 16), // "DisplayImageSWIR"
QT_MOC_LITERAL(7, 82, 13), // "DisconnectRGB"
QT_MOC_LITERAL(8, 96, 14), // "DisconnectSWIR"
QT_MOC_LITERAL(9, 111, 10), // "PreviewRGB"
QT_MOC_LITERAL(10, 122, 11), // "isPreviewed"
QT_MOC_LITERAL(11, 134, 11), // "PreviewSWIR"
QT_MOC_LITERAL(12, 146, 10), // "CaptureRGB"
QT_MOC_LITERAL(13, 157, 11), // "CaptureSWIR"
QT_MOC_LITERAL(14, 169, 17), // "ShowConfiguration"
QT_MOC_LITERAL(15, 187, 18), // "WavelengthSelected"
QT_MOC_LITERAL(16, 206, 11), // "LctfChecked"
QT_MOC_LITERAL(17, 218, 9), // "FwChecked"
QT_MOC_LITERAL(18, 228, 16), // "StartAcquisition"
QT_MOC_LITERAL(19, 245, 15), // "SaveAcqImageRGB"
QT_MOC_LITERAL(20, 261, 16), // "SaveAcqImageSWIR"
QT_MOC_LITERAL(21, 278, 15), // "StopAcquisition"
QT_MOC_LITERAL(22, 294, 4), // "Quit"
QT_MOC_LITERAL(23, 299, 10) // "DestroyAll"

    },
    "MainWindow\0InitializeAll\0\0ConnectRGB\0"
    "ConnectSWIR\0DisplayImageRGB\0"
    "DisplayImageSWIR\0DisconnectRGB\0"
    "DisconnectSWIR\0PreviewRGB\0isPreviewed\0"
    "PreviewSWIR\0CaptureRGB\0CaptureSWIR\0"
    "ShowConfiguration\0WavelengthSelected\0"
    "LctfChecked\0FwChecked\0StartAcquisition\0"
    "SaveAcqImageRGB\0SaveAcqImageSWIR\0"
    "StopAcquisition\0Quit\0DestroyAll"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      21,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,  119,    2, 0x08 /* Private */,
       3,    0,  120,    2, 0x08 /* Private */,
       4,    0,  121,    2, 0x08 /* Private */,
       5,    1,  122,    2, 0x08 /* Private */,
       6,    1,  125,    2, 0x08 /* Private */,
       7,    0,  128,    2, 0x08 /* Private */,
       8,    0,  129,    2, 0x08 /* Private */,
       9,    1,  130,    2, 0x08 /* Private */,
      11,    1,  133,    2, 0x08 /* Private */,
      12,    0,  136,    2, 0x08 /* Private */,
      13,    0,  137,    2, 0x08 /* Private */,
      14,    0,  138,    2, 0x08 /* Private */,
      15,    0,  139,    2, 0x08 /* Private */,
      16,    0,  140,    2, 0x08 /* Private */,
      17,    0,  141,    2, 0x08 /* Private */,
      18,    0,  142,    2, 0x08 /* Private */,
      19,    1,  143,    2, 0x08 /* Private */,
      20,    1,  146,    2, 0x08 /* Private */,
      21,    0,  149,    2, 0x08 /* Private */,
      22,    0,  150,    2, 0x08 /* Private */,
      23,    0,  151,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Bool,
    QMetaType::Bool,
    QMetaType::Void, QMetaType::QImage,    2,
    QMetaType::Void, QMetaType::QImage,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   10,
    QMetaType::Void, QMetaType::Bool,   10,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Int,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QImage,    2,
    QMetaType::Void, QMetaType::QImage,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->InitializeAll(); break;
        case 1: { bool _r = _t->ConnectRGB();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 2: { bool _r = _t->ConnectSWIR();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 3: _t->DisplayImageRGB((*reinterpret_cast< QImage(*)>(_a[1]))); break;
        case 4: _t->DisplayImageSWIR((*reinterpret_cast< QImage(*)>(_a[1]))); break;
        case 5: _t->DisconnectRGB(); break;
        case 6: _t->DisconnectSWIR(); break;
        case 7: _t->PreviewRGB((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 8: _t->PreviewSWIR((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 9: _t->CaptureRGB(); break;
        case 10: _t->CaptureSWIR(); break;
        case 11: _t->ShowConfiguration(); break;
        case 12: { int _r = _t->WavelengthSelected();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 13: _t->LctfChecked(); break;
        case 14: _t->FwChecked(); break;
        case 15: _t->StartAcquisition(); break;
        case 16: _t->SaveAcqImageRGB((*reinterpret_cast< QImage(*)>(_a[1]))); break;
        case 17: _t->SaveAcqImageSWIR((*reinterpret_cast< QImage(*)>(_a[1]))); break;
        case 18: _t->StopAcquisition(); break;
        case 19: _t->Quit(); break;
        case 20: _t->DestroyAll(); break;
        default: ;
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 21)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 21;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 21)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 21;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
