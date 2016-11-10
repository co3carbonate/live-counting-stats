// Header guard
#ifndef HALLOFPALINDROMES_H
#define HALLOFPALINDROMES_H

// Variables
namespace {
	vector<string> palindromes;
	map<string, int> palindromesLeaderboard;
	string HallOfPalindromesOutput;
}

// Main function
void HallOfPalindromes() {

	// forEachMessage
	forEachMessage.push_back([](Chat chat) {

		// Exceptions
		if(chat.id == "b1e87ca4-7311-11e6-bbc9-0e296602ce9b" ||
           chat.id == "3844c4c-6f0a-11e6-a07f-0e07bfd2cbaf" ||
           chat.id == "ad16f994-9a03-11e6-ba7a-0e5676d6e010" ||
           chat.id == "52bb2d10-815f-11e6-b296-0eea21cc2a75" ||
           chat.id == "e2e4d2d4-6c83-11e5-a166-0e355ac73a6f" ||
           chat.id == "d489b7c2-6c83-11e5-9e03-0e313743e45f" ||
           chat.id == "d37c57fe-6c83-11e5-b5cc-0ed4497f342d" ||
           chat.id == "d1448c5e-6c83-11e5-8104-0e6b3fdbebb1" ||
           chat.id == "d7b7ed64-6c7f-11e5-bdb5-0e1d3ee68d31" ||
           chat.id == "d6fe904e-6c7f-11e5-893b-0eb6627f4805" ||
           chat.id == "ce257c9e-6c7f-11e5-9cee-0eb6627f4805" ||
           chat.id == "3454847e-6c12-11e5-9680-0eb7787afe7f" ||
           chat.id == "c57395a2-6c0e-11e5-b64a-0ed4497f342d" ||
           chat.id == "aab8d164-6c0e-11e5-b554-0e1d3ee68d31" ||
           chat.id == "a840ca72-6c0e-11e5-88e8-0eb4554fb32f") 
			return; // spam message
		if(chat.stricken) return; // message has been stricken
		if(chat.count == "-1") return; // message does not contain count

		// Terminate if string is not a palindromes
		if(chat.count.size() <= 2) return; // must have at least 3 digits
		string reversed = chat.count;
		reverse(reversed.begin(), reversed.end());
		if(chat.count != reversed) return;

		// Terminate if map already contains this palindrome
		if(find(palindromes.begin(), palindromes.end(), chat.count) != palindromes.end()) {
			return;
		}
		palindromes.push_back(chat.count);

		// Update leaderboard
		if(chat.author != "[deleted]") {
			if(palindromesLeaderboard.find(chat.author) == palindromesLeaderboard.end()) {
				palindromesLeaderboard.insert(pair<string, int>(chat.author, 0));
			}
			palindromesLeaderboard[chat.author]++;
		}

		// Output
		HallOfPalindromesOutput = "* [" +chat.count+ "](https://www.reddit.com/live/ta535s1hq2je/updates/" +chat.id+ ") - " +chat.author+ "\n" + HallOfPalindromesOutput;

	});

	// afterAllMessages
	afterAllMessages.push_back([]() {

		// Process leaderboard output
		// Convert map to vector of pairs to sort based on .second
		vector<pair<string, int> > palindromesLeaderboardSorted(palindromesLeaderboard.begin(), palindromesLeaderboard.end());
		string palindromesLeaderboardString;
		
		sort(palindromesLeaderboardSorted.begin(), palindromesLeaderboardSorted.end(),
			[](pair<string, int> a, pair<string, int> b) {
				return a.second > b.second;
			}
		);

		for(int i = 9; i >= 0; i--) {
			palindromesLeaderboardString = to_string(i+1) + " | " + palindromesLeaderboardSorted[i].first + " | " + to_string(palindromesLeaderboardSorted[i].second) + "\n" + palindromesLeaderboardString;
		}


		// Output
		ofstream out("output/HallOfPalindromes.txt");
		out << palindromesLeaderboardString + "\n###Palindromes\n\n" + HallOfPalindromesOutput;
		cout << "\tUpdated HallOfPalindromes.txt\n";
		
	});


	
}

#endif