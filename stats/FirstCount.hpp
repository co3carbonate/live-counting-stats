// Header guard
#ifndef FIRSTCOUNT_H
#define FIRSTCOUNT_H

// Variables
namespace {
	vector<string> usersAnalysed;
	string FirstCountOutput;
}

// Main function
void FirstCount() {

	// forEachMessage
	forEachMessage.push_back([](Chat chat) {

		// Exceptions
		if(chat.author == "[deleted]") return; // deleted user
		if(find(usersAnalysed.begin(), usersAnalysed.end(), chat.author) != usersAnalysed.end()) { // current user already accounted for
			return;
		}

		usersAnalysed.push_back(chat.author);

		// Process
		replace(chat.body.begin(), chat.body.end(), '\n', ' ');
		chat.body = "[" +chat.body+ "](https://www.reddit.com/live/ta535s1hq2je/updates/" +chat.id+ ")";
		FirstCountOutput = chat.author + " | " +chat.body+ " | " +chat.date_string+ "\n" + FirstCountOutput;

	});

	// afterAllMessages
	afterAllMessages.push_back([]() {

		// Output
		ofstream out("output/FirstCount.txt");
		out << FirstCountOutput;
		cout << "\tUpdated FirstCount.txt\n";
		
	});


	
}

#endif