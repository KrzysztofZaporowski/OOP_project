#pragma once
#include <string>

class Book{
public:
	Book(std::string title, int publishYear, const std::string& authorName, const std::string& author_Lastname, long long isbn, int amountInLibrary);
	std::string getTitle() const;
	int getPublishYear() const;
	std::string getAuthorName() const;
	std::string getAuthorLastname() const;
	long long getIsbn() const;
	bool getIsAvailable() const;
private:
	std::string title;
	int publishYear;
	long long isbn;
	bool isAvailable;
	std::string authorName;
	std::string authorLastname;
	int amountInLibrary;
};

