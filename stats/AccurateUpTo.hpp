// Header guard
#ifndef ACCURATEUPTO_H
#define ACCURATEUPTO_H

// Variables
namespace {
	bool done = false;
	string AccurateUpToOutput;
}

// Main function
void AccurateUpTo() {

	// forEachMessage
	forEachMessage.push_back([](Chat chat) {

		if(chat.count != "-1") {
			AccurateUpToOutput = chat.count;
			done = true;
		}

	});

	// afterAllMessages
	afterAllMessages.push_back([]() {

		// Output
		ofstream out("output/AccurateUpTo.txt");
		out << AccurateUpToOutput;
		cout << "\tUpdated AccurateUpTo.txt\n";
		
	});


	
}

#endif