#ifndef _SPECIES_H
#define _SPECIES_H

#include <string>

class Species {

public:
	Species(const std::string& name);
	Species(const Species& that);

	bool operator<(const Species& that) const;

	const std::string& name() const;

private:
	std::string _name;
};

#endif
