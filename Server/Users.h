#ifndef _USERS_H
#define _USERS_H

#include <QObject>

struct AccountData
{
	qint16 ID;
	QString Name;
	QString Password;
};

AccountData Account[] = {
	{ 1, "John", "123456", },
	{ 2, "Michelle", "123456",},
	{ 3, "Amy", "123456", },
	{ 4, "Kim", "123456", },
	{ 5, "Mary", "123456", },
	{ 6, "David", "123456", },
	{ 7, "Sunny", "123456", },
	{ 8, "James", "123456", },
	{ 9, "Maria", "123456", },
	{ 10, "Michael", "123456"}
};

#endif //#ifndef _USERS_H