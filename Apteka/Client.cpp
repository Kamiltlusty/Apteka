#include "Client.h"

size_t Client::clientsCounter = 0;

Client::Client(size_t clientId, std::string fName, std::string lName, std::string tNumber) : f_name(fName), l_name(lName), t_number(tNumber) {
	if (clientId == -1) c_id = 0; // tworzenie klienta domyslnego
	else if (clientId >= 0) c_id = ++clientsCounter; // tworzenie nowego klienta/wczytywanie z pliku
	else throw std::invalid_argument("B³¹d wprowadzonej wartosci id klienta.");
}