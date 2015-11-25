#include "Reaction.h"


Reaction::Reaction(float speed) : _speed(speed) {

}

void Reaction::add_reactant(unsigned int number, const Species& species) {
	_reactants.insert(std::pair<Species, unsigned int>(species, number));
}

void Reaction::add_product(unsigned int number, const Species& species) {
	_products.insert(std::pair<Species, unsigned int>(species, number));
}

float Reaction::speed() const {
	return _speed;
}

const std::map<Species, unsigned int>& Reaction::reactants() const {
	return _reactants;
}

const std::map<Species, unsigned int>& Reaction::products() const {
	return _products;
}
