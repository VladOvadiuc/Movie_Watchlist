/********************************************************************************
** Form generated from reading UI file 'GuiUser.ui'
**
** Created by: Qt User Interface Compiler version 5.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GUIUSER_H
#define UI_GUIUSER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GuiUser
{
public:
    QListWidget *watchList;
    QPushButton *playButton;
    QPushButton *nextButton;
    QPushButton *addwButton;
    QPushButton *deletewButton;
    QPushButton *displayButton;
    QPushButton *saveButton;

    void setupUi(QWidget *GuiUser)
    {
        if (GuiUser->objectName().isEmpty())
            GuiUser->setObjectName(QStringLiteral("GuiUser"));
        GuiUser->resize(606, 387);
        watchList = new QListWidget(GuiUser);
        watchList->setObjectName(QStringLiteral("watchList"));
        watchList->setGeometry(QRect(20, 10, 571, 192));
        playButton = new QPushButton(GuiUser);
        playButton->setObjectName(QStringLiteral("playButton"));
        playButton->setGeometry(QRect(20, 230, 61, 31));
        nextButton = new QPushButton(GuiUser);
        nextButton->setObjectName(QStringLiteral("nextButton"));
        nextButton->setGeometry(QRect(100, 230, 61, 31));
        addwButton = new QPushButton(GuiUser);
        addwButton->setObjectName(QStringLiteral("addwButton"));
        addwButton->setGeometry(QRect(180, 230, 71, 31));
        deletewButton = new QPushButton(GuiUser);
        deletewButton->setObjectName(QStringLiteral("deletewButton"));
        deletewButton->setGeometry(QRect(270, 230, 71, 31));
        displayButton = new QPushButton(GuiUser);
        displayButton->setObjectName(QStringLiteral("displayButton"));
        displayButton->setGeometry(QRect(360, 230, 71, 31));
        saveButton = new QPushButton(GuiUser);
        saveButton->setObjectName(QStringLiteral("saveButton"));
        saveButton->setGeometry(QRect(450, 230, 81, 31));

        retranslateUi(GuiUser);

        QMetaObject::connectSlotsByName(GuiUser);
    } // setupUi

    void retranslateUi(QWidget *GuiUser)
    {
        GuiUser->setWindowTitle(QApplication::translate("GuiUser", "GuiUser", nullptr));
        playButton->setText(QApplication::translate("GuiUser", "Play", nullptr));
        nextButton->setText(QApplication::translate("GuiUser", "Next", nullptr));
        addwButton->setText(QApplication::translate("GuiUser", "Add", nullptr));
        deletewButton->setText(QApplication::translate("GuiUser", "Delete", nullptr));
        displayButton->setText(QApplication::translate("GuiUser", "Display", nullptr));
        saveButton->setText(QApplication::translate("GuiUser", "Save", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GuiUser: public Ui_GuiUser {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GUIUSER_H
