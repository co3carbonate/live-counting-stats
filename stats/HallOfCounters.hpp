#pragma once

// Variables
namespace HallOfCounters {
	map<string, int> HoCList;
	void main();
}

// Main function
void HallOfCounters::main() {

	// forEachMessage
	forEachMessage.push_back([](Chat chat) {

		// Exceptions
		if(chat.author == "[deleted]") return; // deleted user
		if(chat.stricken) return; // message stricken
		if(chat.count == "-1") return; // message does not contain number

		// Process
		if(HoCList.find(chat.author) == HoCList.end()) {
			// Users list does not contain author
			// Define new key
			HoCList.insert(pair<string, int>(chat.author, 0));
		}
		HoCList[chat.author]++;

	});

	// afterAllMessages
	afterAllMessages.push_back([]() {
		
		// Convert map into a vector of pairs
		vector<pair<string, int> > HoCArr;
		for(auto p : HoCList) {
			HoCArr.push_back(p);
		}

		// Sort vector of pairs based on .second
		sort(HoCArr.begin(), HoCArr.end(), [](pair<string, int> a, pair<string, int> b) {
			return a.second > b.second;
		});

		// Generate output
		string output;
		for(int i = 0; i < HoCArr.size(); i++) {
			output += to_string(i+1) + " | " + HoCArr[i].first + " | " + to_string(HoCArr[i].second) + '\n';
		}

		// Output
		ofstream out("output/HallOfCounters.txt");
		out << output;
		cout << "\tUpdated HallOfCounters.txt\n";
	});


	
}
