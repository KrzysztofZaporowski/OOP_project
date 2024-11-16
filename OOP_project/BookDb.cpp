#include "BookDb.h"
#include <iostream>

BookDb::BookDb(const std::string& host, const std::string& user, const std::string& password, const std::string& schema) {
    try {
        driver = sql::mysql::get_mysql_driver_instance();
        conn = driver->connect(host, user, password);
        conn->setSchema(schema);
        std::cout << "Connected to the database successfully." << std::endl;
    }
    catch (sql::SQLException& e) {
        std::cerr << "Error connecting to the database: " << e.what() << std::endl;
        throw;
    }
}

BookDb::~BookDb() {
    delete conn;
}

void BookDb::addBook(int id, const std::string& title) {
    try {
        sql::PreparedStatement* pstmt = conn->prepareStatement("INSERT INTO books (id, title) VALUES (?, ?)");
        pstmt->setInt(1, id);
        pstmt->setString(2, title);
        pstmt->executeUpdate();
        std::cout << "Book added successfully: ID=" << id << ", Title=" << title << std::endl;
        delete pstmt;
    }
    catch (sql::SQLException& e) {
        std::cerr << "Error adding book: " << e.what() << std::endl;
    }
}

void BookDb::deleteBook(int id) {
    try {
        sql::PreparedStatement* pstmt = conn->prepareStatement("DELETE FROM books WHERE id= ?");
        pstmt->setInt(1, id);
        pstmt->executeUpdate();
        std::cout << "Book deleted successfully" << std::endl;
        delete pstmt;
    }
    catch (sql::SQLException& e) {
        std::cerr << "Error deleting book: " << e.what() << std::endl;
    }
}

void BookDb::listBooks() {
    try {
        sql::Statement* stmt = conn->createStatement();
        sql::ResultSet* res = stmt->executeQuery("SELECT * FROM books");
        while (res->next()) {
            std::cout << "ID: " << res->getInt("id") << ", Title: " << res->getString("title") << std::endl;
        }
        delete res;
        delete stmt;
    }
    catch (sql::SQLException& e) {
        std::cerr << "Error listing books: " << e.what() << std::endl;
    }
}