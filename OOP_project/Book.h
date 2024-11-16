#pragma once
#include <string>
#include "Author.h"

class Book{
public:
	Book(std::string title, int publishYear, long long isbn, bool isAvailable, Author author, int amountInLibrary);
	std::string getTitle();
	int getPublishYear();
	//getAuthor
	long long getIsbn();
	bool getIsAvailable();
private:
	std::string title;
	int publishYear;
	long long isbn;
	bool isAvailable;
	Author author;
	int amountInLibrary;
};

