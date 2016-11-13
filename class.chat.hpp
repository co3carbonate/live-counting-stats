// Header guard
#ifndef CLASSCHAT_H
#define CLASSCHAT_H

class Chat {
	public:
		// Constructor function
		Chat(json chat) {
			// Make modifications to JSON chat data first

			// Count (detect the count from chat["body"])
			string body = chat["body"];
			string num;
			int i = 0;
			for(int len = body.size(); i < len; i++) {
				char s = body[i];
				if(isdigit(s)) {
					num += s;
					continue;
				} 
				else if(s == ' ' || s == ',') {
					continue;
				} 
				else if(s == '~' || s == '^' || s == '#' ||
						s == '*' || s == '>') {
					// Only allow special formatting characters if they are at 
					// the start of the string
					if(num.empty()) {
						continue;
					} else {
						break;
					}
				} else {
					break;
				}
			}
			//this->count_end_index = i;
			if(num.empty() || find_if(num.begin(), num.end(), (int(*)(int))isdigit) == num.end()) {
				this->count = "-1"; // number is empty or does not contain numbers
			} else {
				this->count = num;
			}

			// Author (/u/ and [deleted])
			if(chat["author"].is_string()) {
				string author = chat["author"];
				chat["author"] = "/u/" + author;
			} else if(chat["author"].is_null()) {
				chat["author"] = "[deleted]";
			}

			// Generate date and date_string from created_utc
			int created = chat["created_utc"];
			date = created;
			char buffer[64];
			strftime(buffer, sizeof(buffer), "%d %b '%y", gmtime(&date));
			date_string = string(buffer);

			// Now transfer JSON data to object members
			this->id = chat["id"];
			this->author = chat["author"];
			this->body = chat["body"];
			//this->body_html = chat["body_html"];
			this->name = chat["name"];
			this->stricken = chat["stricken"];

		}
		bool stricken;
		time_t date;
		string id;
		string count;
		string date_string;
		string author;
		string body;
		string name;
		//string body_html;
		//int count_end_index;
};



#endif