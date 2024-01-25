#include "ManagingSystem.h"

void ManagingSystem::welcomeUser() {
    std::cout << "Witaj uzytkowniku." << std::endl;
}

std::string ManagingSystem::takeDrugName() {
    std::cout << "Podaj nazwe leku, którego potrzebujesz: ";
    std::string nazwa;
    std::cin >> nazwa;
    return nazwa;
}

void ManagingSystem::giveOutDrug(std::string& drugName) {
    std::cout << "Oto twoj lek: " << drugName << std::endl;
}

void ManagingSystem::DrugUnavailableInfo() {
    std::cout << "Twoj lek istnieje w naszej bazie, jednak¿e nie jest aktualnie dostêpny." << std::endl
        << "Zostaw nam swoje podstawowe dane, a my powiadomimy Ciê, gdy lek bêdzie dostêpny." << std::endl;
}

std::string ManagingSystem::takeFirstName() {
    std::cout << "Uzytkowniku podaj swoje imie: ";
    std::string fName;
    std::cin >> fName;
    return fName;
}

std::string ManagingSystem::takeLastName() {
    std::cout << "Uzytkowniku podaj swoje nazwisko: ";
    std::string lName;
    std::cin >> lName;
    return lName;
}

std::optional<std::string> ManagingSystem::takeTelephoneNumber() {
    std::regex telephone_num_pl("\\d{9}");
    std::cout << "Uzytkowniku podaj swoj numer telefonu: ";
    std::string tNum;
    std::cin >> tNum;
    if (std::regex_match(tNum, telephone_num_pl)) {
        return tNum;
    }
    return {};
}
