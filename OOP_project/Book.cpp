#include "Book.h"

Book::Book(std::string title, int publishYear, const std::string& authorName, const std::string& authorLastname, long long isbn, int amountInLibrary):title(title),
	publishYear(publishYear), authorName(authorName), authorLastname(authorLastname), isbn(isbn), amountInLibrary(amountInLibrary) {
	if (amountInLibrary > 0){
		isAvailable = true;
	}
	else {
		isAvailable = false;
	}
}

std::string Book::getTitle() const {
	return title;
}

int Book::getPublishYear() const {
	return publishYear;
}

std::string Book::getAuthorName() const {
	return authorName;
}

std::string Book::getAuthorLastname() const {
	return authorLastname;
}

long long Book::getIsbn() const {
	return isbn;
}

bool Book::getIsAvailable() const {
	return isAvailable;
}




