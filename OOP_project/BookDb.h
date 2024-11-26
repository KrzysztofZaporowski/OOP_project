#pragma once
#include "Author.h"
#include <string>
#include <iostream>
#include <vector>
#include "Book.h"
#include "mysql_driver.h"
#include "mysql_connection.h"
#include "cppconn/statement.h"
#include "cppconn/prepared_statement.h"
#include "cppconn/resultset.h"
#include "cppconn/exception.h"

class BookDb {
private:
    sql::mysql::MySQL_Driver* driver;
    sql::Connection* conn;

public:
    BookDb(const std::string& host, const std::string& user, const std::string& password, const std::string& schema);
    ~BookDb();

    void addBook(int id, const std::string& title, int year, const std::string& author_name, const std::string& author_lastname, long long isbn, int available_copies);
    void deleteBook(int id);
    std::vector<Book> listBooks();
    void updateBook(int id, const std::string& title, int year, const std::string& author_name, const std::string& author_lastname, long long isbn, int available_copies);
};
