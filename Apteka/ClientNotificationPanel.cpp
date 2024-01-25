#include "ClientNotificationPanel.h"

void ClientNotificationPanel::notifyClient(size_t clientId) {
	Client client = clients.at(clientId - 1);
	std::string clientTNum = client.getTelephoneNumber();
	std::cout << "Wysylanie sms na numer: " << clientTNum << std::endl
		<< "Kliencie twoj lek jest juz dostepny w aptece." << std::endl;
}

std::optional<std::reference_wrapper<Client>> ClientNotificationPanel::checkIsClientInSys(std::string telephoneNumber) {
	for (auto& c : clients) {
		if (c.getTelephoneNumber() == telephoneNumber) return std::ref(c);
	}
	return {};
}


