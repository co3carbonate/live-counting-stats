// STL includes
#include <bits/stdc++.h>
using namespace std;

// Class includes
#include "json/json.hpp"
using json = nlohmann::json;
#include "class.chat.hpp"

// Local includes
#include "globals.hpp"
#include "data.hpp"
#include "stats.hpp"

// Main
int main() {
	retrieveData();
	generateStats();
	
	return 0;
}