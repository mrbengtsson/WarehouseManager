#ifndef DATABASE_HANDLER_H
#define DATABASE_HANDLER_H

#include "Database.h"

class DatabaseHandler
{
private:
	int capacity;
	int nrOfDatabases;
	Database** databaseList;
public:
	DatabaseHandler(int capacity);
	virtual ~DatabaseHandler();

	DatabaseHandler(const DatabaseHandler& other) = delete;
	bool operator=(const DatabaseHandler& other) const = delete;

	void addDatabase(Database* database) throw(...);
	Database* getDatabase(std::string name);
	Database* removeDatabase(std::string name);
	int getNrOfDatabases() const;
	bool isFull() const;
};

#endif // !DATABASE_HANDLER_H
