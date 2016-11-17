// Header guard
#ifndef GLOBALS_H
#define GLOBALS_H

// Global variables
vector<Chat> data; // chat data
int l; // size of chat data vector

// Configuration
// These are the names of the standard stats functions to run
// (override if necessary)
vector<string> statsToRun
= {"AccurateUpTo", "FirstCount", "HallOfCounters", "HallOfTrips", "KsParticipation", "DaysParticipation", "HallOfRepDigits", "HallOfPalindromes"};
//= {"HallOfCountersPer100k"};

#endif