// Header guard
#ifndef STATS_H
#define STATS_H

// Global variables for stats
vector<function<void(Chat)>> forEachMessage;
vector<function<void()>> afterAllMessages;

// Local includes
#include "stats/FirstCount.hpp"
#include "stats/HallOfCounters.hpp"
#include "stats/HallOfTrips.hpp"
#include "stats/KsParticipation.hpp"

// Main function
void generateStats() {

	// Call main functions from local includes
	FirstCount();
	HallOfCounters();
	HallOfTrips();
	KsParticipation();

	// Loop through all messages - starting from count 1
	cout << "Updating statistics:\n";
	for(int i = l - 1; i >= 0; i--) {
		
		// Call forEachMessage
		for(int j = 0, len = forEachMessage.size(); j < len; j++) {
			(forEachMessage[j])(data[i]);
		}

	}

	// Call afterAllMessages
	for(int i = 0, len = afterAllMessages.size(); i < len; i++) {
		(afterAllMessages[i])();
	}

}




#endif