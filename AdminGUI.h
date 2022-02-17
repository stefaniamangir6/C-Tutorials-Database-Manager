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
#include <qevent.h>
#include <QShortcut>

class AdminGUI : public QWidget
{
private:
	AdminController& ac;

	// graphical elements
	QListWidget* tutorialsListWidget;
	QLineEdit* titleLineEdit, * presenterLineEdit, * minutesLineEdit, * secondsLineEdit, * likesLineEdit, * linkLineEdit;
	QPushButton* addButton, * deleteButton, * updateButton, * adminButton, * userButton, *undoButton, *redoButton;

	//bool pressedCTRLKey;
	//bool pressedZKey;
	//bool pressedYKey;

	QShortcut *ctrlZ, *ctrlY;


public:
	AdminGUI(AdminController& ac);

private:
	void initGUIModeAdmin();
	void populateList();
	void connectSignalsAndSlots();
	int getSelectedIndex() const;
	void addTutorial();
	void deleteTutorial();
	void updateTutorial();
	void undo();
	void redo();
	//bool eventFilter(QObject* object, QEvent* currentEvent);
};

