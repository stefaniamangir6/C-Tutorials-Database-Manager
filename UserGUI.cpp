#include "UserGUI.h"

UserGUI::UserGUI(AdminController& ac, UserController& uc, std::string repoType) : ac{ ac }, uc{ uc }, repoType{repoType}
{
	this->setWindowTitle("USER");
	this->initGUIModeUser();
	this->populateWatchList();
	this->populateList();
	this->connectSignalsAndSlots();
}

void UserGUI::initializeTableView() {
	this->mylistTableModel = new CustomTableModel{this->uc};
	this->mylistTableView = new QTableView{};
	this->mylistTableView->setModel(this->mylistTableModel);
	this->mylistTableView->resizeRowsToContents();
	this->mylistTableView->resizeColumnsToContents();
}

void UserGUI::initGUIModeUser()
{
	this->tutorialsListWidget = new QListWidget{};
	//this->watchlistWidget = new QListWidget{};
	this->filteredTutorialsWidget = new QListWidget{};

	this->titleLineEdit = new QLineEdit{};
	this->presenterLineEdit = new QLineEdit{};
	this->minutesLineEdit = new QLineEdit{};
	this->secondsLineEdit = new QLineEdit{};
	this->likesLineEdit = new QLineEdit{};
	this->linkLineEdit = new QLineEdit{};
	this->searchLineEdit = new QLineEdit{};

	this->addButton = new QPushButton{ "Add Tutorial to Watchlist" };
	this->deleteButton = new QPushButton{ "Delete Tutorial from Watchlist" };
	this->searchButton = new QPushButton{ "Search" };
	this->openButton = new QPushButton{ "Play the tutorial on youtube" };
	this->openCSV = new QPushButton{ "View the watchlist in NotePad" };
	this->openHTML = new QPushButton{ "View the watchlist in browser" };
	

	// the main layout 
	QBoxLayout* mainLayout = new QHBoxLayout{ this };

	// build the left layout: title, tutorials' list
	QBoxLayout* leftLayout = new QVBoxLayout{ this };

	QLabel* titlee = new QLabel(this);
	titlee->setText("Tutorials' List");
	leftLayout->addWidget(titlee);

	leftLayout->addWidget(this->tutorialsListWidget);
	

	mainLayout->addLayout(leftLayout);

	//build the central layout: tutorial details, buttons 
	QBoxLayout* centralLayout = new QVBoxLayout{ this };

	QFormLayout* tutorialDetailsLayout = new QFormLayout{};

	tutorialDetailsLayout->addRow("Title:", this->titleLineEdit);
	tutorialDetailsLayout->addRow("Presenter:", this->presenterLineEdit);
	tutorialDetailsLayout->addRow("Minutes:", this->minutesLineEdit);
	tutorialDetailsLayout->addRow("Seconds:", this->secondsLineEdit);
	tutorialDetailsLayout->addRow("Likes:", this->likesLineEdit);
	tutorialDetailsLayout->addRow("Link:", this->linkLineEdit);

	centralLayout->addLayout(tutorialDetailsLayout);
	QLabel* title = new QLabel(this);
	title->setText("What you can do: ");
	title->setIndent(275);
	centralLayout->addWidget(title);
	

	// build the search layout
	QBoxLayout* mainCentralLayout = new QHBoxLayout{ this };
	QLabel* title1 = new QLabel(this);
	title1->setText("Search tutorials by presenter -> introduce the name of the presenter: ");
	mainCentralLayout->addWidget(title1);
	mainCentralLayout->addWidget(this->searchLineEdit);
	mainCentralLayout->addWidget(this->searchButton);
	

	centralLayout->addLayout(mainCentralLayout, 1);
	QLabel* title2 = new QLabel(this);
	title2->setText("Filtered Tutorials ( add one or more to your watchlist, if you want): ");
	centralLayout->addWidget(title2);
	centralLayout->addWidget(this->filteredTutorialsWidget);


	QGridLayout* buttonsLayout = new QGridLayout{};
	buttonsLayout->addWidget(this->openButton, 1, 0);
	buttonsLayout->addWidget(this->addButton, 2, 0);
	buttonsLayout->addWidget(this->deleteButton, 3, 0);
	buttonsLayout->addWidget(this->openCSV, 4, 0);
	buttonsLayout->addWidget(this->openHTML, 5, 0);
	//buttonsLayout->addWidget(this->showMyListButton, 6, 0);

	centralLayout->addLayout(buttonsLayout);


	mainLayout->addLayout(centralLayout);

	// build the left layout: title1, watchlist
	QBoxLayout* rightLayout = new QVBoxLayout{ this };

	QLabel* title3 = new QLabel(this);
	title3->setText("WatchList");

	rightLayout->addWidget(title3);

	this->initializeTableView();
	rightLayout->addWidget(mylistTableView);


	mainLayout->addLayout(rightLayout);

	this->tutorialsListActive = 0;
	this->watchlistActive = 0;
	this->filteredActive = 0;

	
}

void UserGUI::populateWatchList()
{
	this->mylistTableModel->resetModel();
	this->mylistTableView->setModel(mylistTableModel);
	this->mylistTableView->resizeRowsToContents();
	this->mylistTableView->resizeColumnsToContents();

}

void UserGUI::populateList()
{
	this->tutorialsListWidget->clear(); //refresh and repopulate the list each time ( for add, delete, etc)

	vector<Tutorial> allTutorials = this->ac.getAllC();

	for (Tutorial& t : allTutorials)
		this->tutorialsListWidget->addItem(QString::fromStdString(t.toString()));

}

void UserGUI::connectSignalsAndSlots()
{
	// when the item selection is changed in the list, we want to populate the line edits with the details of the tutorial

	QObject::connect(this->tutorialsListWidget, &QListWidget::itemSelectionChanged, [this]() {

		int selectedIndex = getSelectedIndexMainList();
		if (selectedIndex < 0)
			return;

		Tutorial t = this->ac.getAllC()[selectedIndex];
		this->titleLineEdit->setText(QString::fromStdString(t.getTitle()));
		this->presenterLineEdit->setText(QString::fromStdString(t.getPresenter()));
		this->minutesLineEdit->setText(QString::fromStdString(to_string(t.getDuration().getMinutes())));
		this->secondsLineEdit->setText(QString::fromStdString(to_string(t.getDuration().getSeconds())));
		this->likesLineEdit->setText(QString::fromStdString(to_string(t.getLikes())));
		this->linkLineEdit->setText(QString::fromStdString(t.getTutorialLink()));
		this->tutorialsListActive = 1;
		this->watchlistActive = 0;
		this->filteredActive = 0;

		}); // the widget that is going to emit the signal, &the signal, the slot/
														// the function that is going to get called whenever we select a new item in the list 

	QObject::connect(this->mylistTableView->selectionModel(), &QItemSelectionModel::selectionChanged, [this]() {

		int selectedIndex = getSelectedIndexWatchList();
		if (selectedIndex < 0)
			return;

		Tutorial t = this->uc.getAllUC()[selectedIndex];
		this->titleLineEdit->setText(QString::fromStdString(t.getTitle()));
		this->presenterLineEdit->setText(QString::fromStdString(t.getPresenter()));
		this->minutesLineEdit->setText(QString::fromStdString(to_string(t.getDuration().getMinutes())));
		this->secondsLineEdit->setText(QString::fromStdString(to_string(t.getDuration().getSeconds())));
		this->likesLineEdit->setText(QString::fromStdString(to_string(t.getLikes())));
		this->linkLineEdit->setText(QString::fromStdString(t.getTutorialLink()));
		this->watchlistActive = 1;
		this->tutorialsListActive = 0;
		this->filteredActive = 0;
		});

	QObject::connect(this->filteredTutorialsWidget, &QListWidget::itemSelectionChanged, [this]() {

		int selectedIndex = getSelectedIndexFilteredList();
		if (selectedIndex < 0)
			return;

		Tutorial t = this->filtered[selectedIndex];
		this->titleLineEdit->setText(QString::fromStdString(t.getTitle()));
		this->presenterLineEdit->setText(QString::fromStdString(t.getPresenter()));
		this->minutesLineEdit->setText(QString::fromStdString(to_string(t.getDuration().getMinutes())));
		this->secondsLineEdit->setText(QString::fromStdString(to_string(t.getDuration().getSeconds())));
		this->likesLineEdit->setText(QString::fromStdString(to_string(t.getLikes())));
		this->linkLineEdit->setText(QString::fromStdString(t.getTutorialLink()));
		this->watchlistActive = 0;
		this->tutorialsListActive = 0;
		this->filteredActive = 1;
		});

	QObject::connect(this->addButton, &QPushButton::clicked, this, &UserGUI::addTutorialU);
	QObject::connect(this->searchButton, &QPushButton::clicked, this, &UserGUI::showListFiltered);
	QObject::connect(this->openButton, &QPushButton::clicked, this, &UserGUI::playOnYoutube);
	QObject::connect(this->deleteButton, &QPushButton::clicked, this, &UserGUI::deleteTutorialU);
	QObject::connect(this->openCSV, &QPushButton::clicked, this, &UserGUI::openCSVf);
	QObject::connect(this->openHTML, &QPushButton::clicked, this, &UserGUI::openHTMLf);
	//QObject::connect(this->showMyListButton, &QPushButton::clicked, this, &UserGUI::showMyList);
}

int UserGUI::getSelectedIndexMainList() const
{
	QModelIndexList selectedIndexes = this->tutorialsListWidget->selectionModel()->selectedIndexes();
	if (selectedIndexes.size() == 0)
	{
		this->titleLineEdit->clear();
		this->presenterLineEdit->clear();
		this->minutesLineEdit->clear();
		this->secondsLineEdit->clear();
		this->likesLineEdit->clear();
		this->linkLineEdit->clear();
		return -1;
	}

	int selectedIndex = selectedIndexes.at(0).row();
	return selectedIndex;
}

int UserGUI::getSelectedIndexWatchList() const
{
	QModelIndexList selectedIndexes = this->mylistTableView->selectionModel()->selectedIndexes();
	if (selectedIndexes.size() == 0)
	{
		this->titleLineEdit->clear();
		this->presenterLineEdit->clear();
		this->minutesLineEdit->clear();
		this->secondsLineEdit->clear();
		this->likesLineEdit->clear();
		this->linkLineEdit->clear();
		return -1;
	}

	int selectedIndex = selectedIndexes.at(0).row();
	return selectedIndex;
}

int UserGUI::getSelectedIndexFilteredList() const
{
	QModelIndexList selectedIndexes = this->filteredTutorialsWidget->selectionModel()->selectedIndexes();
	if (selectedIndexes.size() == 0)
	{
		this->titleLineEdit->clear();
		this->presenterLineEdit->clear();
		this->minutesLineEdit->clear();
		this->secondsLineEdit->clear();
		this->likesLineEdit->clear();
		this->linkLineEdit->clear();
		return -1;
	}

	int selectedIndex = selectedIndexes.at(0).row();
	return selectedIndex;
}

void UserGUI::addTutorialU()
{
	
	string title = this->titleLineEdit->text().toStdString();
	string presenter = this->presenterLineEdit->text().toStdString();
	int minutes = this->minutesLineEdit->text().toInt();
	int seconds = this->secondsLineEdit->text().toInt();
	double likes = this->likesLineEdit->text().toDouble();
	string link = this->linkLineEdit->text().toStdString();
	Duration duration = { minutes, seconds };
	Tutorial t = { title, presenter, duration, likes, link };

	if (title == "")
	{
		QMessageBox::critical(this, "Error", "No tutorial was selected!");
		return;
	}

	if (this->watchlistActive)
	{
		QMessageBox::critical(this, "Error", "You cannot add from here!");
		return;
	}
	else
	{
		try
		{
			this->uc.addToWatchList(t);
		}
		catch (RepositoryException& re)
		{
			QMessageBox::critical(this, "Error", "The tutorial already exists!");
		}
		this->populateWatchList();

		//int lastElement = this->uc.getAllUC().size() - 1;
		//this->watchlistWidget->setCurrentRow(lastElement);
	}

}

void UserGUI::showListFiltered()
{
	auto presenter = this->searchLineEdit->text().toStdString();
	this->filteredTutorialsWidget->clear();
	this->filtered.clear();

	if (presenter != "")
	{

		vector<Tutorial> filteredTutorials = this->uc.showTutorialsOfGivenPresenterUC(presenter);
		for (Tutorial& t : filteredTutorials)
		{
			this->filteredTutorialsWidget->addItem(QString::fromStdString(t.toString()));
			filtered.push_back(t);
		}
		if (filteredTutorials.size() == 0)
			QMessageBox::information(this, "Oops!", "There are no tutorials belonging to this presenter!");
	}
	else
	{

		vector<Tutorial> allTutorials = this->ac.getAllC();

		for (Tutorial& t : allTutorials)
		{
			this->filteredTutorialsWidget->addItem(QString::fromStdString(t.toString()));
			filtered.push_back(t);
		}
	}

	this->searchLineEdit->clear();

}

void UserGUI::playOnYoutube()
{
	QString link = this->linkLineEdit->text();
	QDesktopServices::openUrl(QUrl(link));
}

void UserGUI::noRate()
{
	this->rateWidget->close();
}

void UserGUI::yesRate()
{
	uc.rateTutorial(tutorialToBeRated);
	this->populateList();
	this->filteredTutorialsWidget->clear();
	this->rateWidget->close();
}

void UserGUI::openCSVf()
{
	if (this->repoType != "csv")
	{
		QMessageBox::critical(this, "Error", "The type of files you chose at the beginning does not permit this action!");
		return;
	}
	else
	{
		ShellExecute(0, 0, L"Watchlist.csv", 0, 0, SW_SHOW);
	}

}

void UserGUI::openHTMLf()
{
	if (this->repoType != "html")
	{
		QMessageBox::critical(this, "Error", "The type of files you chose at the beginning does not permit this action!");
		return;
	}
	else
	{
		ShellExecute(0, 0, L"Watchlistt.html", 0, 0, SW_SHOW);
	}
}

void UserGUI::createRateWidget()
{
	this->rateWidget = new QWidget();
	this->rateWidget->show();
	this->rateWidget->setWindowTitle("Rating");
	QLabel* title = new QLabel(this);
	title->setText("Do you want to rate the tutorial?");

	QVBoxLayout* vlay = new QVBoxLayout(this->rateWidget);
	vlay->addWidget(title, 1, Qt::AlignCenter);

	QPushButton* btn1 = new QPushButton("Yes");
	vlay->addWidget(btn1);
	QPushButton* btn2 = new QPushButton("No");
	vlay->addWidget(btn2);
	this->rateWidget->setLayout(vlay);
	QObject::connect(btn2, &QPushButton::clicked, this, &UserGUI::noRate);
	QObject::connect(btn1, &QPushButton::clicked, this, &UserGUI::yesRate);

}
void UserGUI::deleteTutorialU()
{
	if (this->tutorialsListActive == 1 || this->filteredActive == 1)
	{
		QMessageBox::critical(this, "Error", "No tutorial from the watchlist was selected!");
		return;
	}
	int selectedIndex = this->mylistTableView->selectionModel()->selectedIndexes().at(0).row();
	if (selectedIndex < 0)
	{
		QMessageBox::critical(this, "Error", "No tutorial from the watchlist was selected!");
		return;
	}
	else
	{
		Tutorial t = this->uc.getAllUC()[selectedIndex];
		this->tutorialToBeRated = t.getTutorialLink();
		this->createRateWidget();
		this->uc.removeTutorialUC(t.getTutorialLink());
		this->populateWatchList();
		return;
	}

}

