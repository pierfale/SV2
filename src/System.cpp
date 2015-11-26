#include "System.h"

System::System() {

}

void System::add_reaction(const Reaction& reaction) {
	_reactions.push_back(reaction);
}

void System::simulate(float max_time, const std::map<Species, unsigned int>& species_number, Log& logger) {

	std::map<Species, unsigned int> current_species_number(species_number);
	std::vector<float> h;
	std::vector<float> a;

	float sum_a_h = 0;
/*
	for(const Reaction& reaction : _reactions) {

		unsigned int current_h = 1;
		for(const auto& reactant : reaction.reactants()) {
			current_h *= reactant.second;
		}

		a.push_back(reaction.speed());
		h.push_back(current_h);

		sum_a_h += current_h*reaction.speed();
	}*/

	float current_time = 0.0f;

	std::cout << "Start simulation ..." << std::endl;

	while(current_time < max_time) {

		// Update variable
		h.clear();
		a.clear();
		sum_a_h = 0;
		for(const Reaction& reaction : _reactions) {
			unsigned int current_h = 1;
			for(const auto& reactant : reaction.reactants()) {
				current_h *= current_species_number[reactant.first]/reactant.second;
			}

			a.push_back(reaction.speed());
			h.push_back(current_h);

			sum_a_h += current_h*reaction.speed();
		}

		if(sum_a_h == 0) // no more reaction
			break;

		// Tau
		float tau = (1.0f/sum_a_h)*log(1.0f/((float)rand()/std::numeric_limits<int>::max()));
		current_time += tau;

		// I
		float rand_pointer = ((float)rand()/std::numeric_limits<int>::max())*sum_a_h;
		float sum = 0;
		unsigned int i;
		for(i=0;; i++) {
			if(h[i]*a[i] == 0)
				continue;

			sum += h[i]*a[i];

			if(rand_pointer < sum || i == h.size())
				break;
		}



		// State
		Reaction& current_reaction = _reactions[i];
		for(const auto& reactant : current_reaction.reactants()) {
			current_species_number[reactant.first] -= reactant.second;
		}

		for(const auto& product: current_reaction.products()) {
			current_species_number[product.first] += product.second;
		}

		logger.add(current_time, current_species_number);
	}

	std::cout << "End of simulation" << std::endl;



}
