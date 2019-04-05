#pragma once

#include <QWidget>
#include "ui_GuiAdmin.h"
#include "Controller.h"
#include "Movie.h"
#include "RepositoryExceptions.h"
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

class GuiAdmin : public QWidget
{
	Q_OBJECT

public:
	GuiAdmin(Controller& c,QWidget *parent = 0);
	~GuiAdmin();

private:
	Ui::GuiAdmin ui;
	Controller& ctrl;
	std::vector<Movie> elemsRepo;
	void populateRepo();
	void populateRepoShort();
private slots:
	void on_addButton_clicked();
	void on_detailComboBox_currentTextChanged();
	void on_removeButton_clicked();
	void on_updateButton_clicked();
	void on_filterButton_clicked();
	void on_undoButton_clicked();
	void on_redoButton_clicked();
};
