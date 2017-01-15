#pragma once

// Variables
namespace HallOfPalindromes {
	vector<string> palindromes;
	map<string, int> palindromesLeaderboard;
	string output;
	void main();
}

// Main function
void HallOfPalindromes::main() {

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
           chat.id == "a840ca72-6c0e-11e5-88e8-0eb4554fb32f" ||
           chat.id == "05c940a0-6c84-11e5-8f17-0e96416492c1" ||
           chat.id == "3776daee-6c12-11e5-bf80-0eb6627f4805" ||
           chat.id == "3649d73e-6c12-11e5-a397-0eb4554fb32f" ||
           chat.id == "35499770-6c12-11e5-bc53-0e6b3fdbebb1" ||
           chat.id == "bcbdc7ca-6c0e-11e5-beee-0eb7787afe7f" ||
           chat.id == "bbe024a6-6c0e-11e5-969b-0e49db09c135" ||
           chat.id == "baccc0c4-6c0e-11e5-ad0c-0e96416492c1" ||
           chat.id == "b78d14ea-6c0e-11e5-97f7-0e254636921b" ||
           chat.id == "b5e1f08e-6c0e-11e5-82cb-0e355ac73a6f" ||
           chat.id == "b3ae2ba2-6c0e-11e5-b1e0-0edc22c2349d" ||
           chat.id == "b1efd8d8-6c0e-11e5-90be-0e49db09c135" ||
           chat.id == "b001f088-6c0e-11e5-b1fd-0e7d1b48e76b" ||
           chat.id == "ad4991ca-6c0e-11e5-afd3-0e7ace5d854b" ||
           chat.id == "a73601f6-6c0e-11e5-a677-0e53d95baa8f" ||
           chat.id == "a4119210-6c0e-11e5-8969-0e254636921b" ||
           chat.id == "a1ee758e-6c0e-11e5-9b7c-0ed3bcacbc51" ||
           chat.id == "a02cb882-6c0e-11e5-877e-0eb7787afe7f" ||
           chat.id == "9dec4f10-6c0e-11e5-a836-0ea7f7edc7ed" ||
           chat.id == "9b615358-6c0e-11e5-b3d6-0e313743e45f" ||
           chat.id == "996abada-6c0e-11e5-a759-0e7311dec0a7" ||
           chat.id == "97e6dd06-6c0e-11e5-9f52-0eb6627f4805" ||
           chat.id == "96728178-6c0e-11e5-a69c-0eb4554fb32f" ||
           chat.id == "9501c628-6c0e-11e5-8e0e-0e254636921b" ||
           chat.id == "93b293ba-6c0e-11e5-b1d6-0edc22c2349d" ||
           chat.id == "92587994-6c0e-11e5-a770-0eb6627f4805" ||
           chat.id == "074d3b3c-6c0e-11e5-ba15-0e53d95baa8f") 
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
		output = "* [" +addCommas(chat.count)+ "](https://www.reddit.com/live/ta535s1hq2je/updates/" +chat.id+ ") - " +chat.author+ "\n" + output;

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
		out << palindromesLeaderboardString + "\n###Palindromes\n\n" + output;
		cout << "\tUpdated HallOfPalindromes.txt\n";
		
	});


	
}
