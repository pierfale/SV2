#ifndef _SYSTEM_H
#define _SYSTEM_H

#include "Reaction.h"
#include "Log.h"

#include <vector>
#include <iostream>
#include <cmath>
#include <limits>
class System {


public:
	System();

	void add_reaction(const Reaction& reaction);

	void simulate(float tau_max, const std::map<Species, unsigned int>& species_number, Log& logger);

private:
	std::vector<Reaction> _reactions;

};

#endif
