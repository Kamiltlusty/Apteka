#pragma once
#include <string>
#include <vector>
#include <deque>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include "Drug.h"
#include "Order.h"
#include "Client.h"

typedef std::vector<Drug> vD;
typedef std::vector<Client> vC;
typedef std::deque<Order> dO;

class Database {
public: 
	void loadDrugs(vD& drugs, const std::string& filename);
	void loadClientsOrders(dO& orders, const std::string& filename);
	void loadClients(vC& clients, const std::string& filename);
	void writeClientsOrders(dO& orders, const std::string& filename);
	void writeClients(vC& clients, const std::string& filename);
	void writeDrugs(vD& drugs, const std::string& filename);
};

