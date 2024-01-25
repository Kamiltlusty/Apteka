#pragma once
#include <deque>
#include "Order.h"

typedef std::deque<Order> dO;

class ClientsOrders {
public:
	ClientsOrders() {}
	void loadClientsOrders(Database& database, const std::string& filename) { database.loadClientsOrders(orders, filename); }
	void writeClientsOrders(Database& database, const std::string& filename) { database.writeClientsOrders(orders, filename); }
	dO& getOrders() { return orders; }
private:
	dO orders;
};