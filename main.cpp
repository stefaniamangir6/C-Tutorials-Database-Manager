#include "assignment89TutorialsGUI.h"
#include <QtWidgets/QApplication>
#include <stdlib.h>
#include <stdio.h>
#include "tests.h"
#include "FileRepository.h"
#include "FileWatchlist.h"
#include "CSVRepository.h"
#include "CSVWatchlist.h"
#include "HTMLRepository.h"
#include "HTMLWatchlist.h"
#include <memory>
#include "GUI.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

	std::string repoType;
	QMessageBox msgBox;
	QPushButton* fileButton = msgBox.addButton(("TXT"), QMessageBox::ActionRole);
	QPushButton* csvButton = msgBox.addButton(("CSV"), QMessageBox::ActionRole);
	QPushButton* htmlButton = msgBox.addButton(("HTML"), QMessageBox::ActionRole);

	msgBox.setText("Choose the type of files you want to work with");
	msgBox.exec();

	if (msgBox.clickedButton() == fileButton)
	{
		Validator valid;
		FileWatchlist frepo("watchlist.txt");
		FileRepo fileRepo("tutorials_in.txt");
		AdminController ac = AdminController(fileRepo, valid);
		UserController uc = UserController(fileRepo, frepo);
		repoType = "txt";
		GUI gui{ ac, uc, repoType };
		gui.show();
		return a.exec();

	}
	else if (msgBox.clickedButton() == csvButton)
	{
		Validator valid;
		CSVRepo repo("Tutorials.csv");
		CSVWatchlist watchlist("Watchlist.csv");
		AdminController ac = AdminController(repo, valid);
		UserController uc = UserController(repo, watchlist);
		repoType = "csv";
		GUI gui{ ac, uc, repoType };
		gui.show();
		return a.exec();
	}
	else if (msgBox.clickedButton() == htmlButton)
	{
		Validator valid;
		HTMLWatchlist hrepo("Watchlistt.html");
		HTMLRepo hRepo("Tutorials.html");
		AdminController ac = AdminController(hRepo, valid);
		UserController uc = UserController(hRepo, hrepo);
		repoType = "html";
		GUI gui{ ac, uc, repoType };
		gui.show();
		return a.exec();
	}

}
