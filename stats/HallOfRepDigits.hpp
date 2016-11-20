#pragma once

// Variables
namespace HallOfRepDigits {
	vector<string> repDigits;
	map<string, int> repDigitsLeaderboard;
	string output;
	void main();
}

// Main function
void HallOfRepDigits::main() {

	// forEachMessage
	forEachMessage.push_back([](Chat chat) {

		// Exceptions
		if(chat.id == "cfa5edec-6c7f-11e5-9d86-0e7eccdaeabd" || 
		   chat.id == "ceca88e2-6c7f-11e5-9f62-0e7d1b48e76b" ||
		   chat.id == "bc9924d0-6c7f-11e5-bf7e-0e1d3ee68d31" ||
		   chat.id == "bbe00f22-6c7f-11e5-904f-0e49db09c135" ||
		   chat.id == "5e922e6c-6c12-11e5-9e5e-0e1d3ee68d31" ||
		   chat.id == "4d4d0e24-6c12-11e5-96eb-0e53d95baa8f") 
			return; // spam message
		if(chat.stricken) return; // message has been stricken
		if(chat.count == "-1") return; // message does not contain count

		// Terminate if string is not a rep-digit number
		int length = chat.count.size();
		if(length <= 2 || length % 2 > 0) return; // must be even number of digits
		string s1 = chat.count.substr(0, length / 2);
		string s2 = chat.count.substr(length / 2, length / 2);
		if(s1 != s2) return;

		// Terminate if map already contains this rep-digit
		if(find(repDigits.begin(), repDigits.end(), chat.count) != repDigits.end()) {
			return;
		}
		repDigits.push_back(chat.count);

		// Update leaderboard
		if(chat.author != "[deleted]") {
			if(repDigitsLeaderboard.find(chat.author) == repDigitsLeaderboard.end()) {
				repDigitsLeaderboard.insert(pair<string, int>(chat.author, 0));
			}
			repDigitsLeaderboard[chat.author]++;
		}

		// Output
		output = "* [" +chat.count+ "](https://www.reddit.com/live/ta535s1hq2je/updates/" +chat.id+ ") - " +chat.author+ "\n" + output;

	});

	// afterAllMessages
	afterAllMessages.push_back([]() {

		// Process leaderboard output
		// Convert map to vector of pairs to sort based on .second
		vector<pair<string, int> > repDigitsLeaderboardSorted(repDigitsLeaderboard.begin(), repDigitsLeaderboard.end());
		string repDigitsLeaderboardString;
		
		sort(repDigitsLeaderboardSorted.begin(), repDigitsLeaderboardSorted.end(),
			[](pair<string, int> a, pair<string, int> b) {
				return a.second > b.second;
			}
		);

		for(int i = 9; i >= 0; i--) {
			repDigitsLeaderboardString = to_string(i+1) + " | " + repDigitsLeaderboardSorted[i].first + " | " + to_string(repDigitsLeaderboardSorted[i].second) + "\n" + repDigitsLeaderboardString;
		}


		// Output
		ofstream out("output/HallOfRepDigits.txt");
		out << repDigitsLeaderboardString + "\n###Repeating Digits\n\n" + output;
		cout << "\tUpdated HallOfRepDigits.txt\n";
		
	});


	
}
