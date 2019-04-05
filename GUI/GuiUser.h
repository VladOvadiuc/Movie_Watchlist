#pragma once

#include <QWidget>
#include "ui_GuiUser.h"
#include "Controller.h"
#include "WatchList.h"
#include "Movie.h"
#include <QtWidgets/qmainwindow.h>
#include <QtWidgets/qlistwidget.h>
#include <QtWidgets/qboxlayout.h>
#include <QtWidgets/qlineedit.h>
#include <QtWidgets/qformlayout.h>
#include <QtWidgets/qlabel.h>
#include <QtWidgets/qpushbutton.h>
#include <QtWidgets/qradiobutton.h>
#include <QtWidgets/qmessagebox.h>
#include <QtWidgets/qbuttongroup.h>

class GuiUser : public QWidget
{
	Q_OBJECT

public:
	GuiUser(Controller& ctrl,QWidget *parent =0);
	~GuiUser();

	void populateWatchList();

private:
	Ui::GuiUser ui;
	Controller& ctrl;
	std::vector<Movie> elems;
private slots:
	void on_playButton_clicked();
	void on_nextButton_clicked();
	void on_addwButton_clicked();
	void on_deletewButton_clicked();
	void on_displayButton_clicked();
	void on_saveButton_clicked();
};
