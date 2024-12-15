#include "Admin.h"


Admin::Admin(std::string login, std::string password, std::string nickname) : User(login, password, nickname){}

bool Admin::addUser(std::vector<Reader>& readers, const Reader& reader){
	for (const auto& existingReader : readers) {
		if (existingReader == reader) {
			std::cout << "Reader with this login already exists!" << std::endl;
			return false;
		}
	}
	readers.push_back(reader);
	std::cout << "Reader " << reader.getNick() << " was added!" << std::endl;
	return true;
}

bool Admin::deleteUser(std::vector<Reader>& readers, const Reader& reader){
	for (const auto& existingReader : readers) {
		if (reader == existingReader) {
			readers.erase(std::remove(readers.begin(), readers.end(), reader), readers.end());
			std::cout << "Reader " << reader.getNick() << " has been succesfully deleted!" << std::endl;
			return true;
		}
	}
	std::cout << "User " << reader.getNick() << " can't be deleted. Are you sure you gave good data, because this reader doesn't exit in our databse." << std::endl;
	return false;
}

void Admin::updateBookCopiesNumber(Book& book, int new_amount){
	if (new_amount > 0) {
		book.setAvailableCopies(new_amount);
		std::cout << "Update book: " << book.getTitle() << " copies amount to: " << new_amount << std::endl;
	}
	else {
		std::cout << "It is not possible to have less than 0 copies!" << std::endl;
	}
}

bool Admin::addBook(std::vector<Book>& books, const Book& book){
	for (const auto& existingBook : books) {
		if (existingBook == book){
			std::cout << "Book: " << book.getTitle() << "already exists." << std::endl;
			return false;
		}
	}
	books.push_back(book);
	std::cout << "Book " << book.getTitle() << " added do library." << std::endl;
	return true;
}

bool Admin::deleteBook(std::vector<Book>& books, const Book& book){
	for (const auto& existingBook : books) {
		if (book == existingBook) {
			books.erase(std::remove(books.begin(), books.end(), book), books.end());
			std::cout << "Book: " << book.getTitle() << " has been succesfully deleted!" << std::endl;
			return true;
		}
	}
	std::cout << "Book: " << book.getTitle() << " can't be deleted. We don't have such book in library." << std::endl;
	return false;
}

bool Admin::addAdmin(std::vector<Admin>& admins, const Admin& admin){
	for (const auto& existingAdmin : admins) {
		if (existingAdmin == admin) {
			std::cout << "Admin with this login already exists!" << std::endl;
			return false;
		}
	}
	admins.push_back(admin);
	std::cout << "Reader " << admin.getNick() << " was added!" << std::endl;
	return true;
}

bool Admin::deleteAdmin(std::vector<Admin>& admins, const Admin& admin){
	for (const auto& existingAdmin : admins) {
		if (admin == existingAdmin) {
			admins.erase(std::remove(admins.begin(), admins.end(), admin), admins.end());
			std::cout << "Admin " << admin.getNick() << " has been succesfully deleted!" << std::endl;
			return true;
		}
	}
	std::cout << "User " << admin.getNick() << " can't be deleted. Are you sure you gave good data, because this admin doesn't exit in our databse." << std::endl;
	return false;
}

void Admin::displayInfo(){
	std::cout << "Admin. Login: " << login << ", nickname: " << nickname << std::endl;
}

bool Admin::operator==(const Admin& other) const{
	return login == other.login || nickname == other.nickname;
}


