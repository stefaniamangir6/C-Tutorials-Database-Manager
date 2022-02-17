#include "CustomTableModel.h"

CustomTableModel::CustomTableModel(UserController& uc, QObject* parent) : QAbstractTableModel{ parent }, uc{ uc }{
	this->tutorialCount = this->uc.getAllUC().size();
}

CustomTableModel::~CustomTableModel() {
	;
}

int CustomTableModel::rowCount(const QModelIndex& parent) const {
	return this->tutorialCount;
}

int CustomTableModel::columnCount(const QModelIndex& parent) const {
	return NUMBER_OF_COLUMNS;
}

QVariant CustomTableModel::data(const QModelIndex& index, int role) const {
	int row = index.row();
	int column = index.column();

	std::vector<Tutorial> mylist = this->uc.getAllUC();
	Tutorial currentTutorial = mylist[row];
	

	if (role == Qt::DisplayRole) {
		
		if (column == TUTORIAL_NAME_HEADER_COLUMN) {
			return QString::fromStdString(currentTutorial.getTitle());
		}
		if (column == PRESENTER_HEADER_COLUMN) {
			return QString::fromStdString(currentTutorial.getPresenter());
		}
		if (column == MINUTES_HEADER_COLUMN) {
			return QString::number(currentTutorial.getDuration().getMinutes());
		}
		if (column == SECONDS_HEADER_COLUMN) {
			return QString::number(currentTutorial.getDuration().getSeconds());
		}
		if (column == LIKES_HEADER_COLUMN) {
			return QString::number(currentTutorial.getLikes());
		}
		if(column == TUTORIAL_LINK_HEADER_COLUMN)
			return QString::fromStdString(currentTutorial.getTutorialLink());
	}

	if (role == Qt::FontRole) {
		QFont tableFont(QString::fromStdString(TABLE_FONT_NAME), TABLE_FONT_SIZE);
		tableFont.setBold(true);
		return tableFont;
	}

	return QVariant();
}

QVariant CustomTableModel::headerData(int section, Qt::Orientation orientation, int role) const {
	if (role == Qt::DisplayRole) {
		if (orientation == Qt::Horizontal) {
			if (section == TUTORIAL_NAME_HEADER_COLUMN) {
				return QString{ "Tutorial's Title" };
			}
			if (section == PRESENTER_HEADER_COLUMN) {
				return QString{ "Presenter" };
			}
			if (section == MINUTES_HEADER_COLUMN) {
				return QString{ "Minutes" };
			}
			if (section == SECONDS_HEADER_COLUMN) {
				return QString{ "Seconds" };
			}
			if (section == LIKES_HEADER_COLUMN) {
				return QString{ "Likes" };
			}
			if (section == TUTORIAL_LINK_HEADER_COLUMN)
				return QString{ "Tutorial's Link" };
		}
	}

	if (role == Qt::FontRole) {
		QFont tableFont(QString::fromStdString(TABLE_FONT_NAME), TABLE_FONT_SIZE);
		tableFont.setBold(true);
		tableFont.setItalic(true);
		return tableFont;
	}

	return QVariant{};
}

void CustomTableModel::resetModel()
{
	this->tutorialCount = this->uc.getAllUC().size(); // update the row count 
	this->endResetModel(); // this emits the signal that the model has been updated
}
