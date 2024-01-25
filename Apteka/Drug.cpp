#include "Drug.h"

size_t Drug::drugsCounter = 0;

Drug::Drug(size_t drug_id, std::string drugName, bool available, std::string substituteName) : d_name(drugName), avail(available), s_name(substituteName) {
	if (drug_id == -1) d_id = 0; // tworzenie leku domyslnego
	else if (drug_id >= 0) d_id = ++drugsCounter; // tworzenie nowego leku/wczytywanie z pliku
	else throw std::invalid_argument("B³¹d wprowadzonej wartosci id leku.");
}