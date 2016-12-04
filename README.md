# Live Counting Stats

Source code for the Live Counting stats by [/u/co3_carbonate](https://www.reddit.com/user/co3_carbonate/)

The Live Counting stats used to be made with JavaScript as it was more convenient. However, I decided to rewrite it in C++ due to performance issues with a growing database of messages.

Due to my lack of much experience with C++, the code may have bugs that I may or may not have noticed. Either way, inform me if you spot any.

---

## Code 

This section is just a brief summary of what each file does.

main.cpp - links all the libraries (STL and the JSON library) and header files (all the other files) together; calls the important functions in `int main()`.

json/json.hpp - this is a [JSON library](https://github.com/nlohmann/json) which is used in data.hpp to retrieve data from all the JSON files in the folder "data"

class.chat.hpp - each message from the retrieved data is stored into a class `Chat`, which is defined here

globals.hpp - all global variables for the actual "non-library" files are here, including a vector `data` of class Chat

data.hpp - defines function `retrieveData()` called in `main()`, which retrieves data from the JSON files in the "data" folder, and stores these data into `data` from glboals.hpp (note that the JSON files in the "data" folder are updated through a JavaScript/PHP script which is not present here)

stats.hpp - defines function `generateStats()` called in `main`, which links all the .hpp files in the "stats" folder to generate stats from the retrieved data and outputs those stats to the "output" folder