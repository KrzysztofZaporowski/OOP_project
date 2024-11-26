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

void BookDb::addBook(int id, const std::string& title, int year, const std::string& author_name, const std::string& author_lastname, long long isbn, int available_copies) {
    try {
        sql::PreparedStatement* pstmt = conn->prepareStatement("INSERT INTO library_resources (id, title, published_year, author_name, author_lastname, isbn, available_copies) VALUES (?, ?, ?, ?, ?, ?, ?)");
        pstmt->setInt(1, id);
        pstmt->setString(2, title);
        pstmt->setInt(3, year);
        pstmt->setString(4, author_name);
        pstmt->setString(5, author_lastname);
        pstmt->setInt64(6, isbn);
        pstmt->setInt(7, available_copies);
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
        sql::PreparedStatement* pstmt = conn->prepareStatement("DELETE FROM library_resources WHERE id= ?");
        pstmt->setInt(1, id);
        pstmt->executeUpdate();
        std::cout << "Book deleted successfully" << std::endl;
        delete pstmt;
    }
    catch (sql::SQLException& e) {
        std::cerr << "Error deleting book: " << e.what() << std::endl;
    }
}

std::vector<Book> BookDb::listBooks() {
    std::vector<Book> books;
    try {
        sql::Statement* stmt = conn->createStatement();
        sql::ResultSet* res = stmt->executeQuery("SELECT title, published_year, author_name, author_lastname, isbn, available_copies FROM library_resources");
        while (res->next()) {
            std::string title = res->getString("title");
            int year = res->getInt("published_year");
            std::string authorName = res->getString("author_name");
            std::string authorLastname = res->getString("author_lastname");
            long long isbn = res->getInt64("isbn");
            int available_copies = res->getInt("available_copies");

            books.emplace_back(title, year, authorName, authorLastname, isbn, available_copies);
        }   
        delete res;
        delete stmt;
    }
    catch (sql::SQLException& e) {
        std::cerr << "Error listing books: " << e.what() << std::endl;
    }
    return books;
}

void BookDb::updateBook(int id, const std::string& title, int year, const std::string& author_name, const std::string& author_lastname, long long isbn, int available_copies){
    try {
        sql::PreparedStatement* pstmt = conn->prepareStatement(
            "UPDATE library_resources SET title = ?, published_year = ?, author_name = ?, author_lastname = ?, isbn = ?, available_copies = ? WHERE id = ?"
        );
        pstmt->setString(1, title);
        pstmt->setInt(2, year);
        pstmt->setString(3, author_name);
        pstmt->setString(4, author_lastname);
        pstmt->setInt64(5, isbn);
        pstmt->setInt(6, available_copies);
        pstmt->setInt(7, id);
        pstmt->executeUpdate();
        std::cout << "Book updated successfully: ID=" << id << std::endl;
        delete pstmt;
    }
    catch (sql::SQLException& e) {
        std::cerr << "Error updating book: " << e.what() << std::endl;
    }
}
