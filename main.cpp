#include "Lab11.h"
#include  "GuiAdmin.h"
#include "GuiUser.h"

#include <QtWidgets/QApplication>
#include "CSVRepository.h"
#include "CSVWAtchlist.h"
#include "HTMLWatchList.h"
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
#include <string>
#include <iostream>
#include <QInputDialog>
#include <qwidget.h>
#include "MovieTableModel.h"
#include "movieWidget.h"
int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Repository repo{ "Movies.txt" };
	MovieValidator val;
	
	QMessageBox msgBox;
	msgBox.setText("What do you want to be?");
	QPushButton *userButton = msgBox.addButton("User", QMessageBox::ActionRole);
	QPushButton *adminButton = msgBox.addButton("Admin", QMessageBox::ActionRole);
	msgBox.exec();
	if (msgBox.clickedButton() == adminButton) {
		HTMLWatchList* hw = new HTMLWatchList{ "watchlist.htm" };
		Controller ctrl{ repo,hw,val };
		GuiAdmin ga(ctrl);
		MovieTableModel* tableModel = new MovieTableModel{ repo };
		movieWidget widget{ repo,tableModel };
		widget.show();
		ga.show();
		return a.exec();
	}
	if (msgBox.clickedButton() == userButton) {
		QMessageBox msg;
		msg.setText("What type of file do you want?");
		QPushButton *csvButton = msg.addButton("CSV", QMessageBox::ActionRole);
		QPushButton *htmlButton = msg.addButton("HTML", QMessageBox::ActionRole);
		msg.exec();
		if (msg.clickedButton() == htmlButton) {
			HTMLWatchList* hw = new HTMLWatchList{ "watchlist.htm" };
			Controller ctrl{ repo,hw,val };
			GuiUser ga(ctrl);
			
			
			ga.show();
			return a.exec();
		}
		if (msg.clickedButton() == csvButton) {
			CSVWatchList* hw = new CSVWatchList{ "watchlist.csv" };
			Controller ctrl{ repo,hw,val };
			GuiUser ga(ctrl);
			MovieTableModel* tableModel = new MovieTableModel{ repo };
			movieWidget widget{ repo,tableModel };
			widget.show();
			ga.show();
			return a.exec();
		}

	}
	
	
	return a.exec();
}
