#include "GUI.h"

GUI::GUI(AdminController& ac, UserController& uc, std::string repoType): ac{ ac }, uc{ uc }, repoType{repoType}
{
	this->initGUI();

}

void GUI::adminButtonWindow() {
	this->AdminWindow = new AdminGUI(this->ac);
	AdminWindow->setMinimumWidth(700);


	if(!this->UserWindow->isVisible())
		this->AdminWindow->show();
	else
		QMessageBox::critical(this, "Error", "Close the user mode window first!");
}

void GUI::userButtonWindow() {
	this->UserWindow = new UserGUI(this->ac, this->uc, repoType);
	UserWindow->setMinimumWidth(700);

	if (!this->AdminWindow->isVisible())
		this->UserWindow->show();
	else
		QMessageBox::critical(this, "Error", "Close the admin mode window first!");
	
}

void GUI::initGUI()
{
	auto pWindow = new QWidget();
	

	this->adminButton = new QPushButton{ "Admin" };
	this->userButton = new QPushButton{ "User" };
	QBoxLayout* mainLayout = new QVBoxLayout{ this };

	QGridLayout* buttonsLayout = new QGridLayout{};
	buttonsLayout->addWidget(this->adminButton, 0, 0);
	buttonsLayout->addWidget(this->userButton, 0, 1);

	mainLayout->addLayout(buttonsLayout);
	QObject::connect(this->adminButton, &QPushButton::clicked, this, &GUI::adminButtonWindow);
	QObject::connect(this->userButton, &QPushButton::clicked, this, &GUI::userButtonWindow);

	this->AdminWindow = new AdminGUI(this->ac);
	this->UserWindow = new UserGUI(this->ac, this->uc, repoType);
	
}

