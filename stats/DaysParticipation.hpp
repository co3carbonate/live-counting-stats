#pragma once

// Variables
namespace DaysParticipation {
	time_t nextDay;
	map<time_t, set<string> > DaysParticipationArr;
	void main();
}

// Main function
void DaysParticipation::main() {

	// Init
	nextDay = data[l - 1].date;

	// forEachMessage
	forEachMessage.push_back([](Chat chat) {

		// Exceptions
		if(chat.author == "[deleted]") return; // deleted user
		if(chat.stricken) return; // message has been stricken
		if(chat.count == "-1") return; // message does not contain number

		// Change to the next day
		while(chat.date >= nextDay) {
			nextDay += 86400;
			DaysParticipationArr.insert(pair<time_t, set<string> >(nextDay, {}));
		}

		DaysParticipationArr[nextDay].insert(chat.author);

	});

	// afterAllMessages
	afterAllMessages.push_back([]() {

		// Process leaderboard output
		// Leaderboard in map (unsorted)
		map<string, int> DaysLeaderboard;
		for(auto i : DaysParticipationArr) {
			for(auto j : i.second) {
				if(DaysLeaderboard.find(j) == DaysLeaderboard.end()) {
					DaysLeaderboard.insert(pair<string, int>(j, 0));
				}
				DaysLeaderboard[j]++;
			}
		}

		// Convert map to vector of pairs to sort based on .second
		vector<pair<string, int> > DaysLeaderboardSorted(DaysLeaderboard.begin(), DaysLeaderboard.end());
		sort(DaysLeaderboardSorted.begin(), DaysLeaderboardSorted.end(),
			[](pair<string, int> a, pair<string, int> b) {
				return a.second > b.second;
			}
		);

		string DaysParticipationOutput;
		for(int i = 0, len = DaysLeaderboardSorted.size(); i < len; i++) {
			DaysParticipationOutput += to_string(i+1) + " | " + DaysLeaderboardSorted[i].first + " | " + to_string(DaysLeaderboardSorted[i].second) + "\n";
		}


		// Output
		ofstream out("output/DaysParticipation.txt");
		out << DaysParticipationOutput;
		cout << "\tUpdated DaysParticipation.txt\n";
		
	});


	
}
