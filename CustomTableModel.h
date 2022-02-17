#pragma once
#include <qabstractitemmodel.h>
#include "AdminController.h"
#include "UserController.h"
#include <qfont.h>
#include <qdebug.h>
#include <qcolor.h>
#include <qbrush.h>

class CustomTableModel : public QAbstractTableModel {
private:
	const int TABLE_FONT_SIZE = 12;
	const std::string TABLE_FONT_NAME = "Times";

	const int TUTORIAL_NAME_HEADER_COLUMN = 0;
	const int PRESENTER_HEADER_COLUMN = 1;
	const int MINUTES_HEADER_COLUMN = 2;
	const int SECONDS_HEADER_COLUMN = 3;
	const int LIKES_HEADER_COLUMN = 4;
	const int TUTORIAL_LINK_HEADER_COLUMN = 5;
	const int NUMBER_OF_COLUMNS = 6;

	int tutorialCount;
	UserController& uc;

public:
	CustomTableModel(UserController& uc, QObject* parent = NULL);
	int rowCount(const QModelIndex& parent = QModelIndex{}) const override;
	int columnCount(const QModelIndex& parent = QModelIndex{}) const override;
	QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;
	QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;
	void resetModel();
	~CustomTableModel();
};