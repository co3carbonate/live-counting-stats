// Header guard
#ifndef STATS_H
#define STATS_H

// Global variables for stats
vector<function<void(Chat)>> forEachMessage;
vector<function<void()>> afterAllMessages;

// Local includes
#include "stats/AccurateUpTo.hpp"
#include "stats/FirstCount.hpp"
#include "stats/HallOfCounters.hpp"
#include "stats/HallOfTrips.hpp"
#include "stats/KsParticipation.hpp"
#include "stats/DaysParticipation.hpp"
#include "stats/HallOfRepDigits.hpp"
#include "stats/HallOfPalindromes.hpp"

// Main function
void generateStats() {

	// Call main functions from local includes
	AccurateUpTo();
	FirstCount();
	HallOfCounters();
	HallOfTrips();
	KsParticipation();
	DaysParticipation();
	HallOfRepDigits();
	HallOfPalindromes();

	// Preparation
	cout << "Updating statistics:\n";
	auto start = chrono::system_clock::now();

	// Loop through all messages - starting from count 1
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

	auto end = chrono::system_clock::now();
	chrono::duration<double> elapsed = end - start;
	cout << "Successfully updated statistics (" <<
	setprecision(2) << fixed << elapsed.count() << "s)\n\n";


}




#endif