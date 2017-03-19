#pragma once

// Variables
namespace NoOfCountsOverTime {
	time_t nextDay = 1406131200;
	map<time_t, int > DayCounts;
	void main();
}

// Main function
void NoOfCountsOverTime::main() {

	// forEachMessage
	forEachMessage.push_back([](Chat chat) {

		// Exceptions
		if(chat.author == "[deleted]") return; // deleted user
		if(chat.stricken) return; // message has been stricken
		if(chat.count == "-1") return; // message does not contain number

		// Change to the next day
		while(chat.date >= nextDay) {
			nextDay += 86400;
			DayCounts.insert(pair<time_t, int >(nextDay, DayCounts[nextDay - 86400]));
		}

		DayCounts[nextDay]++;

	});

	// afterAllMessages
	afterAllMessages.push_back([]() {

		// Process table output
		string output = "";
		for(auto p : DayCounts) {
			time_t currentDay = p.first;
			int count = p.second;
			struct tm *timeInfo = gmtime(&currentDay);

			char buffer[64];
			strftime(buffer, sizeof(buffer), "%d %b '%y", gmtime(&currentDay));
			string date_string = string(buffer);

			output += date_string+ " | " +addCommas(to_string(count))+ "\n";
		}

		// Output
		ofstream out("output/extras/NoOfCountsOverTime.txt");
		out << output;
		cout << "\tUpdated NoOfCountsOverTime.txt\n";
		
	});


	
}
