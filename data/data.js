// Global variables
var failedToLoad = false;
var chat = [];

// Start collecting data
(function(){

// Local functions/variables
// Function to read from a JSON file
function loadJSON(path, success, error) {
	var xhr = new XMLHttpRequest();
	xhr.onreadystatechange = function() {
		if (xhr.readyState === XMLHttpRequest.DONE) {
			if (xhr.status === 200) {
				if (success) {
					success(JSON.parse(xhr.responseText));
				}
			} else {
				if (error) {
					error(xhr);
				} else {
					failedToLoad = true;
				}
			}
		}
	};
	xhr.open("GET", path, true);
	xhr.send();
}
var lastChatFile;

// Load the value of lastChatFile first
loadJSON("data/lastChatFile.txt", function(data) {
	lastChatFile = data;
	loadChatData(lastChatFile);
});

// Load all chat data afterwards
function loadChatData(i) {
	// Base case
	if(i < 0) return;

	// Special case for first (newest) JSON file to prevent caching
	var suffix = '';
	if(i == lastChatFile) suffix = '?v=' + Date.now();

	// Load this chat data file
	loadJSON("data/chat" +i+ ".json" +suffix, function(data) {
		chat = chat.concat(data);

		// Recurse to load next chat data file
		i--;
		loadChatData(i);
	});
}


})(); // THE END

