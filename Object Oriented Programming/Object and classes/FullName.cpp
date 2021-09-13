#include "FullName.h"

FullName::FullName(std::string value):EnhancedString(value)
{
	this->data = value;
}

string FullName::getFirstName(){
	string retValue;
	
	int pos = this->data.find_first_of(oneSpace);
	if (pos != string::npos){
		retValue = this->data.substr(0, pos);
	}
	
	return retValue;
}

string FullName::getLastName(){
	string retValue;
	
	if (this->data.length() > 0){
		int pos = this->data.find_last_of(oneSpace);
		if (pos != string::npos){
			retValue = this->data.substr(pos + 1);
		}
	}
	
	return retValue;
}

string FullName::getMiddleName(){
	string retValue;
	
	int rightPos = this->data.find_last_of(oneSpace);
	int leftPos = this->data.find_first_of(oneSpace);
	if(rightPos != string::npos && leftPos != string::npos && leftPos < rightPos){
		retValue = this->data.substr(leftPos + 1, rightPos - leftPos);
	}
	return retValue;
}

string FullName::getInitials(){
	string retValue;
	
	if(this->data.length() > 0){
		int position = 0;
		retValue = this->data.substr(position, 1);
		while(true){
			position = this->data.find(oneSpace, position);
			if(position == string::npos){
				break;
			} else{
				string initial = this->data.substr(position + 1, 1);
				retValue = this->data.append(initial);
			}
			position++;
		}
	}
	return retValue;
}

void FullName::displayInfo(){
	int namesCount = this->countWords();
	int vowelsCount = this->countVowels();
	
	switch(namesCount){
		case 0:
			cout << "You didn't provide any information!" << endl;
			break;
		case 1:
			cout << "You entered " << this->data << endl;
			cout << "Please include more than one name, with spaces between" << endl;
			break;
		case 2:
			cout << "You entered " << this->data << endl;
			cout << "Your last name is " << this->getLastName() << endl;
			cout << "Your first name is " << this->getFirstName() << endl;
			cout << "Your initials are " << this->getInitials() << endl;
			cout << "There are " << vowelsCount << " vowels in your name" << endl;
			break;
		case 3:
			cout << "You entered " << this->data << endl;
			cout << "Your last name is " << this->getLastName() << endl;
			cout << "Your middle name is " << this->getMiddleName() << endl;
			cout << "Your first name is " << this->getFirstName() << endl;
			cout << "Your initials are " << this->getInitials() << endl;
			cout << "There are " << vowelsCount << " vowels in your name" << endl;
			break;
		default:
			cout << "You entered " << this->data << endl;
			cout << "Your last name is " << this->getLastName() << endl;
			cout << "Your middle names are " << this->getMiddleName() << endl;
			cout << "Your first name is " << this->getFirstName() << endl;
			cout << "Your initials are " << this->getInitials() << endl;
			cout << "There are " << vowelsCount << " vowels in your name" << endl;
	}
}

FullName::~FullName()
{
}

