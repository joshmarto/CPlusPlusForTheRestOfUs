#include <iostream>
#include <string>

using namespace std;

const string b = " by ";

void test(){
	cout << "Still working..." << endl;
}

string trim(string anyString){
	string retVal = anyString;
	int lastPos = retVal.length() - 1;
	
	bool found = true;
	
	while(found == true && lastPos >= 0){
		if (retVal.substr(lastPos, 1) == " "){
			retVal = retVal.erase(lastPos, 1);
		} else if(retVal.substr(0, 1) == " "){
			retVal = retVal.erase(0, 1);
		} else{
			found = false;
		}
		lastPos = retVal.length() - 1;
	}
	return retVal;
}

string getFirst(string text, char separator){
	string value;

	int pos = text.find_first_of(separator);
	if (separator == '*'){
		size_t found = text.find(b);
	    if (found != string::npos)
	        pos = found;
	}
	
	if (pos != string::npos){
		value = text.substr(0, pos);
	}

	return value;
}

string getSecond(string text, char separator){
	string value;

	int pos = text.find_first_of(separator);
	if (separator == '*'){
		pos = text.find_first_of(b);
		string::iterator i;
		for(i = text.begin(); i != text.end(); i++){
			char c = *i;
			pos = text.find(b);
		}
	}
	
	if (pos != string::npos){
		value = text.substr(pos + 1);
	}

	return value;
}

int main(){
	// Sail on By - The Spinnakers
	// Abby Lane - the Stinkbugs
	// The BFD and Fiddy Pence: We Rap by Sunlight
	// Shooby Dooby by the Wooby Sisters
	while(true){
		string fullName;
		cout << "Enter track or 'Q' to quit." << endl;
		getline(cin, fullName);
		if (fullName == "q"){
			break;
		} else{
			if (fullName.length() >= 5){
				string title;
				string artist;
				if (fullName.find(":")){
					//Title:artist
					title = trim(getFirst(fullName, ':'));
					artist = trim(getSecond(fullName, ':'));
					if (title != "" && artist != ""){
						cout << "TITLE: " << title << "\nAUTHOR: " << artist << "\n" << endl;
						continue;
					}
				}
				if (fullName.find("-")){
					//Artist-title
					artist = trim(getFirst(fullName, '-'));
					title = trim(getSecond(fullName, '-'));
					if (title != "" && artist != ""){
						cout << "TITLE: " << title << "\nAUTHOR: " << artist << "\n" << endl;
						continue;
					}
				}
				if (fullName.find("by")){
					//Title by artist
					title = getFirst(fullName, '*');
					artist = getSecond(fullName, '*');
					if (title != "" && artist != ""){
						cout << "TITLE: " << title << "\nAUTHOR: " << artist << "\n" << endl;
						continue;
					}
				}
			} else{
				cout << "please enter a track with more than five characters." << endl;
			}
		}
	}
	return 0;
}

