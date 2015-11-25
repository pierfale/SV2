#ifndef _LOG_H
#define _LOG_H

#include "Species.h"

#include <map>
#include <vector>
#include <fstream>
#include <stdexcept>

class Log {

public:
	Log();

	void add(float time, const std::map<Species, unsigned int>& species_number);

	void save_to_file(const std::string& filename);

private:
	std::vector<std::pair<float, std::map<Species, unsigned int>>> _events;
};

#endif
