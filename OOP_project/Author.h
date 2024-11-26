#pragma once
#include <string>
#include "Book.h"

class Author{
public:
	Author(const std::string& name, const std::string& lastname);
	std::string getName() const;
	std::string getLastname() const;
private:
	std::string name;
	std::string lastname;
};

