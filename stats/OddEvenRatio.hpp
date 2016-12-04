#pragma once

// Variables
namespace OddEvenRatio {
	map<string, pair<int, pair<int, int> > > OddEvenList;
	void main();
}

// Main function
void OddEvenRatio::main() {

	// forEachMessage
	forEachMessage.push_back([](Chat chat) {

		// Exceptions
		if(chat.author == "[deleted]") return; // deleted user
		if(chat.stricken) return; // message stricken
		if(chat.count == "-1") return; // message does not contain number

		// Process
		if(OddEvenList.find(chat.author) == OddEvenList.end()) {
			// Users list does not contain author
			// Define new key
			OddEvenList.insert(pair<string, pair<int, pair<int, int>>>({chat.author, {0, {0, 0}}}));
		}
		OddEvenList[chat.author].first++;

		// Add to even / odd
		char lastChar = chat.count.back();
		bool even = (lastChar == '0' || lastChar == '2' || lastChar == '4' || lastChar == '6' || lastChar == '8');
		if(!even) OddEvenList[chat.author].second.first++;
		else OddEvenList[chat.author].second.second++;

	});

	// afterAllMessages
	afterAllMessages.push_back([]() {
		
		// Convert map into a vector of pairs
		vector<pair<string, pair<int, pair<int, int>>>> OddEvenArr;
		for(auto p : OddEvenList) {
			OddEvenArr.push_back(p);
		}

		// Sort vector of pairs based on .second.first
		sort(OddEvenArr.begin(), OddEvenArr.end(), [](pair<string, pair<int, pair<int, int>>> a, pair<string, pair<int, pair<int, int>>> b) {
			return a.second.first > b.second.first;
		});

		// Generate output
		string output;
		for(int i = 0; i < OddEvenArr.size(); i++) {
			output += to_string(i+1) + " | " + OddEvenArr[i].first + " | " + to_string(OddEvenArr[i].second.first);
			double oddRatio = (double)((double)OddEvenArr[i].second.second.first / (double)OddEvenArr[i].second.first) * (double)100;
			double evenRatio = (double)((double)OddEvenArr[i].second.second.second / (double)OddEvenArr[i].second.first) * (double)100;
			char oddStr[24], evenStr[24]; 
			sprintf(oddStr, "%.2f", oddRatio);
			sprintf(evenStr, "%.2f", evenRatio);
			output += " | ";
			output += oddStr;
			output += " | ";
			output += evenStr;
			output += '\n';
		}

		// Output
		ofstream out("output/extras/OddEvenRatio.txt");
		out << output;
		cout << "\tUpdated OddEvenRatio.txt\n";
	});


	
}
