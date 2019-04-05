/********************************************************************************
** Form generated from reading UI file 'lab11.ui'
**
** Created by: Qt User Interface Compiler version 5.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LAB11_H
#define UI_LAB11_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_lab11Class
{
public:
    QWidget *centralWidget;
    QPushButton *pushButton;
    QTextBrowser *textBrowser;
    QLabel *label;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *lab11Class)
    {
        if (lab11Class->objectName().isEmpty())
            lab11Class->setObjectName(QStringLiteral("lab11Class"));
        lab11Class->resize(600, 400);
        centralWidget = new QWidget(lab11Class);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(80, 130, 56, 17));
        textBrowser = new QTextBrowser(centralWidget);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setGeometry(QRect(60, 160, 256, 192));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(60, 70, 35, 10));
        lab11Class->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(lab11Class);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 18));
        lab11Class->setMenuBar(menuBar);
        mainToolBar = new QToolBar(lab11Class);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        lab11Class->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(lab11Class);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        lab11Class->setStatusBar(statusBar);

        retranslateUi(lab11Class);

        QMetaObject::connectSlotsByName(lab11Class);
    } // setupUi

    void retranslateUi(QMainWindow *lab11Class)
    {
        lab11Class->setWindowTitle(QApplication::translate("lab11Class", "lab11", nullptr));
        pushButton->setText(QApplication::translate("lab11Class", "PushButton", nullptr));
        label->setText(QApplication::translate("lab11Class", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class lab11Class: public Ui_lab11Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LAB11_H
