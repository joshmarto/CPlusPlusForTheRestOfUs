#include "EnhancedString.h"
#include <iostream>

using namespace std;

const string EnhancedString::oneSpace = " ";
const string EnhancedString::twoSpaces = "  ";
const string EnhancedString::vowels = "aeiouAEIOU";

EnhancedString::EnhancedString(string value){
	this->data = value;
	this->trim();
	this->singleSpace();
}

void EnhancedString::getFromKeyboard(string message){
	cout << message << endl;
	getline(cin, this->data);
}


void EnhancedString::singleSpace(){
	bool found = true;
	
	while(found == true){
		int pos = this->data.find(twoSpaces);
		if (pos == string::npos){
			found = false;
		} else{
			this->data = this->data.erase(pos, 1);
		}
	}
}

void EnhancedString::trim(){
	int lastPos = this->data.length() - 1;
	bool found = true;
	
	while(found == true && lastPos >= 0){
		if (this->data.substr(lastPos, 1) == " "){
			this->data = this->data.erase(lastPos, 1);
		} else if(this->data.substr(0, 1) == " "){
			this->data = this->data.erase(0, 1);
		} else{
			found = false;
		}
		this->data = this->data.length() - 1;
	}
}

int EnhancedString::countWords(){
	int wordCount = 0;
	
	if(this->data.length() > 0){
		wordCount++;
		int position = 0;
		while(true){
			position = this->data.find(oneSpace, position);
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

int EnhancedString::countVowels(){
	int vowelCount = 0;
	string::iterator i;
	
	if(this->data.length() > 0){
		for(i = this->data.begin(); i != this->data.end(); i++){
			char c = *i;
			int pos = vowels.find(c);
			if(pos != string::npos){
				vowelCount++;
			}
		}
	}
	
	return vowelCount;
}

EnhancedString::~EnhancedString()
{
}

