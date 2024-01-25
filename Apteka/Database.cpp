#include "Database.h"

void Database::loadDrugs(vD& drugs, const std::string& filename) {
	std::ifstream ifs(filename);
	if (!ifs.is_open()) throw std::runtime_error("Blad otwarcia pliku.");
	if (ifs.peek() == std::ifstream::traits_type::eof()) throw std::runtime_error("Blad plik jest pusty.");

	size_t tmp_d_id;
	std::string tmp_d_name;
	bool tmp_avail;
	std::string tmp_substitute_name;
	std::string line;
	while (std::getline(ifs, line)) {
		std::istringstream iss(line);
		if (iss >> tmp_d_id >> tmp_d_name >> tmp_avail >> tmp_substitute_name) drugs.emplace_back(Drug(tmp_d_id, tmp_d_name, tmp_avail, tmp_substitute_name));
		else throw std::runtime_error("Blad odczytu z lini.");
	}
}

void Database::loadClientsOrders(dO& orders, const std::string& filename) {
	std::ifstream ifs(filename);
	if (ifs.good()) {
		if (ifs.peek() == std::ifstream::traits_type::eof()) {
			return;
		}
		size_t tmp_c_id;
		size_t tmp_d_id;
		std::string line;
		while (std::getline(ifs, line)) {
			std::istringstream iss(line);
			if (iss >> tmp_c_id >> tmp_d_id) orders.emplace_back(Order(tmp_c_id, tmp_d_id));
			else throw std::runtime_error("Blad odczytu z lini.");
		}
	}
}

void Database::loadClients(vC& clients, const std::string& filename) {
	std::ifstream ifs(filename);
	if (ifs.good()) {
		if (ifs.peek() == std::ifstream::traits_type::eof()) {
			return;
		}
		size_t tmp_c_id;
		std::string tmp_f_name;
		std::string tmp_l_name;
		std::string tmp_t_number;
		std::string line;
		while (std::getline(ifs, line)) {
			std::istringstream iss(line);
			if (iss >> tmp_c_id >> tmp_f_name >> tmp_l_name >> tmp_t_number) clients.emplace_back(Client(tmp_c_id, tmp_f_name, tmp_l_name, tmp_t_number));
			else throw std::runtime_error("Blad odczytu z lini.");
		}
	}
}

void Database::writeClientsOrders(dO& orders, const std::string& filename) {
	std::ofstream ofs(filename);
	if (!ofs.is_open()) throw std::runtime_error("Blad otwarcia pliku.");

	for (auto& o : orders)
		ofs << o.getClientID() << " " << o.getDrugID() << std::endl;
}

void Database::writeClients(vC& clients, const std::string& filename) {
	std::ofstream ofs(filename);
	if (!ofs.is_open()) throw std::runtime_error("Blad otwarcia pliku.");

	for (auto& c : clients)
		ofs << c.getClientID() << " " << c.getFirstName() << " " << c.getLastName() << " " << c.getTelephoneNumber() << std::endl;
}

void Database::writeDrugs(vD& drugs, const std::string& filename) {
	std::ofstream ofs(filename);
	if (!ofs.is_open()) throw std::runtime_error("Blad otwarcia pliku.");

	for (auto& d : drugs)
		ofs << d.getDrugID() << " " << d.getDrugName() << " " << d.getAvailability() << " " << d.getSubstituteName() << std::endl;
}
