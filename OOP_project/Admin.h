#pragma once
#include "User.h"
#include "Book.h"
#include <string>
#include <vector>

class Admin : public User{
public:
	void addBook(Book book);
	void deleteBook(Book book);
	void upgrateBookInfo(Book book);
	void accountsMenagement();
private:
	std::vector<Book> bookList;
};

