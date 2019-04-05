#include "movieWidget.h"

movieWidget::movieWidget(Repository& repo, QAbstractItemModel* model, QWidget *parent)
	: QWidget(parent), repo{ repo }, model{ model }
{
	ui.setupUi(this);
	this->ui.movieTableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

	this->ui.movieTableView->setModel(this->model);
	
}

movieWidget::~movieWidget()
{
}
