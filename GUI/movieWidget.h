#pragma once

#include <QWidget>
#include "ui_movieWidget.h"
#include "Repository.h"

class movieWidget : public QWidget
{
	Q_OBJECT

public:
	movieWidget(Repository & repo, QAbstractItemModel* model, QWidget *parent = 0);
	~movieWidget();

private:
	Ui::movieWidget ui; 
	Repository & repo;
	QAbstractItemModel* model;
};
