// Header guard
#ifndef KSPARTICIPATION_H
#define KSPARTICIPATION_H

// Variables
namespace {
	map<int, set<string> > KsParticipationArr;
}

// Main function
void KsParticipation() {

	// forEachMessage
	forEachMessage.push_back([](Chat chat) {

		// Exceptions
		if(chat.author == "[deleted]") return; // deleted user
		if(chat.stricken) return; // message has been stricken
		if(chat.count == "-1") return; // message does not contain number

		// Obtain current thousand (thisK)
		int thisK;
		try {
			thisK = stoi(chat.count);
		}
		catch(out_of_range &exception) {
			// chat.count too large
			return;
		}
		thisK = thisK + 999 - (thisK - 1) % 1000; // round up to nearest thousand

		// If the map does not contain this K
		if(KsParticipationArr.find(thisK) == KsParticipationArr.end()) {
			KsParticipationArr.insert(pair<int, set<string> >(thisK, {}));
		}

		KsParticipationArr[thisK].insert(chat.author);

	});

	// afterAllMessages
	afterAllMessages.push_back([]() {

		// Process leaderboard output
		// Leaderboard in map (unsorted)
		map<string, int> KsLeaderboard;
		for(auto i : KsParticipationArr) {
			for(auto j : i.second) {
				if(KsLeaderboard.find(j) == KsLeaderboard.end()) {
					KsLeaderboard.insert(pair<string, int>(j, 0));
				}
				KsLeaderboard[j]++;
			}
		}

		// Convert map to vector of pairs to sort based on .second
		vector<pair<string, int> > KsLeaderboardSorted(KsLeaderboard.begin(), KsLeaderboard.end());
		sort(KsLeaderboardSorted.begin(), KsLeaderboardSorted.end(),
			[](pair<string, int> a, pair<string, int> b) {
				return a.second > b.second;
			}
		);

		string KsParticipationOutput;
		for(int i = 0, len = KsLeaderboardSorted.size(); i < len; i++) {
			KsParticipationOutput += to_string(i+1) + " | " + KsLeaderboardSorted[i].first + " | " + to_string(KsLeaderboardSorted[i].second) + "\n";
		}


		// Output
		ofstream out("output/KsParticipation.txt");
		out << KsParticipationOutput;
		cout << "\tUpdated KsParticipation.txt\n";
		
	});


	
}

#endif