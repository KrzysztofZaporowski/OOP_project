#pragma once
#include "Book.h"
#include "vector"

class LibraryCollections{
public:
	LibraryCollections(std::vector<Book> librarycollection);
	std::vector<Book> getLibraryCollection();
private:
	std::vector<Book> libraryCollection;
};

