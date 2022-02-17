#include "AdminGUI.h"

AdminGUI::AdminGUI(AdminController& ac) : ac{ ac }
{
	this->setWindowTitle("ADMIN");
	this->initGUIModeAdmin();
	this->populateList();
	this->connectSignalsAndSlots();
}


void AdminGUI::initGUIModeAdmin()
{
	this->tutorialsListWidget = new QListWidget{};
	this->titleLineEdit = new QLineEdit{};
	this->presenterLineEdit = new QLineEdit{};
	this->minutesLineEdit = new QLineEdit{};
	this->secondsLineEdit = new QLineEdit{};
	this->likesLineEdit = new QLineEdit{};
	this->linkLineEdit = new QLineEdit{};
	this->addButton = new QPushButton{ "Add" };
	this->deleteButton = new QPushButton{ "Delete" };
	this->updateButton = new QPushButton{ "Update" };
	this->undoButton = new QPushButton{ "Undo" };
	this->redoButton = new QPushButton{ "Redo" };

	this->ctrlZ = new QShortcut{ this->tutorialsListWidget };
	this->ctrlY = new QShortcut{ this->tutorialsListWidget };

	QBoxLayout* mainLayout = new QVBoxLayout{ this };

	mainLayout->addWidget(this->tutorialsListWidget);

	QFormLayout* tutorialDetailsLayout = new QFormLayout{};

	tutorialDetailsLayout->addRow("Title:", this->titleLineEdit);
	tutorialDetailsLayout->addRow("Presenter:", this->presenterLineEdit);
	tutorialDetailsLayout->addRow("Minutes:", this->minutesLineEdit);
	tutorialDetailsLayout->addRow("Seconds:", this->secondsLineEdit);
	tutorialDetailsLayout->addRow("Likes:", this->likesLineEdit);
	tutorialDetailsLayout->addRow("Link:", this->linkLineEdit);

	mainLayout->addLayout(tutorialDetailsLayout);

	QGridLayout* buttonsLayout = new QGridLayout{};
	buttonsLayout->addWidget(this->addButton, 0, 0);
	buttonsLayout->addWidget(this->deleteButton, 0, 1);
	buttonsLayout->addWidget(this->updateButton, 1, 0);
	buttonsLayout->addWidget(this->undoButton, 1, 1);
	buttonsLayout->addWidget(this->redoButton, 2, 0);

	mainLayout->addLayout(buttonsLayout);

	this->installEventFilter(this);
}

void AdminGUI::populateList()
{
	this->tutorialsListWidget->clear(); //refresh and repopulate the list each time ( for add, delete, etc)

	vector<Tutorial> allTutorials = this->ac.getAllC();

	for (Tutorial& t : allTutorials)
		this->tutorialsListWidget->addItem(QString::fromStdString(t.toString()));

}

void AdminGUI::connectSignalsAndSlots()
{
	// when the item selection is changed in the list, we want to populate the line edits with the details of the tutorial

	QObject::connect(this->tutorialsListWidget, &QListWidget::itemSelectionChanged, [this]() {

		int selectedIndex = getSelectedIndex();
		if (selectedIndex < 0)
			return;

		Tutorial t = this->ac.getAllC()[selectedIndex];
		this->titleLineEdit->setText(QString::fromStdString(t.getTitle()));
		this->presenterLineEdit->setText(QString::fromStdString(t.getPresenter()));
		this->minutesLineEdit->setText(QString::fromStdString(to_string(t.getDuration().getMinutes())));
		this->secondsLineEdit->setText(QString::fromStdString(to_string(t.getDuration().getSeconds())));
		this->likesLineEdit->setText(QString::fromStdString(to_string(t.getLikes())));
		this->linkLineEdit->setText(QString::fromStdString(t.getTutorialLink()));

		}); // the widget that is going to emit the signal, &the signal, the slot/
														// the function that is going to get called whenever we select a new item in the list 
	QObject::connect(this->addButton, &QPushButton::clicked, this, &AdminGUI::addTutorial);
	QObject::connect(this->deleteButton, &QPushButton::clicked, this, &AdminGUI::deleteTutorial);
	QObject::connect(this->updateButton, &QPushButton::clicked, this, &AdminGUI::updateTutorial);

	QObject::connect(this->undoButton, &QPushButton::clicked, this, &AdminGUI::undo);
	ctrlZ->setKey(Qt::CTRL + Qt::Key_Z);
	QObject::connect(ctrlZ, &QShortcut::activated, this, &AdminGUI::undo);

	QObject::connect(this->redoButton, &QPushButton::clicked, this, &AdminGUI::redo);
	ctrlY->setKey(Qt::CTRL + Qt::Key_Y);
	QObject::connect(ctrlY, &QShortcut::activated, this, &AdminGUI::redo);
}

int AdminGUI::getSelectedIndex() const
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

void AdminGUI::addTutorial()
{
	string title = this->titleLineEdit->text().toStdString();
	string presenter = this->presenterLineEdit->text().toStdString();
	int minutes = this->minutesLineEdit->text().toInt();
	int seconds = this->secondsLineEdit->text().toInt();
	double likes = this->likesLineEdit->text().toDouble();
	string link = this->linkLineEdit->text().toStdString();

	try
	{
		this->ac.addTutorial(title, presenter, minutes, seconds, likes, link);
	}
	catch (ValidatorException& e)
	{
		QMessageBox::critical(this, "Error", "Invalid details for the tutorial!");
	}
	catch (RepositoryException& re)
	{
		QMessageBox::critical(this, "Error", "The tutorial already exists!");
	}
	this->populateList();

	int lastElement = this->ac.getAllC().size() - 1;
	this->tutorialsListWidget->setCurrentRow(lastElement);
}

void AdminGUI::deleteTutorial()
{
	int selectedIndex = this->getSelectedIndex();
	if (selectedIndex < 0)
	{
		QMessageBox::critical(this, "Error", "No tutorial was selected!");
		return;
	}
	Tutorial t = this->ac.getAllC()[selectedIndex];

	this->ac.removeTutorial(t.getTutorialLink());
	this->populateList();
}

void AdminGUI::updateTutorial()
{
	int selectedIndex = this->getSelectedIndex();
	if (selectedIndex < 0)
	{
		QMessageBox::critical(this, "Error", "No tutorial was selected!");
		return;
	}
	Tutorial t = this->ac.getAllC()[selectedIndex];

	string title = this->titleLineEdit->text().toStdString();
	string presenter = this->presenterLineEdit->text().toStdString();
	int minutes = this->minutesLineEdit->text().toInt();
	int seconds = this->secondsLineEdit->text().toInt();
	double likes = this->likesLineEdit->text().toDouble();
	string link = this->linkLineEdit->text().toStdString();

	try
	{
		this->ac.updateTutorial(title, presenter, minutes, seconds, likes, link);
	}
	catch (ValidatorException& e)
	{
		QMessageBox::critical(this, "Error", "Invalid details for the tutorial!");
	}

	this->populateList();

}

void AdminGUI::undo()
{
	try {
		this->ac.undoLastAction();
		this->populateList();
	}
	catch (const std::exception& currentException) {
		QMessageBox::critical(this, "Error", "No more undos!");
	}
}

void AdminGUI::redo()
{
	try {
		this->ac.redoLastAction();
		this->populateList();
	}
	catch (const std::exception& currentException) {
		QMessageBox::critical(this, "Error", "No more redos!");
	}
}

/*bool AdminGUI::eventFilter(QObject* object, QEvent* currentEvent) {
	if (currentEvent->type() == QEvent::KeyPress) {
		c pressedKey = (QKeyEvent*)currentEvent;
		if (pressedKey->key() == Qt::Key_Control) {
			this->pressedCTRLKey = true;
		}
		if (pressedKey->key() == Qt::Key_Y) {
			this->pressedYKey = true;
		}
		if (pressedKey->key() == Qt::Key_Z) {
			this->pressedZKey = true;
		}

		if (this->pressedCTRLKey) {
			if (this->pressedZKey) { // CTRL-Z - undo
				this->undo();
				this->pressedCTRLKey = this->pressedZKey = false; // reset the pressed key values
			}
			else if (this->pressedYKey) { // CTRL-Y - redo
				this->redo();
				this->pressedCTRLKey = this->pressedYKey = false; // reset the pressed key values
			}
		}

		return true;
	}

	return false;
}*/
