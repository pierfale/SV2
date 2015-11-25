#include "Species.h"

Species::Species(const std::string& name) : _name(name) {

}

Species::Species(const Species& that) : _name(that._name) {

}

bool Species::operator<(const Species& that) const {
	return _name < that._name;
}

const std::string& Species::name() const {
	return _name;
}
