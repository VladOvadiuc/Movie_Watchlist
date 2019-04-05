#include "GuiUser.h"

#include <QInputDialog>

GuiUser::GuiUser(Controller& ctrl,QWidget *parent)
	: ctrl{ ctrl },QWidget(parent)
{
	ui.setupUi(this);
	ui.watchList;

	this->elems = this->ctrl.getWatchList()->getMovies();
	this->populateWatchList();

}

GuiUser::~GuiUser()
{
}
void GuiUser::populateWatchList()
{
	if (ui.watchList->count() > 0)
		ui.watchList->clear();
	for (auto m : this->elems)
	{
		QString itemInList = QString::fromStdString(m.getTitle() + " - " +
			m.getGenre() + " - " +
			std::to_string(m.getRelease()) + " - " +
			std::to_string(m.getLikes()) + " - " +
			m.getSource() + " - " +
			std::to_string(m.getDuration()));
		QListWidgetItem *item3 = new QListWidgetItem(itemInList);
		ui.watchList->addItem(item3);
	}
	

	// set the selection on the first item in the list
	if (this->elems.size() > 0)
		ui.watchList->setCurrentRow(0);
}
void GuiUser::on_nextButton_clicked()
{
	this->ctrl.nextMovie();
}

void GuiUser::on_addwButton_clicked()
{
	Movie m = this->ctrl.getRepo().getCurrentMovie();
	this->ctrl.addMovieToWatchList(m);
	this->elems = this->ctrl.getWatchList()->getMovies();
	this->populateWatchList();
}

void GuiUser::on_deletewButton_clicked()
{
	bool ok;
	QString text = QInputDialog::getText(0, "Dialog", "Title:", QLineEdit::Normal, "", &ok);
	std::string input = text.toLocal8Bit().constData();
	Movie m = this->ctrl.findMovie(input);
	if (m.getTitle() == "")
	{
		QMessageBox msg;
		msg.critical(0, "ERROR", "Invalid data!");
		
		return;
	}
	QMessageBox msgBox;
	msgBox.setText("Did you liked it?");
	QPushButton *yesButton = msgBox.addButton("Yes", QMessageBox::ActionRole);
	QPushButton *noButton = msgBox.addButton("NO", QMessageBox::ActionRole);
	msgBox.exec();
	if (msgBox.clickedButton() == yesButton) {
		Movie old = this->ctrl.findMovie(m.getTitle());
		Movie nou{ m.getTitle(), m.getGenre(), m.getRelease(), m.getLikes() + 1, m.getSource(), m.getDuration() };
		this->ctrl.update(old, nou);

		//this->ctrl.update(m.getTitle(), m.getGenre(), m.getRelease(), m.getLikes()+1, m.getSource(), m.getDuration());
		this->ctrl.deleteMovieWatchList(m.getTitle());
		this->elems = this->ctrl.getWatchList()->getMovies();
		this->populateWatchList();
	}
	else {


		this->ctrl.deleteMovieWatchList(m.getTitle());
		this->elems = this->ctrl.getWatchList()->getMovies();
		this->populateWatchList();
	}
}

void GuiUser::on_displayButton_clicked()
{
	this->ctrl.openWatchList();
}

void GuiUser::on_saveButton_clicked()
{
	this->ctrl.saveWatchList();
}

void GuiUser::on_playButton_clicked()
{
	this->ctrl.start();
}