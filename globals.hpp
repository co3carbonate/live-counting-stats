#pragma once

// Global variables
vector<Chat> data; // chat data
int l; // size of chat data vector

// Global functions
// Format a number string with commas
string addCommas(string num) {
	int insertPosition = num.length() - 3;
	while (insertPosition > 0) {
	    num.insert(insertPosition, ",");
	    insertPosition -= 3;
	}
	return num;
}

// Configuration
// These are the names of the standard stats functions to run
// (override if necessary)
vector<string> statsToRun
= {"AccurateUpTo", "FirstCount", "HallOfCounters", "HallOfTrips", "HallOf666s", "KsParticipation", "DaysParticipation", "HallOfRepDigits", "HallOfPalindromes"};
//= {"HallOfCountersPer100k", "NoOfCountsOverTime", "OddEvenRatio"};
