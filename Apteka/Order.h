#pragma once

class Order {
public:
	size_t getClientID() { return c_id; }
	size_t getDrugID() { return d_id; }
	Order(size_t clientId, size_t drugId) : c_id(clientId), d_id(drugId) {}
private:
	size_t c_id;
	size_t d_id;
};
