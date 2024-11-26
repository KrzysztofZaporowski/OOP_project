#include "Author.h"

Author::Author(const std::string& name, const std::string& lastname):name(name), lastname(lastname){}

std::string Author::getName() const{
	return name;
}

std::string Author::getLastname() const{
	return lastname;
}

