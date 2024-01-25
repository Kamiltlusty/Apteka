#pragma once
#include <string>
#include <iostream>
#include <stdexcept>

class Client {
public:
	static size_t clientsCounter;
	size_t getClientID() { return c_id; }
	std::string getFirstName() { return f_name; }
	std::string getLastName() { return l_name; }
	std::string getTelephoneNumber() { return t_number; }
	Client(size_t clientId, std::string fName = "imie", std::string lName = "nazwisko", std::string tNumber = "000000000");
private:
	size_t c_id;
	std::string f_name;
	std::string l_name;
	std::string t_number;
};
