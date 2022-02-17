#pragma once
#include <qwidget.h>
#include "AdminController.h"
#include "UserController.h"
#include <qlistwidget.h>
#include <qpushbutton.h>
#include <qlineedit.h>
#include <qlayout.h>
#include <qformlayout.h>
#include <qmessagebox.h>
#include <qlabel.h>
#include "GUI.h"
#include <qwindow.h>
#include <qaction.h>
#include <qurl.h>
#include <qdesktopservices.h>
#include <windows.h>
#include <qtableview.h>
#include "CustomTableModel.h"

class UserGUI : public QWidget
{
private:
	AdminController& ac;
	UserController& uc;
	std::string repoType;

	// graphical elements
	vector<Tutorial> filtered;
	QListWidget* tutorialsListWidget, *watchlistWidget, *filteredTutorialsWidget;
	QLineEdit* titleLineEdit, * presenterLineEdit, * minutesLineEdit, * secondsLineEdit, * likesLineEdit, * linkLineEdit, *searchLineEdit;
	QPushButton* addButton, * deleteButton, *searchButton, *openButton, *openCSV, *openHTML, *showMyListButton;
	QWidget* rateWidget;

	int tutorialsListActive, watchlistActive, filteredActive;
	string tutorialToBeRated;

	CustomTableModel* mylistTableModel;
	QTableView* mylistTableView;

public:
	UserGUI(AdminController& ac, UserController& uc, std::string repoType);

private:
	void initGUIModeUser();
	void populateWatchList();
	void populateList();
	void connectSignalsAndSlots();
	int getSelectedIndexMainList() const;
	int getSelectedIndexWatchList() const;
	int getSelectedIndexFilteredList() const;
	void addTutorialU();
	void deleteTutorialU();
	void showListFiltered();
	void noRate();
	void yesRate();
	void createRateWidget();
	void playOnYoutube();
	void openCSVf();
	void openHTMLf();
	void initializeTableView();
	void showMyList();

};

