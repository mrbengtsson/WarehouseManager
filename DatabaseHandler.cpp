#include "DatabaseHandler.h"

DatabaseHandler::DatabaseHandler(int capacity)
{
	this->capacity = capacity;
	this->nrOfDatabases = 0;
	this->databaseList = new Database*[capacity];

	for (int i = 0; i < capacity; i++)
	{
		this->databaseList[i] = nullptr;
	}
}

DatabaseHandler::~DatabaseHandler()
{
	for (int i = 0; i < this->nrOfDatabases; i++)
	{
		delete this->databaseList[i];
	}

	delete[] this->databaseList;
}

void DatabaseHandler::addDatabase(Database* database) throw(...)
{
	if (this->nrOfDatabases >= this->capacity)
	{
		throw std::exception("Array is full.");
	}

	this->databaseList[this->nrOfDatabases] = database;
	this->nrOfDatabases++;
}

Database* DatabaseHandler::getDatabase(std::string name)
{
	Database* result = nullptr;

	for (int i = 0; i < this->nrOfDatabases && result == nullptr; i++)
	{
		if (this->databaseList[i]->getName() == name)
		{
			result = this->databaseList[i];
		}
	}

	return result;
}

Database * DatabaseHandler::removeDatabase(std::string name)
{
	Database* result = nullptr;

	for (int i = 0; i < this->nrOfDatabases && result == nullptr; i++)
	{
		if (this->databaseList[i]->getName() == name)
		{
			result = this->databaseList[i];

			if (i == this->nrOfDatabases - 1)
			{
				this->databaseList[i] = nullptr;
			}
			else
			{
				this->databaseList[i] = this->databaseList[this->nrOfDatabases - 1];
				this->databaseList[this->nrOfDatabases - 1] = nullptr;
			}

			this->nrOfDatabases--;
		}
	}

	return result;
}

int DatabaseHandler::getNrOfDatabases() const
{
	return this->nrOfDatabases;
}

bool DatabaseHandler::isFull() const
{
	return this->nrOfDatabases >= this->capacity;
}
