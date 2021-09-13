#include <iostream>
#include <string>

using namespace std;

string singleSpace(string anyString){
	string retVal = anyString;
	const string twoSpaces = "  ";
	bool found = true;
	
	while(found == true){
		int pos = retVal.find(twoSpaces);
		if (pos == string::npos){
			found = false;
		} else{
			retVal = retVal.erase(pos, 1);
		}
	}
	
	return retVal;
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

string oneSpace = " ";
string twoSpaces = "  ";

int countNames(string fullName){
	int wordCount = 0;
	fullName = trim(singleSpace(fullName));
	
	if(fullName.length() > 0){
		wordCount++;
		int position = 0;
		while(true){
			position = fullName.find(oneSpace, position);
			if (position == string::npos){
				break;
			} else{
				wordCount++;
			}
			position++;
		}
	}
	return wordCount;
}

string getFirstName(string fullName){
	string retValue;
	//const char* oneSpace = " ";
	
	int pos = fullName.find_first_of(oneSpace);
	if (pos != string::npos){
		retValue = fullName.substr(0, pos);
	}
	
	return retValue;
}

string getLastName(string fullName){
	string retValue;
	//const char* oneSpace = " ";
	
	if (fullName.length() > 0){
		int pos = fullName.find_last_of(oneSpace);
		if (pos != string::npos){
			retValue = fullName.substr(pos + 1);
		}
	}
	
	return retValue;
}

string getMiddleName(string fullName){
	string retValue;
	
	int rightPos = fullName.find_last_of(oneSpace);
	int leftPos = fullName.find_first_of(oneSpace);
	if(rightPos != string::npos && leftPos != string::npos && leftPos < rightPos){
		retValue = fullName.substr(leftPos + 1, rightPos - leftPos);
	}
	return retValue;
}

string getInitials(string fullName){
	string retValue;
	
	
	if(fullName.length() > 0){
		int position = 0;
		retValue = fullName.substr(position, 1);
		while(true){
			position = fullName.find(oneSpace, position);
			if(position == string::npos){
				break;
			} else{
				string initial = fullName.substr(position + 1, 1);
				retValue = retValue.append(initial);
			}
			position++;
		}
	}
	return retValue;
}

const string vowels = "aeiouAEIOU";

int countVowels(string anyString){
	int vowelCount = 0;
	string::iterator i;
	
	if(anyString.length() > 0){
		for(i = anyString.begin(); i != anyString.end(); i++){
			char c = *i;
			int pos = vowels.find(c);
			if(pos != string::npos){
				vowelCount++;
			}
		}
	}
	
	return vowelCount;
}

void displayNameInfo(string fullName){
	fullName = trim(fullName);
	fullName = singleSpace(fullName);
	
	int namesCount = countNames(fullName);
	int vowelsCount = countVowels(fullName);
	
	switch(namesCount){
		case 0:
			cout << "You didn't provide any information!" << endl;
			break;
		case 1:
			cout << "You entered " << fullName << endl;
			cout << "Please include more than one name, with spaces between" << endl;
			break;
		case 2:
			cout << "You entered " << fullName << endl;
			cout << "Your last name is " << getLastName(fullName) << endl;
			cout << "Your first name is " << getFirstName(fullName) << endl;
			cout << "Your initials are " << getInitials(fullName) << endl;
			cout << "There are " << vowelsCount << " vowels in your name" << endl;
			break;
		case 3:
			cout << "You entered " << fullName << endl;
			cout << "Your last name is " << getLastName(fullName) << endl;
			cout << "Your middle name is " << getMiddleName(fullName) << endl;
			cout << "Your first name is " << getFirstName(fullName) << endl;
			cout << "Your initials are " << getInitials(fullName) << endl;
			cout << "There are " << vowelsCount << " vowels in your name" << endl;
			break;
		default:
			cout << "You entered " << fullName << endl;
			cout << "Your last name is " << getLastName(fullName) << endl;
			cout << "Your middle names are " << getMiddleName(fullName) << endl;
			cout << "Your first name is " << getFirstName(fullName) << endl;
			cout << "Your initials are " << getInitials(fullName) << endl;
			cout << "There are " << vowelsCount << " vowels in your name" << endl;
	}
}

string getFullName(){
	string message = "Enter your full name";
	string fullName;
	
	cout << message << endl;
	getline(cin, fullName);
	
	return fullName;
}

int main(int argc, char** argv) {
	string myString1 = " ABC ";
	string myString2 = " HELLO    WORLD    ";
	string myString3 = " ";
	string myString4 = "A        ";
	
	// EXAMPLE 1
//	cout << trim(singleSpace(myString1)) << "." << endl;
//	cout << trim(singleSpace(myString2)) << "." << endl;
//	cout << trim(singleSpace(myString3)) << "." << endl;
//	cout << trim(singleSpace(myString4)) << "." << endl;

	string fullName1 = " Snubby";
	string fullName2 = " Shelia Becomin Rondamountin";
	string fullName3 = " Arthur Chicken Sandwich";
	//string fullName4 = getFullName();
	
	// EXAMPLE 2
//	cout << fullName1 << " has " << countNames(fullName1) << " names." << endl;
//	cout << fullName2 << " has " << countNames(fullName2) << " names." << endl;
//	cout << fullName3 << " has " << countNames(fullName3) << " names." << endl;

	// EXAMPLE 3
//	displayNameInfo(fullName1);
//	cout << "---------------------------" << endl;
//	displayNameInfo(fullName2);
//	cout << "---------------------------" << endl;
//	displayNameInfo(fullName3);
//	cout << "---------------------------" << endl;
//	displayNameInfo(fullName4);
	
	// EXAMPLE 4
	string fullNameA = " Shelia Becomin Rondamountin";
	string fullNameB = " Arthur Chicken Sandwich";
	
	fullNameA = trim(fullNameA);
	fullNameB = trim(fullNameB);
	
	if(fullNameA > fullNameB){
		fullNameA.swap(fullNameB);
	}
	
	displayNameInfo(fullNameA);
	displayNameInfo(fullNameB);
	return 0;
}
