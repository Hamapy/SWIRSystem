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
struct qt_meta_stringdata_WorkerLCTF_t {
    QByteArrayData data[4];
    char stringdata0[48];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_WorkerLCTF_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_WorkerLCTF_t qt_meta_stringdata_WorkerLCTF = {
    {
QT_MOC_LITERAL(0, 0, 10), // "WorkerLCTF"
QT_MOC_LITERAL(1, 11, 17), // "waveLengthChanged"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 17) // "wavelengthChanged"

    },
    "WorkerLCTF\0waveLengthChanged\0\0"
    "wavelengthChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_WorkerLCTF[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   19,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,

       0        // eod
};

void WorkerLCTF::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        WorkerLCTF *_t = static_cast<WorkerLCTF *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->waveLengthChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject WorkerLCTF::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_WorkerLCTF.data,
      qt_meta_data_WorkerLCTF,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *WorkerLCTF::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *WorkerLCTF::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_WorkerLCTF.stringdata0))
        return static_cast<void*>(const_cast< WorkerLCTF*>(this));
    return QObject::qt_metacast(_clname);
}

int WorkerLCTF::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}
struct qt_meta_stringdata_WorkerSWIR_t {
    QByteArrayData data[9];
    char stringdata0[101];
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
QT_MOC_LITERAL(3, 24, 12), // "acquringSWIR"
QT_MOC_LITERAL(4, 37, 6), // "scanOK"
QT_MOC_LITERAL(5, 44, 18), // "sendingCollectTime"
QT_MOC_LITERAL(6, 63, 15), // "sendingSaveTime"
QT_MOC_LITERAL(7, 79, 16), // "sendingTotalTime"
QT_MOC_LITERAL(8, 96, 4) // "Scan"

    },
    "WorkerSWIR\0sendingSWIR\0\0acquringSWIR\0"
    "scanOK\0sendingCollectTime\0sendingSaveTime\0"
    "sendingTotalTime\0Scan"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_WorkerSWIR[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x06 /* Public */,
       3,    1,   52,    2, 0x06 /* Public */,
       4,    0,   55,    2, 0x06 /* Public */,
       5,    1,   56,    2, 0x06 /* Public */,
       6,    1,   59,    2, 0x06 /* Public */,
       7,    1,   62,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    0,   65,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QImage,    2,
    QMetaType::Void, QMetaType::QImage,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double,    2,
    QMetaType::Void, QMetaType::Double,    2,
    QMetaType::Void, QMetaType::Double,    2,

 // slots: parameters
    QMetaType::Void,

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
        case 2: _t->scanOK(); break;
        case 3: _t->sendingCollectTime((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 4: _t->sendingSaveTime((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 5: _t->sendingTotalTime((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 6: _t->Scan(); break;
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
        {
            typedef void (WorkerSWIR::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&WorkerSWIR::scanOK)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (WorkerSWIR::*_t)(double );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&WorkerSWIR::sendingCollectTime)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (WorkerSWIR::*_t)(double );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&WorkerSWIR::sendingSaveTime)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (WorkerSWIR::*_t)(double );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&WorkerSWIR::sendingTotalTime)) {
                *result = 5;
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
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
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

// SIGNAL 2
void WorkerSWIR::scanOK()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}

// SIGNAL 3
void WorkerSWIR::sendingCollectTime(double _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void WorkerSWIR::sendingSaveTime(double _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void WorkerSWIR::sendingTotalTime(double _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[29];
    char stringdata0[393];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 17), // "sendingWavelength"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 12), // "scanPrepared"
QT_MOC_LITERAL(4, 43, 13), // "InitializeAll"
QT_MOC_LITERAL(5, 57, 10), // "ConnectRGB"
QT_MOC_LITERAL(6, 68, 11), // "ConnectSWIR"
QT_MOC_LITERAL(7, 80, 11), // "ConnectLCTF"
QT_MOC_LITERAL(8, 92, 15), // "DisplayImageRGB"
QT_MOC_LITERAL(9, 108, 16), // "DisplayImageSWIR"
QT_MOC_LITERAL(10, 125, 18), // "DisplayCollectTime"
QT_MOC_LITERAL(11, 144, 15), // "DisplaySaveTime"
QT_MOC_LITERAL(12, 160, 16), // "DisplayTotalTime"
QT_MOC_LITERAL(13, 177, 13), // "DisconnectRGB"
QT_MOC_LITERAL(14, 191, 14), // "DisconnectSWIR"
QT_MOC_LITERAL(15, 206, 10), // "PreviewRGB"
QT_MOC_LITERAL(16, 217, 11), // "isPreviewed"
QT_MOC_LITERAL(17, 229, 11), // "PreviewSWIR"
QT_MOC_LITERAL(18, 241, 10), // "CaptureRGB"
QT_MOC_LITERAL(19, 252, 11), // "CaptureSWIR"
QT_MOC_LITERAL(20, 264, 17), // "ShowConfiguration"
QT_MOC_LITERAL(21, 282, 18), // "WavelengthSelected"
QT_MOC_LITERAL(22, 301, 9), // "FwChecked"
QT_MOC_LITERAL(23, 311, 16), // "StartAcquisition"
QT_MOC_LITERAL(24, 328, 15), // "SaveAcqImageRGB"
QT_MOC_LITERAL(25, 344, 16), // "SaveAcqImageSWIR"
QT_MOC_LITERAL(26, 361, 15), // "StopAcquisition"
QT_MOC_LITERAL(27, 377, 4), // "Quit"
QT_MOC_LITERAL(28, 382, 10) // "DestroyAll"

    },
    "MainWindow\0sendingWavelength\0\0"
    "scanPrepared\0InitializeAll\0ConnectRGB\0"
    "ConnectSWIR\0ConnectLCTF\0DisplayImageRGB\0"
    "DisplayImageSWIR\0DisplayCollectTime\0"
    "DisplaySaveTime\0DisplayTotalTime\0"
    "DisconnectRGB\0DisconnectSWIR\0PreviewRGB\0"
    "isPreviewed\0PreviewSWIR\0CaptureRGB\0"
    "CaptureSWIR\0ShowConfiguration\0"
    "WavelengthSelected\0FwChecked\0"
    "StartAcquisition\0SaveAcqImageRGB\0"
    "SaveAcqImageSWIR\0StopAcquisition\0Quit\0"
    "DestroyAll"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      26,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  144,    2, 0x06 /* Public */,
       3,    0,  147,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,  148,    2, 0x08 /* Private */,
       5,    0,  149,    2, 0x08 /* Private */,
       6,    0,  150,    2, 0x08 /* Private */,
       7,    0,  151,    2, 0x08 /* Private */,
       8,    1,  152,    2, 0x08 /* Private */,
       9,    1,  155,    2, 0x08 /* Private */,
      10,    1,  158,    2, 0x08 /* Private */,
      11,    1,  161,    2, 0x08 /* Private */,
      12,    1,  164,    2, 0x08 /* Private */,
      13,    0,  167,    2, 0x08 /* Private */,
      14,    0,  168,    2, 0x08 /* Private */,
      15,    1,  169,    2, 0x08 /* Private */,
      17,    1,  172,    2, 0x08 /* Private */,
      18,    0,  175,    2, 0x08 /* Private */,
      19,    0,  176,    2, 0x08 /* Private */,
      20,    0,  177,    2, 0x08 /* Private */,
      21,    0,  178,    2, 0x08 /* Private */,
      22,    0,  179,    2, 0x08 /* Private */,
      23,    0,  180,    2, 0x08 /* Private */,
      24,    1,  181,    2, 0x08 /* Private */,
      25,    1,  184,    2, 0x08 /* Private */,
      26,    0,  187,    2, 0x08 /* Private */,
      27,    0,  188,    2, 0x08 /* Private */,
      28,    0,  189,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Bool,
    QMetaType::Bool,
    QMetaType::Bool,
    QMetaType::Void, QMetaType::QImage,    2,
    QMetaType::Void, QMetaType::QImage,    2,
    QMetaType::Void, QMetaType::Double,    2,
    QMetaType::Void, QMetaType::Double,    2,
    QMetaType::Void, QMetaType::Double,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   16,
    QMetaType::Void, QMetaType::Bool,   16,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Int,
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
        case 0: _t->sendingWavelength((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->scanPrepared(); break;
        case 2: _t->InitializeAll(); break;
        case 3: { bool _r = _t->ConnectRGB();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 4: { bool _r = _t->ConnectSWIR();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 5: { bool _r = _t->ConnectLCTF();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 6: _t->DisplayImageRGB((*reinterpret_cast< QImage(*)>(_a[1]))); break;
        case 7: _t->DisplayImageSWIR((*reinterpret_cast< QImage(*)>(_a[1]))); break;
        case 8: _t->DisplayCollectTime((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 9: _t->DisplaySaveTime((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 10: _t->DisplayTotalTime((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 11: _t->DisconnectRGB(); break;
        case 12: _t->DisconnectSWIR(); break;
        case 13: _t->PreviewRGB((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 14: _t->PreviewSWIR((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 15: _t->CaptureRGB(); break;
        case 16: _t->CaptureSWIR(); break;
        case 17: _t->ShowConfiguration(); break;
        case 18: { int _r = _t->WavelengthSelected();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 19: _t->FwChecked(); break;
        case 20: _t->StartAcquisition(); break;
        case 21: _t->SaveAcqImageRGB((*reinterpret_cast< QImage(*)>(_a[1]))); break;
        case 22: _t->SaveAcqImageSWIR((*reinterpret_cast< QImage(*)>(_a[1]))); break;
        case 23: _t->StopAcquisition(); break;
        case 24: _t->Quit(); break;
        case 25: _t->DestroyAll(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MainWindow::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::sendingWavelength)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (MainWindow::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::scanPrepared)) {
                *result = 1;
                return;
            }
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
        if (_id < 26)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 26;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 26)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 26;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::sendingWavelength(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MainWindow::scanPrepared()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
