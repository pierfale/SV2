#include "Species.h"
#include "Reaction.h"
#include "System.h"

int main() {


	Species a("A");
	Species b("B");
	Species c("C");
	Species d("D");


	Reaction r1(1.f);
	r1.add_reactant(2, a);
	r1.add_reactant(1, b);
	r1.add_product(1, c);

	Reaction r2(0.5f);
	r2.add_reactant(1, a);
	r2.add_reactant(1, c);
	r2.add_product(1, d);

	System s;

	s.add_reaction(r1);
	s.add_reaction(r2);

	// initial species number
	std::map<Species, unsigned int> init_species_number;
	init_species_number[a] = 150;
	init_species_number[b] = 50;
	init_species_number[c] = 10;
	init_species_number[d] = 0;

	Log logger;
	s.simulate(20.0f, init_species_number, logger);

	logger.save_to_file("result.csv");

	return 0;
}

