#pragma once
#include <regex>
#include "Database.h"
#include "DrugsShelf.h"
#include "ClientNotificationPanel.h"
#include "ClientsOrders.h"


class ManagingSystem {
public:
	void welcomeUser();
	std::string takeDrugName();
	Database& getDatabase() { return database; }
	DrugsShelf& getDrugsShelf() { return ds; }
	ClientsOrders& getClientsOrders() { return co; }
	ClientNotificationPanel& getClientNotificationPanel() { return cnp; }
	void giveOutDrug(std::string& drugName);
	void DrugUnavailableInfo();
	std::string takeFirstName();
	std::string takeLastName();
	std::optional<std::string> takeTelephoneNumber();
	ManagingSystem() {}
private:
	Database database;
	DrugsShelf ds;
	ClientsOrders co;
	ClientNotificationPanel cnp;
};

