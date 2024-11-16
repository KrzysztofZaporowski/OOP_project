#pragma once
#include "User.h"
#include "Book.h"
#include <string>
#include <vector>

class Reader : public User{
public:
	//not finished yet
private:
	void rentBook(Book book);
	void extendRental(Book book);
	void returnBook(Book book);
	// not finished yet
};

