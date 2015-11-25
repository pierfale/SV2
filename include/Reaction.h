#ifndef _REACTION_H
#define _REACTION_H

#include "Species.h"

#include <map>

class Reaction {

public:
	Reaction(float speed);

	void add_reactant(unsigned int number, const Species& species);
	void add_product(unsigned int number, const Species& species);

	float speed() const;
	const std::map<Species, unsigned int>& reactants() const;
	const std::map<Species, unsigned int>& products() const;

private:
	float _speed;
	std::map<Species, unsigned int> _reactants;
	std::map<Species, unsigned int> _products;

};

#endif
