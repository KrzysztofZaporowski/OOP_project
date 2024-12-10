#include "MenuHandler.h"
/// <summary>
/// dodaæ wiêcej metod ¿eby kod by³ bardziej przejzysty 
/// </summary>
void MenuHandler::menu(){
	int choice;
	LibraryDB libraryDB("root", "Krzysiu13", "library", "books", "readers", "admins", "renting_history", "borrowed_books");
	libraryDB.loadData();
	std::vector<Book> books = libraryDB.getBooks();
	std::vector<Reader> readers = libraryDB.getReaders();
	std::vector<Admin> admins = libraryDB.getAdmins();
	std::vector<LibraryDB::Item> rentingHistory = libraryDB.getRentingHistory();
	std::vector<LibraryDB::Item> borrowedBooks = libraryDB.getBorrowedBooks();

	std::cout << "Welcome in library management system!" << std::endl;
	while (true){
		std::cout << "Choose what you want to do:" << std::endl <<
			"1. Log in" << std::endl << "2. Sign in" << std::endl << "3. Quit" << std::endl << "(write 1 or 2)" << std::endl;
		std::cin >> choice;
		std::cout << std::endl;
		if (choice == 1){
			std::cout << "You want to log as:" << std::endl << "1. Reader" << std::endl << "2. Admin" << std::endl;
		}
		else if (choice == 2){
			Admin* temp = new Admin("temp", "temp", "temp");
			//add user and delete temp user
		}
		else if (choice == 3) {
			libraryDB.saveBooksToDB(books);
			libraryDB.saveReadersToDB(readers);
			libraryDB.saveAdminsToDB(admins);
			libraryDB.saveToBorrowedBooksTable(borrowedBooks);
			libraryDB.saveToRentingHistoryTable(borrowedBooks);
			break;
		}
		else {
			std::cout << "You have choosen unavaiable option!" << std::endl;
		}
	}
}
