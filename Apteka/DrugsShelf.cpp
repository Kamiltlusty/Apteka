#include "DrugsShelf.h"

void DrugsShelf::supplyDrugs(bool isSupplier1) {
	if (isSupplier1) {
		for (int i = 0; i < drugs.size(); i+=2) {
			auto& drug = drugs.at(i);
			if (!drug.getAvailability()) drug.setAvailability(true);
		}
	}
	else {
		for (int i = 1; i < drugs.size(); i += 2) {
			auto& drug = drugs.at(i);
			if (!drug.getAvailability()) drug.setAvailability(true);
		}
	}
}

std::optional<std::reference_wrapper<Drug>> DrugsShelf::findDrug(const std::string& drugName) {
	for (auto& drug : drugs) {
		if (drug.getDrugName() == drugName) return std::ref(drug);
	}
	return {};
}
