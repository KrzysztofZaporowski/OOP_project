#pragma once

#include <string>
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

    void addBook(int id, const std::string& title);
    void deleteBook(int id);
    void listBooks();
};
