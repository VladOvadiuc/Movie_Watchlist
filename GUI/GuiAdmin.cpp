#include "GuiAdmin.h"
#include <string>
#include <iostream>
#include <QInputDialog>

GuiAdmin::GuiAdmin(Controller& ctrl, QWidget *parent)
	:ctrl(ctrl), QWidget(parent)
{
	ui.setupUi(this);
	ui.repoList;
	this->elemsRepo = this->ctrl.getRepo().getMovies();
	this->populateRepo();
}

GuiAdmin::~GuiAdmin()
{
}

void GuiAdmin::populateRepo()
{
	if (ui.repoList->count() > 0)
		ui.repoList->clear();
	for (auto m : this->elemsRepo)
	{
		QString itemInList = QString::fromStdString(m.getTitle() + " - " + 
													m.getGenre() + " - " + 
													std::to_string(m.getRelease()) + " - " + 
													std::to_string(m.getLikes()) + " - " + 
													m.getSource() + " - " + 
													std::to_string(m.getDuration()));
		QListWidgetItem *item3 = new QListWidgetItem(itemInList);
		ui.repoList->addItem(item3);
	}
	ui.titleEdit->clear();
	ui.genreEdit->clear();
	ui.yearEdit->clear();
	ui.likesEdit->clear();
	ui.linkEdit->clear();
	ui.durationEdit->clear();

	// set the selection on the first item in the list
	if (this->elemsRepo.size() > 0)
		ui.repoList->setCurrentRow(0);
}

void GuiAdmin::populateRepoShort()
{
	if (ui.repoList->count() > 0)
		ui.repoList->clear();
	for (auto m : this->elemsRepo)
	{
		QString itemInList = QString::fromStdString(m.getTitle() + " - " +
			m.getGenre() + " - " +
			std::to_string(m.getRelease()) );
		QListWidgetItem *item3 = new QListWidgetItem(itemInList);
		ui.repoList->addItem(item3);
	}
	ui.titleEdit->clear();
	ui.genreEdit->clear();
	ui.yearEdit->clear();
	ui.likesEdit->clear();
	ui.linkEdit->clear();
	ui.durationEdit->clear();

	// set the selection on the first item in the list
	if (this->elemsRepo.size() > 0)
		ui.repoList->setCurrentRow(0);
}

void GuiAdmin::on_detailComboBox_currentTextChanged()
{
	if (ui.detailComboBox->currentText().toStdString() == "Detailed")
		this->populateRepo();
	else if (ui.detailComboBox->currentText().toStdString() == "Short")
		this->populateRepoShort();

}

void GuiAdmin::on_removeButton_clicked()
{
	std::string title= ui.titleEdit->text().toStdString();
	if (this->ctrl.deleteMovieRepo(title) == 1) {
		QMessageBox msg;
		msg.information(0, "Done", "The movie was deleted!");
		this->elemsRepo = this->ctrl.getRepo().getMovies();
		this->populateRepo();
		ui.titleEdit->clear();
	}
	else {
		QMessageBox msg;
		msg.critical(0, "ERROR", "Couldn't delete it!");
	}
}

void GuiAdmin::on_updateButton_clicked()
{
	std::string title = ui.titleEdit->text().toStdString();
	if (ui.titleEdit->text().toStdString() == "") {
		QMessageBox msg;
		msg.critical(0, "ERROR", "No data!");
		ui.titleEdit->clear();
		return;
	}
	Movie m = this->ctrl.findMovie(title);
	if (m.getTitle() == "")
	{
		QMessageBox msg;
		msg.critical(0, "ERROR", "Invalid data!");
		ui.titleEdit->clear();
		return;
	}
	Movie old = this->ctrl.findMovie(title);
	QMessageBox msgBox;
	msgBox.setText("What do you want to update?");
	QPushButton *genreButton = msgBox.addButton(tr("Genre"), QMessageBox::ActionRole);
	QPushButton *yearButton = msgBox.addButton(tr("Year"), QMessageBox::ActionRole);
	QPushButton *likesButton = msgBox.addButton(tr("Likes"), QMessageBox::ActionRole);
	QPushButton *linkButton = msgBox.addButton(tr("Link"), QMessageBox::ActionRole);
	QPushButton *durationButton = msgBox.addButton(tr("Duration"), QMessageBox::ActionRole);
	QPushButton *abortButton = msgBox.addButton(QMessageBox::Abort);

	msgBox.exec();
	try {


		if (msgBox.clickedButton() == genreButton) {
			bool ok;
			QString text = QInputDialog::getText(0, "Dialog", "Genre:", QLineEdit::Normal, "", &ok);
			std::string input = text.toLocal8Bit().constData();
			
			Movie nou{ title, input, m.getRelease(), m.getLikes(), m.getSource(), m.getDuration() };
			this->ctrl.update(old,nou);
			QMessageBox msg;
			msg.information(0, "Done", "The movie was updated!");
			this->elemsRepo = this->ctrl.getRepo().getMovies();
			this->populateRepo();
			ui.titleEdit->clear();
		}
		if (msgBox.clickedButton() == yearButton) {
			bool ok;
			QString text = QInputDialog::getText(0, "Dialog", "Year:", QLineEdit::Normal, "", &ok);
			std::string input = text.toLocal8Bit().constData();
			Movie nou{ m.getTitle(), m.getGenre(), stoi(input), m.getLikes(), m.getSource(), m.getDuration() };
			this->ctrl.update(old, nou);
			QMessageBox msg;
			msg.information(0, "Done", "The movie was updated!");
			this->elemsRepo = this->ctrl.getRepo().getMovies();
			this->populateRepo();
			ui.titleEdit->clear();
		}
		if (msgBox.clickedButton() == likesButton) {
			bool ok;
			QString text = QInputDialog::getText(0, "Dialog", "Likes:", QLineEdit::Normal, "", &ok);
			std::string input = text.toLocal8Bit().constData();
			Movie nou{ m.getTitle(), m.getGenre(), m.getRelease(), stoi(input), m.getSource(), m.getDuration() };
			this->ctrl.update(old, nou);
			QMessageBox msg;
			msg.information(0, "Done", "The movie was updated!");
			this->elemsRepo = this->ctrl.getRepo().getMovies();
			this->populateRepo();
			ui.titleEdit->clear();
		}
		if (msgBox.clickedButton() == linkButton) {
			bool ok;
			QString text = QInputDialog::getText(0, "Dialog", "Link:", QLineEdit::Normal, "", &ok);
			std::string input = text.toLocal8Bit().constData();
			Movie nou{ m.getTitle(), m.getGenre(), m.getRelease(), m.getLikes(), input, m.getDuration() };
			this->ctrl.update(old, nou);
			QMessageBox msg;
			msg.information(0, "Done", "The movie was updated!");
			this->elemsRepo = this->ctrl.getRepo().getMovies();
			this->populateRepo();
			ui.titleEdit->clear();
		}
		if (msgBox.clickedButton() == durationButton) {
			bool ok;
			QString text = QInputDialog::getText(0, "Dialog", "Duration:", QLineEdit::Normal, "", &ok);
			std::string input = text.toLocal8Bit().constData();
			Movie nou{ m.getTitle(), m.getGenre(), m.getRelease(), m.getLikes(), m.getSource(), stoi(input) };
			this->ctrl.update(old, nou);
			QMessageBox msg;
			msg.information(0, "Done", "The movie was updated!");
			this->elemsRepo = this->ctrl.getRepo().getMovies();
			this->populateRepo();
			ui.titleEdit->clear();
		}
	}
	catch (MovieException& e)
	{
		QMessageBox msg;
		std::string errors="";
		for (auto s : e.getErrors())
			errors += s, errors += "\n";
		QString qstr = QString::fromStdString(errors);
		msg.critical(0, "ERROR", qstr);
	}

}

void GuiAdmin::on_filterButton_clicked()
{
	QListWidget* filterRepo = new QListWidget;
	filterRepo->resize(700, 500);
	if (filterRepo->count() > 0)
		filterRepo->clear();
	bool ok;
	QString text = QInputDialog::getText(0, "Dialog", "Duration:", QLineEdit::Normal, "", &ok);
	std::string input = text.toLocal8Bit().constData();
	int duration = stoi(input);
	for (auto m : this->elemsRepo)
	{
		if (m < duration) {
			QString itemInList = QString::fromStdString(m.getTitle() + " - " +
				m.getGenre() + " - " +
				std::to_string(m.getRelease()) + " - " +
				std::to_string(m.getDuration()));
			QListWidgetItem *item3 = new QListWidgetItem(itemInList);
			filterRepo->addItem(item3);
		}
	}


	// set the selection on the first item in the list
	if (this->elemsRepo.size() > 0)
		filterRepo->setCurrentRow(0);
	filterRepo->show();
	
}

void GuiAdmin::on_undoButton_clicked()
{
	try {

		this->ctrl.undo(); 
		this->elemsRepo = this->ctrl.getRepo().getMovies();
		this->populateRepo();
	}
	catch (RepositoryException e)
	{
		QMessageBox msg;
		msg.critical(0, "ERROR", "No undo");
	}
}
void GuiAdmin::on_redoButton_clicked()
{
	try {

		this->ctrl.redo();
		this->elemsRepo = this->ctrl.getRepo().getMovies();
		this->populateRepo();
	}
	catch (RepositoryException e)
	{
		QMessageBox msg;
		msg.critical(0, "ERROR", "No redo");
	}
}

void GuiAdmin::on_addButton_clicked()
{
	if (ui.genreEdit->text().toStdString() == "" ||
		ui.titleEdit->text().toStdString() == "" ||
		ui.likesEdit->text().toStdString() == "" ||
		ui.yearEdit->text().toStdString() == "" ||
		ui.linkEdit->text().toStdString() == "" ||
		ui.durationEdit->text().toStdString() == "")
	{
		QMessageBox msg;
		msg.critical(0, "ERROR", "No input data");
	}
	else
	{
		std::string title = ui.titleEdit->text().toStdString();
		std::string genre = ui.genreEdit->text().toStdString();
		std::string link = ui.linkEdit->text().toStdString();
		int year = stoi(ui.yearEdit->text().toStdString());
		int likes = stoi(ui.likesEdit->text().toStdString());
		int duration = stoi(ui.durationEdit->text().toStdString());
		try
		{
			this->ctrl.addMovieToRepository(title, genre, year, likes, link, duration);
			// refresh the list
			this->elemsRepo = this->ctrl.getRepo().getMovies();
			this->populateRepo();
		}
		catch (MovieException& e)
		{
			QMessageBox msg;
			std::string errors = "";
			for (auto s : e.getErrors())
				errors += s, errors += "\n";
			QString qstr = QString::fromStdString(errors);
			msg.critical(0, "ERROR", qstr);
			ui.titleEdit->clear();
			ui.genreEdit->clear();
			ui.yearEdit->clear();
			ui.likesEdit->clear();
			ui.linkEdit->clear();
			ui.durationEdit->clear();

		}
		catch (DuplicateMovieException& e)
		{
		QMessageBox messageBox;
		messageBox.critical(0, "Error", "Duplicate elements!");
		ui.titleEdit->clear();
		ui.genreEdit->clear();
		ui.yearEdit->clear();
		ui.likesEdit->clear();
		ui.linkEdit->clear();
		ui.durationEdit->clear();
		}
	}
}