#pragma once

// Variables
namespace FirstCount {
	vector<string> usersAnalysed;
	string output;
	void main();
}

// Main function
void FirstCount::main() {

	// forEachMessage
	forEachMessage.push_back([](Chat chat) {

		// Exceptions
		if(chat.author == "[deleted]") return; // deleted user
		if(chat.stricken) return; // message stricken
		if(chat.count == "-1") return; // message does not contain number
		if(find(usersAnalysed.begin(), usersAnalysed.end(), chat.author) != usersAnalysed.end()) { // current user already accounted for
			return;
		}

		usersAnalysed.push_back(chat.author);

		// Process
		replace(chat.body.begin(), chat.body.end(), '\n', ' ');
		chat.body = "[" +chat.body+ "](https://www.reddit.com/live/ta535s1hq2je/updates/" +chat.id+ ")";
		output = chat.author + " | " +chat.body+ " | " +chat.date_string+ "\n" + output;

	});

	// afterAllMessages
	afterAllMessages.push_back([]() {

		// Output
		ofstream out("output/FirstCount.txt");
		out << output;
		cout << "\tUpdated FirstCount.txt\n";
		
	});


	
}
