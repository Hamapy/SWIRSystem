/********************************************************************************
** Form generated from reading UI file 'configuration.ui'
**
** Created by: Qt User Interface Compiler version 5.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONFIGURATION_H
#define UI_CONFIGURATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ConfigurationClass
{
public:
    QLabel *label_affine;
    QLineEdit *lineEdit_affine;
    QPushButton *pushButton_save;
    QPushButton *pushButton_defaults;
    QLineEdit *lineEdit_framerate;
    QLabel *label_framerate;
    QLabel *label_savepath;
    QLineEdit *lineEdit_savepath;
    QLabel *label_acqf;
    QLineEdit *lineEdit_acqf;

    void setupUi(QWidget *ConfigurationClass)
    {
        if (ConfigurationClass->objectName().isEmpty())
            ConfigurationClass->setObjectName(QStringLiteral("ConfigurationClass"));
        ConfigurationClass->resize(580, 355);
        label_affine = new QLabel(ConfigurationClass);
        label_affine->setObjectName(QStringLiteral("label_affine"));
        label_affine->setGeometry(QRect(30, 30, 111, 16));
        QFont font;
        font.setFamily(QStringLiteral("Times New Roman"));
        font.setPointSize(12);
        label_affine->setFont(font);
        lineEdit_affine = new QLineEdit(ConfigurationClass);
        lineEdit_affine->setObjectName(QStringLiteral("lineEdit_affine"));
        lineEdit_affine->setGeometry(QRect(182, 30, 191, 20));
        pushButton_save = new QPushButton(ConfigurationClass);
        pushButton_save->setObjectName(QStringLiteral("pushButton_save"));
        pushButton_save->setGeometry(QRect(360, 290, 75, 23));
        pushButton_save->setFont(font);
        pushButton_defaults = new QPushButton(ConfigurationClass);
        pushButton_defaults->setObjectName(QStringLiteral("pushButton_defaults"));
        pushButton_defaults->setGeometry(QRect(450, 290, 75, 23));
        pushButton_defaults->setFont(font);
        lineEdit_framerate = new QLineEdit(ConfigurationClass);
        lineEdit_framerate->setObjectName(QStringLiteral("lineEdit_framerate"));
        lineEdit_framerate->setGeometry(QRect(182, 60, 191, 20));
        label_framerate = new QLabel(ConfigurationClass);
        label_framerate->setObjectName(QStringLiteral("label_framerate"));
        label_framerate->setGeometry(QRect(30, 60, 111, 16));
        label_framerate->setFont(font);
        label_savepath = new QLabel(ConfigurationClass);
        label_savepath->setObjectName(QStringLiteral("label_savepath"));
        label_savepath->setGeometry(QRect(30, 90, 111, 16));
        label_savepath->setFont(font);
        lineEdit_savepath = new QLineEdit(ConfigurationClass);
        lineEdit_savepath->setObjectName(QStringLiteral("lineEdit_savepath"));
        lineEdit_savepath->setGeometry(QRect(180, 90, 191, 20));
        label_acqf = new QLabel(ConfigurationClass);
        label_acqf->setObjectName(QStringLiteral("label_acqf"));
        label_acqf->setGeometry(QRect(30, 120, 141, 16));
        label_acqf->setFont(font);
        lineEdit_acqf = new QLineEdit(ConfigurationClass);
        lineEdit_acqf->setObjectName(QStringLiteral("lineEdit_acqf"));
        lineEdit_acqf->setGeometry(QRect(180, 120, 191, 20));

        retranslateUi(ConfigurationClass);

        QMetaObject::connectSlotsByName(ConfigurationClass);
    } // setupUi

    void retranslateUi(QWidget *ConfigurationClass)
    {
        ConfigurationClass->setWindowTitle(QApplication::translate("ConfigurationClass", "Configuration", Q_NULLPTR));
        label_affine->setText(QApplication::translate("ConfigurationClass", "Affine Coefficient", Q_NULLPTR));
        pushButton_save->setText(QApplication::translate("ConfigurationClass", "Save", Q_NULLPTR));
        pushButton_defaults->setText(QApplication::translate("ConfigurationClass", "Defaults", Q_NULLPTR));
        label_framerate->setText(QApplication::translate("ConfigurationClass", "Frame Rate", Q_NULLPTR));
        label_savepath->setText(QApplication::translate("ConfigurationClass", "Save Path", Q_NULLPTR));
        label_acqf->setText(QApplication::translate("ConfigurationClass", "Acquisition Frequency", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ConfigurationClass: public Ui_ConfigurationClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONFIGURATION_H
