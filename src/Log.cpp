#include "Log.h"

Log::Log() {

}

void Log::add(float time, const std::map<Species, unsigned int>& species_number) {
	_events.push_back(std::pair<float, std::map<Species, unsigned int>>(time, species_number));
}

void Log::save_to_file(const std::string& filename) {
	std::ofstream file(filename, std::ios::out | std::ios::trunc);

	if(!file.is_open())
		throw std::runtime_error("Unable to open "+filename);

	// Header
	file << "Time";
	for(const auto& species_number : _events[0].second) {
		file << "," << species_number.first.name();
	}
	file << std::endl;

	// Content
	for(const auto& time_event : _events) {
		file << time_event.first;
		for(const auto& species_number : time_event.second) {
			file << "," << species_number.second;
		}
		file << std::endl;
	}
}
