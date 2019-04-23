/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindowClass
{
public:
    QAction *action_initial;
    QAction *action_config;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QGridLayout *gridLayout_2;
    QGroupBox *groupBox_rgbCamera;
    QGridLayout *gridLayout_5;
    QHBoxLayout *horizontalLayout_5;
    QCheckBox *checkBox_preview;
    QPushButton *pushButton_conn1;
    QPushButton *pushButton_disconn1;
    QPushButton *pushButton_cap1;
    QLabel *label_blank;
    QGroupBox *groupBox_swirCamera;
    QGridLayout *gridLayout_6;
    QHBoxLayout *horizontalLayout_4;
    QGroupBox *groupBox_device;
    QRadioButton *radioButton_FW;
    QRadioButton *radioButton_LCTF;
    QGroupBox *groupBox_channel;
    QComboBox *comboBox_wavelength;
    QLabel *label_nm;
    QHBoxLayout *horizontalLayout_6;
    QCheckBox *checkBox_preview2;
    QPushButton *pushButton_conn2;
    QPushButton *pushButton_disconn2;
    QPushButton *pushButton_cap2;
    QGroupBox *groupBox_swirVideo;
    QGridLayout *gridLayout_3;
    QLabel *label_swirCamera;
    QGroupBox *groupBox_rgbVideo;
    QGridLayout *gridLayout_4;
    QLabel *label_rgbCamera;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_startacq;
    QPushButton *pushButton_stopacq;
    QPushButton *pushButton_quit;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_collect;
    QLabel *label_save;
    QLabel *label_total;
    QMenuBar *menuBar;
    QMenu *menu;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindowClass)
    {
        if (MainWindowClass->objectName().isEmpty())
            MainWindowClass->setObjectName(QStringLiteral("MainWindowClass"));
        MainWindowClass->resize(1339, 935);
        QFont font;
        font.setFamily(QStringLiteral("Times New Roman"));
        font.setPointSize(12);
        MainWindowClass->setFont(font);
        action_initial = new QAction(MainWindowClass);
        action_initial->setObjectName(QStringLiteral("action_initial"));
        action_config = new QAction(MainWindowClass);
        action_config->setObjectName(QStringLiteral("action_config"));
        centralWidget = new QWidget(MainWindowClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setSizeConstraint(QLayout::SetFixedSize);
        groupBox_rgbCamera = new QGroupBox(centralWidget);
        groupBox_rgbCamera->setObjectName(QStringLiteral("groupBox_rgbCamera"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(18);
        groupBox_rgbCamera->setFont(font1);
        gridLayout_5 = new QGridLayout(groupBox_rgbCamera);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        gridLayout_5->setContentsMargins(-1, 9, -1, -1);
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(-1, 0, -1, -1);
        checkBox_preview = new QCheckBox(groupBox_rgbCamera);
        checkBox_preview->setObjectName(QStringLiteral("checkBox_preview"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font2.setPointSize(9);
        checkBox_preview->setFont(font2);

        horizontalLayout_5->addWidget(checkBox_preview);

        pushButton_conn1 = new QPushButton(groupBox_rgbCamera);
        pushButton_conn1->setObjectName(QStringLiteral("pushButton_conn1"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton_conn1->sizePolicy().hasHeightForWidth());
        pushButton_conn1->setSizePolicy(sizePolicy);
        QFont font3;
        font3.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font3.setPointSize(9);
        font3.setBold(false);
        font3.setWeight(50);
        pushButton_conn1->setFont(font3);

        horizontalLayout_5->addWidget(pushButton_conn1);

        pushButton_disconn1 = new QPushButton(groupBox_rgbCamera);
        pushButton_disconn1->setObjectName(QStringLiteral("pushButton_disconn1"));
        sizePolicy.setHeightForWidth(pushButton_disconn1->sizePolicy().hasHeightForWidth());
        pushButton_disconn1->setSizePolicy(sizePolicy);
        pushButton_disconn1->setFont(font2);

        horizontalLayout_5->addWidget(pushButton_disconn1);

        pushButton_cap1 = new QPushButton(groupBox_rgbCamera);
        pushButton_cap1->setObjectName(QStringLiteral("pushButton_cap1"));
        sizePolicy.setHeightForWidth(pushButton_cap1->sizePolicy().hasHeightForWidth());
        pushButton_cap1->setSizePolicy(sizePolicy);
        pushButton_cap1->setFont(font3);

        horizontalLayout_5->addWidget(pushButton_cap1);


        gridLayout_5->addLayout(horizontalLayout_5, 1, 0, 1, 1);

        label_blank = new QLabel(groupBox_rgbCamera);
        label_blank->setObjectName(QStringLiteral("label_blank"));

        gridLayout_5->addWidget(label_blank, 0, 0, 1, 1);

        gridLayout_5->setRowStretch(0, 1);
        gridLayout_5->setRowStretch(1, 1);

        gridLayout_2->addWidget(groupBox_rgbCamera, 0, 0, 1, 1);

        groupBox_swirCamera = new QGroupBox(centralWidget);
        groupBox_swirCamera->setObjectName(QStringLiteral("groupBox_swirCamera"));
        groupBox_swirCamera->setFont(font1);
        gridLayout_6 = new QGridLayout(groupBox_swirCamera);
        gridLayout_6->setSpacing(6);
        gridLayout_6->setContentsMargins(11, 11, 11, 11);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        groupBox_device = new QGroupBox(groupBox_swirCamera);
        groupBox_device->setObjectName(QStringLiteral("groupBox_device"));
        QFont font4;
        font4.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font4.setPointSize(10);
        groupBox_device->setFont(font4);
        radioButton_FW = new QRadioButton(groupBox_device);
        radioButton_FW->setObjectName(QStringLiteral("radioButton_FW"));
        radioButton_FW->setGeometry(QRect(80, 30, 101, 23));
        radioButton_FW->setFont(font3);
        radioButton_LCTF = new QRadioButton(groupBox_device);
        radioButton_LCTF->setObjectName(QStringLiteral("radioButton_LCTF"));
        radioButton_LCTF->setGeometry(QRect(10, 30, 61, 23));
        radioButton_LCTF->setFont(font3);

        horizontalLayout_4->addWidget(groupBox_device);

        groupBox_channel = new QGroupBox(groupBox_swirCamera);
        groupBox_channel->setObjectName(QStringLiteral("groupBox_channel"));
        groupBox_channel->setFont(font4);
        comboBox_wavelength = new QComboBox(groupBox_channel);
        comboBox_wavelength->setObjectName(QStringLiteral("comboBox_wavelength"));
        comboBox_wavelength->setGeometry(QRect(10, 30, 141, 20));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(comboBox_wavelength->sizePolicy().hasHeightForWidth());
        comboBox_wavelength->setSizePolicy(sizePolicy1);
        label_nm = new QLabel(groupBox_channel);
        label_nm->setObjectName(QStringLiteral("label_nm"));
        label_nm->setGeometry(QRect(160, 30, 31, 16));

        horizontalLayout_4->addWidget(groupBox_channel);


        gridLayout_6->addLayout(horizontalLayout_4, 0, 0, 1, 1);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        checkBox_preview2 = new QCheckBox(groupBox_swirCamera);
        checkBox_preview2->setObjectName(QStringLiteral("checkBox_preview2"));
        checkBox_preview2->setFont(font2);

        horizontalLayout_6->addWidget(checkBox_preview2);

        pushButton_conn2 = new QPushButton(groupBox_swirCamera);
        pushButton_conn2->setObjectName(QStringLiteral("pushButton_conn2"));
        QSizePolicy sizePolicy2(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(pushButton_conn2->sizePolicy().hasHeightForWidth());
        pushButton_conn2->setSizePolicy(sizePolicy2);
        pushButton_conn2->setFont(font3);

        horizontalLayout_6->addWidget(pushButton_conn2);

        pushButton_disconn2 = new QPushButton(groupBox_swirCamera);
        pushButton_disconn2->setObjectName(QStringLiteral("pushButton_disconn2"));
        sizePolicy2.setHeightForWidth(pushButton_disconn2->sizePolicy().hasHeightForWidth());
        pushButton_disconn2->setSizePolicy(sizePolicy2);
        pushButton_disconn2->setFont(font2);

        horizontalLayout_6->addWidget(pushButton_disconn2);

        pushButton_cap2 = new QPushButton(groupBox_swirCamera);
        pushButton_cap2->setObjectName(QStringLiteral("pushButton_cap2"));
        sizePolicy2.setHeightForWidth(pushButton_cap2->sizePolicy().hasHeightForWidth());
        pushButton_cap2->setSizePolicy(sizePolicy2);
        pushButton_cap2->setFont(font3);

        horizontalLayout_6->addWidget(pushButton_cap2);


        gridLayout_6->addLayout(horizontalLayout_6, 1, 0, 1, 1);

        gridLayout_6->setRowStretch(0, 1);
        gridLayout_6->setRowStretch(1, 1);

        gridLayout_2->addWidget(groupBox_swirCamera, 0, 1, 1, 1);

        groupBox_swirVideo = new QGroupBox(centralWidget);
        groupBox_swirVideo->setObjectName(QStringLiteral("groupBox_swirVideo"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(groupBox_swirVideo->sizePolicy().hasHeightForWidth());
        groupBox_swirVideo->setSizePolicy(sizePolicy3);
        QFont font5;
        font5.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        groupBox_swirVideo->setFont(font5);
        gridLayout_3 = new QGridLayout(groupBox_swirVideo);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        label_swirCamera = new QLabel(groupBox_swirVideo);
        label_swirCamera->setObjectName(QStringLiteral("label_swirCamera"));
        QFont font6;
        font6.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        font6.setPointSize(25);
        label_swirCamera->setFont(font6);
        label_swirCamera->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_swirCamera, 0, 0, 1, 1);


        gridLayout_2->addWidget(groupBox_swirVideo, 1, 1, 1, 1);

        groupBox_rgbVideo = new QGroupBox(centralWidget);
        groupBox_rgbVideo->setObjectName(QStringLiteral("groupBox_rgbVideo"));
        sizePolicy3.setHeightForWidth(groupBox_rgbVideo->sizePolicy().hasHeightForWidth());
        groupBox_rgbVideo->setSizePolicy(sizePolicy3);
        groupBox_rgbVideo->setMaximumSize(QSize(16777215, 16777215));
        groupBox_rgbVideo->setFont(font5);
        gridLayout_4 = new QGridLayout(groupBox_rgbVideo);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        label_rgbCamera = new QLabel(groupBox_rgbVideo);
        label_rgbCamera->setObjectName(QStringLiteral("label_rgbCamera"));
        label_rgbCamera->setFont(font6);
        label_rgbCamera->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(label_rgbCamera, 0, 0, 1, 1);


        gridLayout_2->addWidget(groupBox_rgbVideo, 1, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetFixedSize);
        horizontalLayout->setContentsMargins(200, -1, 0, -1);
        pushButton_startacq = new QPushButton(centralWidget);
        pushButton_startacq->setObjectName(QStringLiteral("pushButton_startacq"));
        QSizePolicy sizePolicy4(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(pushButton_startacq->sizePolicy().hasHeightForWidth());
        pushButton_startacq->setSizePolicy(sizePolicy4);
        pushButton_startacq->setFont(font3);

        horizontalLayout->addWidget(pushButton_startacq);

        pushButton_stopacq = new QPushButton(centralWidget);
        pushButton_stopacq->setObjectName(QStringLiteral("pushButton_stopacq"));
        sizePolicy4.setHeightForWidth(pushButton_stopacq->sizePolicy().hasHeightForWidth());
        pushButton_stopacq->setSizePolicy(sizePolicy4);
        pushButton_stopacq->setFont(font2);

        horizontalLayout->addWidget(pushButton_stopacq);

        pushButton_quit = new QPushButton(centralWidget);
        pushButton_quit->setObjectName(QStringLiteral("pushButton_quit"));
        sizePolicy4.setHeightForWidth(pushButton_quit->sizePolicy().hasHeightForWidth());
        pushButton_quit->setSizePolicy(sizePolicy4);
        pushButton_quit->setFont(font2);

        horizontalLayout->addWidget(pushButton_quit);

        horizontalLayout->setStretch(0, 3);
        horizontalLayout->setStretch(1, 3);
        horizontalLayout->setStretch(2, 3);

        gridLayout_2->addLayout(horizontalLayout, 2, 1, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_collect = new QLabel(centralWidget);
        label_collect->setObjectName(QStringLiteral("label_collect"));
        label_collect->setFont(font2);

        horizontalLayout_2->addWidget(label_collect);

        label_save = new QLabel(centralWidget);
        label_save->setObjectName(QStringLiteral("label_save"));
        label_save->setFont(font2);

        horizontalLayout_2->addWidget(label_save);

        label_total = new QLabel(centralWidget);
        label_total->setObjectName(QStringLiteral("label_total"));
        label_total->setFont(font2);

        horizontalLayout_2->addWidget(label_total);


        gridLayout_2->addLayout(horizontalLayout_2, 2, 0, 1, 1);

        gridLayout_2->setRowStretch(0, 2);
        gridLayout_2->setRowStretch(1, 5);
        gridLayout_2->setRowStretch(2, 1);
        gridLayout_2->setColumnStretch(0, 1);
        gridLayout_2->setColumnStretch(1, 1);

        gridLayout->addLayout(gridLayout_2, 2, 2, 1, 1);

        MainWindowClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindowClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1339, 23));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        MainWindowClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindowClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindowClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindowClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindowClass->setStatusBar(statusBar);

        menuBar->addAction(menu->menuAction());
        menu->addAction(action_initial);
        menu->addAction(action_config);

        retranslateUi(MainWindowClass);

        QMetaObject::connectSlotsByName(MainWindowClass);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindowClass)
    {
        MainWindowClass->setWindowTitle(QApplication::translate("MainWindowClass", "SWIR\347\263\273\347\273\237", Q_NULLPTR));
        action_initial->setText(QApplication::translate("MainWindowClass", "Initialization", Q_NULLPTR));
        action_config->setText(QApplication::translate("MainWindowClass", "Configuration", Q_NULLPTR));
        groupBox_rgbCamera->setTitle(QApplication::translate("MainWindowClass", "RGB Camera", Q_NULLPTR));
        checkBox_preview->setText(QApplication::translate("MainWindowClass", "Preview", Q_NULLPTR));
        pushButton_conn1->setText(QApplication::translate("MainWindowClass", "Connect", Q_NULLPTR));
        pushButton_disconn1->setText(QApplication::translate("MainWindowClass", "Disconnect", Q_NULLPTR));
        pushButton_cap1->setText(QApplication::translate("MainWindowClass", "Capture", Q_NULLPTR));
        label_blank->setText(QString());
        groupBox_swirCamera->setTitle(QApplication::translate("MainWindowClass", "SWIR Camera", Q_NULLPTR));
        groupBox_device->setTitle(QApplication::translate("MainWindowClass", "Device", Q_NULLPTR));
        radioButton_FW->setText(QApplication::translate("MainWindowClass", "FilterWheel", Q_NULLPTR));
        radioButton_LCTF->setText(QApplication::translate("MainWindowClass", "LCTF          ", Q_NULLPTR));
        groupBox_channel->setTitle(QApplication::translate("MainWindowClass", "Channel", Q_NULLPTR));
        label_nm->setText(QApplication::translate("MainWindowClass", "nm", Q_NULLPTR));
        checkBox_preview2->setText(QApplication::translate("MainWindowClass", "Preview", Q_NULLPTR));
        pushButton_conn2->setText(QApplication::translate("MainWindowClass", "Connect", Q_NULLPTR));
        pushButton_disconn2->setText(QApplication::translate("MainWindowClass", "Disconnect", Q_NULLPTR));
        pushButton_cap2->setText(QApplication::translate("MainWindowClass", "Capture", Q_NULLPTR));
        groupBox_swirVideo->setTitle(QApplication::translate("MainWindowClass", "SWIR Camera Video", Q_NULLPTR));
        label_swirCamera->setText(QString());
        groupBox_rgbVideo->setTitle(QApplication::translate("MainWindowClass", "RGB Camera Video", Q_NULLPTR));
        label_rgbCamera->setText(QString());
        pushButton_startacq->setText(QApplication::translate("MainWindowClass", "Acquisition", Q_NULLPTR));
        pushButton_stopacq->setText(QApplication::translate("MainWindowClass", "Stop Acquisiton", Q_NULLPTR));
        pushButton_quit->setText(QApplication::translate("MainWindowClass", "Quit", Q_NULLPTR));
        label_collect->setText(QApplication::translate("MainWindowClass", "Collect Time", Q_NULLPTR));
        label_save->setText(QApplication::translate("MainWindowClass", "Save Time", Q_NULLPTR));
        label_total->setText(QApplication::translate("MainWindowClass", "Total Time", Q_NULLPTR));
        menu->setTitle(QApplication::translate("MainWindowClass", "Menu", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindowClass: public Ui_MainWindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
