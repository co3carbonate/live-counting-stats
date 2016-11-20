#pragma once

// Variables
namespace AccurateUpTo {
	bool done = false;
	string output;
	void main();
}

// Main function
void AccurateUpTo::main() {

	// forEachMessage
	forEachMessage.push_back([](Chat chat) {

		if(chat.count != "-1") {
			output = chat.count;
			done = true;
		}

	});

	// afterAllMessages
	afterAllMessages.push_back([]() {

		// Output
		ofstream out("output/AccurateUpTo.txt");
		out << output;
		cout << "\tUpdated AccurateUpTo.txt\n";
		
	});
	
}
