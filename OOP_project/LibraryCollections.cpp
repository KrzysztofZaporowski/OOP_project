#include "LibraryCollections.h"

LibraryCollections::LibraryCollections(std::vector<Book> librarycollection):libraryCollection(librarycollection){}

std::vector<Book> LibraryCollections::getLibraryCollection(){
	return libraryCollection;
}
