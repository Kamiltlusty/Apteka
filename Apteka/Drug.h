#pragma once
#include <string>
#include <stdexcept>

class Drug {
public:
	static size_t drugsCounter;
	size_t getDrugID() { return d_id; }
	std::string getDrugName() { return d_name; }
	bool getAvailability() { return avail; }
	std::string getSubstituteName() { return s_name; }
	void setAvailability(bool availability) { avail = availability; }
	Drug(size_t drugID, std::string drugName = "lek_domyslny", bool available = false, std::string substituteName = "brak");
private:
	size_t d_id;
	std::string d_name;
	bool avail;
	std::string s_name;
};

