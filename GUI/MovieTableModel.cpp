#include "MovieTableModel.h"
#include <qbrush.h>
#include <qcolor.h>

MovieTableModel::~MovieTableModel()
{
}

int MovieTableModel::rowCount(const QModelIndex & parent) const
{
	return this->repo.getMovies().size();
}

int MovieTableModel::columnCount(const QModelIndex & parent) const
{
	return 6;
}

QVariant MovieTableModel::data(const QModelIndex & index, int role) const
{
	Movie currentMovie = this->repo.getMovies()[index.row()];

	if (role == Qt::DisplayRole || role == Qt::EditRole)
	{
		switch (index.column())
		{
		case 0:		
			return QString::fromStdString(currentMovie.getTitle());
		case 1:		
			return QString::fromStdString(currentMovie.getGenre());
		case 2:		
			return QString::number(currentMovie.getRelease());
		case 3:		
			return QString::number(currentMovie.getLikes());
		case 4:		
			return QString::fromStdString(currentMovie.getSource());
		case 5:		
			return QString::number(currentMovie.getDuration());

		default:
			break;
		}
	}

	return QVariant();
}

QVariant MovieTableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
	if (role == Qt::DisplayRole)
	{
		if (orientation == Qt::Horizontal)
		{
			switch (section)
			{
			case 0:
				return QString{ "Title" };
			case 1:
				return QString{ "Genre" };
			case 2:
				return QString{ "Year" };
			case 3:
				return QString{ "Likes" };
			case 4:
				return QString{ "Link" };
			case 5:
				return QString{ "Duration" };
			default:
				break;
			}
		}
	}

	return QVariant();
}

bool MovieTableModel::setData(const QModelIndex & index, const QVariant & value, int role)
{
	if (!index.isValid() || role != Qt::EditRole)
		return false;

	int row = index.row();
	int col = index.column();

	Movie& currentMovie = this->repo.getMovies()[index.row()];
	Movie old= this->repo.getMovies()[index.row()];

	if (role == Qt::EditRole)
	{
		switch (col)
		{
		case 0:
			break;
		case 1:
		{
			std::string genre{ value.toString().toStdString() };
			currentMovie.setGenre(genre);
			break;
		}
		this->repo.update(old, currentMovie);
		
		}
	}

	emit dataChanged(index, index);
	return true;
}

Qt::ItemFlags MovieTableModel::flags(const QModelIndex & index) const
{
	int col = index.column();
	if (col == 0 )
		return Qt::ItemFlags{};
	return Qt::ItemIsEnabled | Qt::ItemIsEditable | Qt::ItemIsSelectable;
}
