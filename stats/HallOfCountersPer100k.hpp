#pragma once

// Variables
namespace HallOfCountersPer100k {
	vector<map<string, int> > HoCPer100kList;
	int currentK = 0;
	void main();
}

// Main function
void HallOfCountersPer100k::main() {

	HoCPer100kList.push_back(map<string, int>());

	// forEachMessage
	forEachMessage.push_back([](Chat chat) {

		// Exceptions
		if(chat.author == "[deleted]") return; // deleted user
		if(chat.stricken) return; // message stricken
		if(chat.count == "-1") return; // message does not contain number
		if(chat.id == "98399ad6-77d0-11e6-9ce5-0e5c0099a997"
		|| chat.id == "e2d51cfc-1ec9-11e5-8540-0ee61c357d3b"
		|| chat.id == "94fe28ba-a60f-11e6-93c1-0eebf8235ba8"
		|| chat.id == "f813ee46-a6ad-11e6-8145-0e064f2e6070"
		|| chat.id == "c66a8c3c-98e4-11e6-a244-0e56c1175d95") return; // blacklisted messages

		// Process
		if(HoCPer100kList[currentK].find(chat.author) == HoCPer100kList[currentK].end()) {
			// Users list does not contain author
			// Define new key
			HoCPer100kList[currentK].insert(pair<string, int>(chat.author, 0));
		}
		HoCPer100kList[currentK][chat.author]++;

		int count;
		try {
			count = stoi(chat.count);
		}
		catch(out_of_range &exception) {
			// chat.count too large
			return;
		}
		if(count == ((currentK + 1) * 100000)) {
			currentK++;
			HoCPer100kList.push_back(map<string, int>());
		}

	});

	// afterAllMessages
	afterAllMessages.push_back([]() {
		
		for(int i = 0, len = HoCPer100kList.size(); i < len; i++) {
			// Convert map into a vector of pairs
			vector<pair<string, int> > HoCArr;
			for(auto p : HoCPer100kList[i]) {
				HoCArr.push_back(p);
			}

			// Sort vector of pairs based on .second
			sort(HoCArr.begin(), HoCArr.end(), [](pair<string, int> a, pair<string, int> b) {
				return a.second > b.second;	
			});

			// Generate output
			string output;
			for(int i = 0; i < HoCArr.size(); i++) {
				output += to_string(i+1) + " | " + HoCArr[i].first + " | " + addCommas(to_string(HoCArr[i].second)) + '\n';
			}

			// Output
			ofstream out("output/extras/HallOfCountersPer100k" +to_string(i+1)+ ".txt");
			out << output;
			cout << "\tUpdated extras/HallOfCountersPer100k" +to_string(i+1)+ ".txt\n";
		}
	});
	

	
}