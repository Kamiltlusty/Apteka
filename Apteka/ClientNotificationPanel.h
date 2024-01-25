#include <string>
#include <vector>
#include <optional>
#include "Database.h"
#include "Client.h"

typedef std::vector<Client> vC;

class ClientNotificationPanel {
public:
	vC& getClients() { return clients; }
	void notifyClient(size_t clientId);
	void loadClients(Database& database, const std::string& filename) { database.loadClients(clients, filename); }
	void writeClients(Database& database, const std::string& filename) { database.writeClients(clients, filename); }
	std::optional<std::reference_wrapper<Client>> checkIsClientInSys(std::string telephoneNumber);

private:
	vC clients;
};