#pragma
#include <vector>
#include <optional>
#include "Drug.h"
#include "Database.h"

using std::vector;
typedef vector<Drug> vD;

class DrugsShelf {
public:
	void loadDrugs(Database& database, const std::string& filename) { database.loadDrugs(drugs, filename); }
	void writeDrugs(Database& database, const std::string& filename) { database.writeDrugs(drugs, filename); }
	vD& getDrugs() { return drugs; }
	void supplyDrugs(bool);
	std::optional<std::reference_wrapper<Drug>> findDrug(const std::string& drugName);
private:
	vD drugs;
};