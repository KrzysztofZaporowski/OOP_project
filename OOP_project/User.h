#pragma once
#include <string>

class User{
public:
	User(std::string login, std::string password, std::string name, std::string lastname, std::string email);
	bool logIn(std::string login, std::string password);
	bool logOut(std::string login, std::string password);
	std::string getLogin();
	std::string getPassword();
	std::string getName();
	std::string getLastname();
	void setLogin();
	void setPassword();
	void setEmail();
protected:
	std::string login;
	std::string password;
	std::string name;
	std::string lastname;
	std::string email;
};

