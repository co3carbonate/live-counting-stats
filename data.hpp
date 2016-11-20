#pragma once

void retrieveData(int fileIndex, string filePathPrefix = "") {
	// Preparation
	string filePath = filePathPrefix + "data/chat" +to_string(fileIndex)+ ".json";
	json fileJSON;
	cout << "\tRetrieving '" << filePath << "'\n";

	// Retrieve JSON data
	ifstream in(filePath);
	in >> fileJSON;
	cout << "\tSuccessfully retrieved '" << filePath << "'\n";

	// Append retrieved data to data variable
	for(int i = 0, len = fileJSON.size(); i < len; i++) {
		Chat chat = fileJSON[i];
		data.push_back(chat);
	}
}

void retrieveData(string filePathPrefix = "") {
	// Overloading to retrieve data from ALL data files
	// Also displays time taken to retrieve data

	// Preparation
	auto start = chrono::system_clock::now();
	cout << "Retrieving data:\n";

	// Retrieve JSON data
	ifstream lastChatFileIn("data/lastChatFile.txt");
	int lastChatFile;
	lastChatFileIn >> lastChatFile;
	for(int i = lastChatFile; i >= 0; i--) {
		retrieveData(i);
	}

	// Output
	auto end = chrono::system_clock::now();
	chrono::duration<double> elapsed = end - start;
	cout << "Successfully retrieved data (" <<
		setprecision(2) << fixed << elapsed.count() << "s)\n\n";

	// Others
	l = data.size();

}
