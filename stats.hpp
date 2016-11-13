// Header guard
#ifndef STATS_H
#define STATS_H

// Global variables for stats
vector<function<void(Chat)>> forEachMessage;
vector<function<void()>> afterAllMessages;

// Local includes of stats to run

// Standard stats (in statsToRun vector by default)
#include "stats/AccurateUpTo.hpp"
#include "stats/FirstCount.hpp"
#include "stats/HallOfCounters.hpp"
#include "stats/HallOfTrips.hpp"
#include "stats/KsParticipation.hpp"
#include "stats/DaysParticipation.hpp"
#include "stats/HallOfRepDigits.hpp"
#include "stats/HallOfPalindromes.hpp"

// Additional stats (must be manually added to statsToRun vector)
//#include "stats/HallOfCountersPer100k.hpp"

// Main function
void generateStats() {

	// Setup
	forEachMessage.clear();
	afterAllMessages.clear();

	// Call main functions from stats to run
	for(int i = 0, len = statsToRun.size(); i < len; i++) {
		string c = statsToRun[i]; 
			 if(c == "AccurateUpTo") AccurateUpTo::main();
		else if(c == "FirstCount") FirstCount::main();
		else if(c == "HallOfCounters") HallOfCounters::main();
		else if(c == "HallOfTrips") HallOfTrips::main();
		else if(c == "KsParticipation") KsParticipation::main();
		else if(c == "DaysParticipation") DaysParticipation::main();
		else if(c == "HallOfRepDigits") HallOfRepDigits::main();
		else if(c == "HallOfPalindromes") HallOfPalindromes::main();
		//else if(c == "HallOfCountersPer100k") HallOfCountersPer100k();
	}

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