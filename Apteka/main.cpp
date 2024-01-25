#include <iostream>
#include <string>
#include <ctime>
#include <thread>
#include <optional>
#include "ManagingSystem.h"

using std::string;
using std::cin;
using std::cout;
using std::endl;

static int getSecond() {
	time_t currentTime = time(nullptr);
	tm* localTime = std::localtime(&currentTime);
	auto second = localTime->tm_sec;
	return second;
}

typedef std::optional<std::reference_wrapper<Client>> or_wC;
typedef std::optional<std::reference_wrapper<Drug>> or_wD;
typedef std::optional<std::string> oS;


void ClientCode() {
	setlocale(LC_ALL, "pl_PL");

	string drugsFile = "drugs.txt";
	string ordersFile = "clients_orders.txt";
	string clientsFile = "clients.txt";

	ManagingSystem ms;

	auto& ds = ms.getDrugsShelf();
	auto& co = ms.getClientsOrders();
	auto& cnp = ms.getClientNotificationPanel();
	auto& db = ms.getDatabase();

	auto& dsD = ds.getDrugs();
	auto& coO = co.getOrders();
	auto& cnpC = cnp.getClients();

	try {
		ds.loadDrugs(db, drugsFile);
		if (getSecond() % 2 == 0) ds.supplyDrugs(true);
		else ds.supplyDrugs(false);
		co.loadClientsOrders(db, ordersFile);
		cnp.loadClients(db, clientsFile);
		for (int i = 0; i < coO.size(); i++) {
			Order& order = coO.at(i);
			size_t drugId = order.getDrugID();
			if (dsD.at(drugId - 1).getAvailability()) { // id lekow maja numery od 1-30 poczatkowo
				cnp.notifyClient(order.getClientID());
				coO.erase(coO.begin() + i);
				i--;
			}
		}
		string drugName;
		or_wD foundDrug;
		ms.welcomeUser();
		for (int i = 0; i < 5; i++) {
			drugName = ms.takeDrugName();
			foundDrug = ds.findDrug(drugName);
			if (foundDrug) break;
			std::cout << "Leku " << drugName << " nie znaleziono spróbuj ponownie." << std::endl;
		}
		if (foundDrug) {
			auto& fDrugVG = foundDrug.value().get();
			if (fDrugVG.getAvailability()) {
				ms.giveOutDrug(drugName);
				fDrugVG.setAvailability(false);
			}
			else { // sprawdzanie zamiennika
				string substituteDrugName = fDrugVG.getSubstituteName();
				if (substituteDrugName != "brak") {
					foundDrug = ds.findDrug(substituteDrugName);
					if (foundDrug) {
						std::cout << "Wydanie zamiennika:" << std::endl;
						ms.giveOutDrug(substituteDrugName);
						fDrugVG.setAvailability(false);
					}
				}
				else {
					// brak leku i zamiennika, ale lek istnieje w naszej bazie
					oS telephoneNumber;
					for (int i = 0; i < 5; i++) {
						telephoneNumber = ms.takeTelephoneNumber();
						if (telephoneNumber) break;
					}
					if (telephoneNumber) {
						// sprawdz czy uzytkownik juz istnieje po numerze telefonu
						or_wC foundClient = cnp.checkIsClientInSys(telephoneNumber.value());
						if (!foundClient) {
							string firstName = ms.takeFirstName();
							string lastName = ms.takeLastName();
							cnpC.emplace_back(Client(0, firstName, lastName, telephoneNumber.value()));
							foundClient = std::ref(cnpC.at(cnpC.size() - 1));
						}
						auto& fClientVG = foundClient.value().get();
						coO.emplace_back(Order(fClientVG.getClientID(), fDrugVG.getDrugID()));
						cout << "Powiadomienie o dostêpnoœci leku przyœlemy Ci smsem." << endl;
					}
					else {
						cout << "Poda³eœ blêdny numer. Zamykanie systemu..." << endl;
					}
				}
			}
		}
		else cout << "Twoj lek nie jest dostêpny w naszej aptece." << endl;
		co.writeClientsOrders(db, ordersFile);
		cnp.writeClients(db, clientsFile);
		ds.writeDrugs(db, drugsFile);
	}
	catch (std::runtime_error& e) {
		std::cerr << e.what() << std::endl;
		std::exit(EXIT_FAILURE);
	}
	catch (std::invalid_argument& e) {
		std::cerr << e.what() << std::endl;
		std::exit(EXIT_FAILURE);
	}
}


int main(void) {
	ClientCode();

	cin.get();
	return 0;
}

/*
Lista lekow 
1 Acatar 0 Calperos
2 Acerola 0 brak
3 Bebilon 0 brak
4 Calperos 0 Acatar
5 Desmoxan 0 Entil
6 Destresan 0 brak
7 Elmex 0 Iladian
8 Entil 0 Desmoxan
9 Falvit 0 brak
10 Fastum 0 brak
11 Fenistil 0 brak
12 Gripex 0 brak
13 Hascosept 0 brak
14 Hascovir 0 brak
15 Ibum 0 Ibuprofen
16 Ibuprofen 0 Ibum
17 Ibuvit 0 brak
18 Iladian 0 Elmex
19 Jodyna 0 brak
20 K2 0 Optive
21 Lacrimal 0 brak
22 Magnezin 0 Plusz
23 Marimer 0 brak
24 Nanbiotic 0 brak
25 Naproxen 0 brak
26 Optive 0 K2
27 Pirolam 0 brak
28 Plusz 0 Magnezin
29 Sachol 0 brak
30 Salicylol 0 brak
*/
/*
Lista klientow
1 Alicja Rok 989888234
2 Adam Bred 981818124
3 Marek But 959345256
4 Rados³aw Arka 513555123
5 Konrad Ko³yska 626452255
6 Bogdan Baran 673776856
*/
/*
Lista zamowien
1 10
2 11
3 12
4 15
5 28
2 12
6 27
4 5
*/