#pragma once
#include <string>
#include <vector>
#include "Book.h"

class Author{
public:
	Author(std::string name, std::string lastname, std::vector<Book> writtenBooks);
	std::string getName();
	std::string getLastname();
	std::vector<Book> getWrittenBooks;
private:
	std::string name;
	std::string lastname;
	std::vector<Book> writtenBooks;
};

