#pragma once
#include <vector>
#include <utility>
#include "Book.h"

struct Date{
	int day; 
	int month;
	int year;
};

class Rental{
public:
	void extend(std::vector<std::pair<Book, Date>>);
private:
	Date rentData;
	Date returnData;
};

