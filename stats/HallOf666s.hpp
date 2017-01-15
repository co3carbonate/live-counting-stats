#pragma once

// Variables
namespace HallOf666s {
	vector<string> trips;
	map<string, int> tripsLeaderboard;
	string output;
	void main();
}

// Main function
void HallOf666s::main() {

	// forEachMessage
	forEachMessage.push_back([](Chat chat) {

		// Exceptions
		if(chat.id == "3454847e-6c12-11e5-9680-0eb7787afe7f" || 
		   chat.id == "ad16f994-9a03-11e6-ba7a-0e5676d6e010" ||
		   chat.id == "aec2de70-298a-11e4-a128-12313b0ea0a5" ||
		   chat.id == "d0def8c8-6c0e-11e5-bd45-0e7eccdaeabd" ||
		   chat.id == "35499770-6c12-11e5-bc53-0e6b3fdbebb1" ||
		   chat.id == "3649d73e-6c12-11e5-a397-0eb4554fb32f" ||
		   chat.id == "3776daee-6c12-11e5-bf80-0eb6627f4805") 
			return; // spam message
		if(chat.stricken) return; // message has been stricken
		if(chat.count == "-1") return; // message does not contain count

		// Terminate if string does not end with 666
		string suffix = "666";
		if(chat.count.size() < suffix.size()) return; // shorter than suffix
		if(0 != chat.count.compare(chat.count.length() - suffix.length(), suffix.length(), suffix)) {
			return;
		}

		// Terminate if map already contains this trip
		if(find(trips.begin(), trips.end(), chat.count) != trips.end()) {
			return;
		}
		trips.push_back(chat.count);

		// Update leaderboard
		if(chat.author != "[deleted]") {
			if(tripsLeaderboard.find(chat.author) == tripsLeaderboard.end()) {
				tripsLeaderboard.insert(pair<string, int>(chat.author, 0));
			}
			tripsLeaderboard[chat.author]++;
		}

		// Output
		output = "* [" +addCommas(chat.count)+ "](https://www.reddit.com/live/ta535s1hq2je/updates/" +chat.id+ ") - " +chat.author+ "\n" + output;

	});

	// afterAllMessages
	afterAllMessages.push_back([]() {

		// Process leaderboard output
		// Convert map to vector of pairs to sort based on .second
		vector<pair<string, int> > tripsLeaderboardSorted(tripsLeaderboard.begin(), tripsLeaderboard.end());
		string tripsLeaderboardString;
		
		sort(tripsLeaderboardSorted.begin(), tripsLeaderboardSorted.end(),
			[](pair<string, int> a, pair<string, int> b) {
				return a.second > b.second;
			}
		);

		for(int i = 9; i >= 0; i--) {
			tripsLeaderboardString = to_string(i+1) + " | " + tripsLeaderboardSorted[i].first + " | " + to_string(tripsLeaderboardSorted[i].second) + "\n" + tripsLeaderboardString;
		}


		// Output
		ofstream out("output/HallOf666s.txt");
		out << tripsLeaderboardString + "\n###666s\n\n" + output;
		cout << "\tUpdated HallOf666s.txt\n";
		
	});


	
}
