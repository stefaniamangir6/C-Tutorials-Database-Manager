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
#include <QCloseEvent>
#include "AdminGUI.h"
#include "UserGUI.h"

class GUI : public QWidget
{
private:
	AdminController& ac;
	UserController& uc;
	std::string repoType;

	// graphical elements
	QWidget* AdminWindow, *UserWindow;
	QPushButton* adminButton, * userButton;

public:
	GUI(AdminController& ac, UserController& uc, std::string repoType);

private:
	void adminButtonWindow();
	void userButtonWindow();
	void initGUI();
	
};

