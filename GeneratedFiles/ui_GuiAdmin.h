/********************************************************************************
** Form generated from reading UI file 'GuiAdmin.ui'
**
** Created by: Qt User Interface Compiler version 5.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GUIADMIN_H
#define UI_GUIADMIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GuiAdmin
{
public:
    QListWidget *repoList;
    QPushButton *addButton;
    QPushButton *removeButton;
    QPushButton *updateButton;
    QSplitter *splitter;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *title;
    QLineEdit *titleEdit;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_2;
    QLabel *genre;
    QLineEdit *genreEdit;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *year;
    QLineEdit *yearEdit;
    QWidget *layoutWidget3;
    QHBoxLayout *horizontalLayout_4;
    QLabel *likes;
    QLineEdit *likesEdit;
    QWidget *layoutWidget4;
    QHBoxLayout *horizontalLayout_5;
    QLabel *link;
    QLineEdit *linkEdit;
    QWidget *layoutWidget5;
    QHBoxLayout *horizontalLayout_6;
    QLabel *duration;
    QLineEdit *durationEdit;
    QComboBox *detailComboBox;
    QPushButton *filterButton;
    QPushButton *undoButton;
    QPushButton *redoButton;

    void setupUi(QWidget *GuiAdmin)
    {
        if (GuiAdmin->objectName().isEmpty())
            GuiAdmin->setObjectName(QStringLiteral("GuiAdmin"));
        GuiAdmin->resize(748, 707);
        repoList = new QListWidget(GuiAdmin);
        repoList->setObjectName(QStringLiteral("repoList"));
        repoList->setGeometry(QRect(20, 10, 711, 451));
        addButton = new QPushButton(GuiAdmin);
        addButton->setObjectName(QStringLiteral("addButton"));
        addButton->setGeometry(QRect(410, 510, 91, 41));
        removeButton = new QPushButton(GuiAdmin);
        removeButton->setObjectName(QStringLiteral("removeButton"));
        removeButton->setGeometry(QRect(410, 580, 91, 41));
        updateButton = new QPushButton(GuiAdmin);
        updateButton->setObjectName(QStringLiteral("updateButton"));
        updateButton->setGeometry(QRect(410, 650, 91, 41));
        splitter = new QSplitter(GuiAdmin);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setGeometry(QRect(20, 470, 371, 221));
        splitter->setOrientation(Qt::Vertical);
        layoutWidget = new QWidget(splitter);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        title = new QLabel(layoutWidget);
        title->setObjectName(QStringLiteral("title"));

        horizontalLayout->addWidget(title);

        titleEdit = new QLineEdit(layoutWidget);
        titleEdit->setObjectName(QStringLiteral("titleEdit"));

        horizontalLayout->addWidget(titleEdit);

        splitter->addWidget(layoutWidget);
        layoutWidget1 = new QWidget(splitter);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        genre = new QLabel(layoutWidget1);
        genre->setObjectName(QStringLiteral("genre"));

        horizontalLayout_2->addWidget(genre);

        genreEdit = new QLineEdit(layoutWidget1);
        genreEdit->setObjectName(QStringLiteral("genreEdit"));

        horizontalLayout_2->addWidget(genreEdit);

        splitter->addWidget(layoutWidget1);
        layoutWidget2 = new QWidget(splitter);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        year = new QLabel(layoutWidget2);
        year->setObjectName(QStringLiteral("year"));

        horizontalLayout_3->addWidget(year);

        yearEdit = new QLineEdit(layoutWidget2);
        yearEdit->setObjectName(QStringLiteral("yearEdit"));

        horizontalLayout_3->addWidget(yearEdit);

        splitter->addWidget(layoutWidget2);
        layoutWidget3 = new QWidget(splitter);
        layoutWidget3->setObjectName(QStringLiteral("layoutWidget3"));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget3);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        likes = new QLabel(layoutWidget3);
        likes->setObjectName(QStringLiteral("likes"));

        horizontalLayout_4->addWidget(likes);

        likesEdit = new QLineEdit(layoutWidget3);
        likesEdit->setObjectName(QStringLiteral("likesEdit"));

        horizontalLayout_4->addWidget(likesEdit);

        splitter->addWidget(layoutWidget3);
        layoutWidget4 = new QWidget(splitter);
        layoutWidget4->setObjectName(QStringLiteral("layoutWidget4"));
        horizontalLayout_5 = new QHBoxLayout(layoutWidget4);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        link = new QLabel(layoutWidget4);
        link->setObjectName(QStringLiteral("link"));

        horizontalLayout_5->addWidget(link);

        linkEdit = new QLineEdit(layoutWidget4);
        linkEdit->setObjectName(QStringLiteral("linkEdit"));

        horizontalLayout_5->addWidget(linkEdit);

        splitter->addWidget(layoutWidget4);
        layoutWidget5 = new QWidget(splitter);
        layoutWidget5->setObjectName(QStringLiteral("layoutWidget5"));
        horizontalLayout_6 = new QHBoxLayout(layoutWidget5);
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        duration = new QLabel(layoutWidget5);
        duration->setObjectName(QStringLiteral("duration"));

        horizontalLayout_6->addWidget(duration);

        durationEdit = new QLineEdit(layoutWidget5);
        durationEdit->setObjectName(QStringLiteral("durationEdit"));

        horizontalLayout_6->addWidget(durationEdit);

        splitter->addWidget(layoutWidget5);
        detailComboBox = new QComboBox(GuiAdmin);
        detailComboBox->addItem(QString());
        detailComboBox->addItem(QString());
        detailComboBox->setObjectName(QStringLiteral("detailComboBox"));
        detailComboBox->setGeometry(QRect(420, 470, 301, 22));
        filterButton = new QPushButton(GuiAdmin);
        filterButton->setObjectName(QStringLiteral("filterButton"));
        filterButton->setGeometry(QRect(600, 510, 91, 41));
        undoButton = new QPushButton(GuiAdmin);
        undoButton->setObjectName(QStringLiteral("undoButton"));
        undoButton->setGeometry(QRect(600, 580, 91, 41));
        redoButton = new QPushButton(GuiAdmin);
        redoButton->setObjectName(QStringLiteral("redoButton"));
        redoButton->setGeometry(QRect(600, 650, 91, 41));

        retranslateUi(GuiAdmin);

        QMetaObject::connectSlotsByName(GuiAdmin);
    } // setupUi

    void retranslateUi(QWidget *GuiAdmin)
    {
        GuiAdmin->setWindowTitle(QApplication::translate("GuiAdmin", "GuiAdmin", nullptr));
        addButton->setText(QApplication::translate("GuiAdmin", "Add", nullptr));
        removeButton->setText(QApplication::translate("GuiAdmin", "Remove", nullptr));
        updateButton->setText(QApplication::translate("GuiAdmin", "Update", nullptr));
        title->setText(QApplication::translate("GuiAdmin", "Title", nullptr));
        genre->setText(QApplication::translate("GuiAdmin", "Genre", nullptr));
        year->setText(QApplication::translate("GuiAdmin", "Year", nullptr));
        likes->setText(QApplication::translate("GuiAdmin", "Likes", nullptr));
        link->setText(QApplication::translate("GuiAdmin", "Link", nullptr));
        duration->setText(QApplication::translate("GuiAdmin", "Duration", nullptr));
        detailComboBox->setItemText(0, QApplication::translate("GuiAdmin", "Detailed", nullptr));
        detailComboBox->setItemText(1, QApplication::translate("GuiAdmin", "Short", nullptr));

        filterButton->setText(QApplication::translate("GuiAdmin", "Filter", nullptr));
        undoButton->setText(QApplication::translate("GuiAdmin", "Undo", nullptr));
        redoButton->setText(QApplication::translate("GuiAdmin", "Redo", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GuiAdmin: public Ui_GuiAdmin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GUIADMIN_H
