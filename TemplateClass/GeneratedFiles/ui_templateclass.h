/********************************************************************************
** Form generated from reading UI file 'templateclass.ui'
**
** Created: Sun Feb 16 15:07:04 2014
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TEMPLATECLASS_H
#define UI_TEMPLATECLASS_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TemplateClassClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *TemplateClassClass)
    {
        if (TemplateClassClass->objectName().isEmpty())
            TemplateClassClass->setObjectName(QString::fromUtf8("TemplateClassClass"));
        TemplateClassClass->resize(600, 400);
        menuBar = new QMenuBar(TemplateClassClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        TemplateClassClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(TemplateClassClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        TemplateClassClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(TemplateClassClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        TemplateClassClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(TemplateClassClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        TemplateClassClass->setStatusBar(statusBar);

        retranslateUi(TemplateClassClass);

        QMetaObject::connectSlotsByName(TemplateClassClass);
    } // setupUi

    void retranslateUi(QMainWindow *TemplateClassClass)
    {
        TemplateClassClass->setWindowTitle(QApplication::translate("TemplateClassClass", "TemplateClass", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class TemplateClassClass: public Ui_TemplateClassClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEMPLATECLASS_H
