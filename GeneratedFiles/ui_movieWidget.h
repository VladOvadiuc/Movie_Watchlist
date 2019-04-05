/********************************************************************************
** Form generated from reading UI file 'movieWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MOVIEWIDGET_H
#define UI_MOVIEWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_movieWidget
{
public:
    QTableView *movieTableView;

    void setupUi(QWidget *movieWidget)
    {
        if (movieWidget->objectName().isEmpty())
            movieWidget->setObjectName(QStringLiteral("movieWidget"));
        movieWidget->resize(565, 372);
        movieTableView = new QTableView(movieWidget);
        movieTableView->setObjectName(QStringLiteral("movieTableView"));
        movieTableView->setGeometry(QRect(10, 10, 531, 341));

        retranslateUi(movieWidget);

        QMetaObject::connectSlotsByName(movieWidget);
    } // setupUi

    void retranslateUi(QWidget *movieWidget)
    {
        movieWidget->setWindowTitle(QApplication::translate("movieWidget", "movieWidget", nullptr));
    } // retranslateUi

};

namespace Ui {
    class movieWidget: public Ui_movieWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MOVIEWIDGET_H
