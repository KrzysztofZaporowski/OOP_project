#include <iostream> 
#include "BookDb.h"
#include "Book.h"
#include "LibraryCollections.h"


using namespace std;
int main()
{
	BookDb db("tcp://localhost:3306", "root", "Krzysiu13", "library");
	LibraryCollections collection(db.listBooks());
	for (const auto& book : collection.getLibraryCollection()) {
		std::cout << book.getTitle() << std::endl;
	}

	return 0;
}
