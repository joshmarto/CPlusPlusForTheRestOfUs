#include <iostream>

using namespace std;

int main(int argc, char** argv) {
	int month = 0;
	int year = 0;
	
	cout << "Enter the year as 4 digits: ";
	cin >> year;
	
	cout << "Enter the month as a number(1-12): ";
	cin >> month;
	
	int daysInMonth = 0;
	
	int febDay = 0;
	/*if (year % 4 == 0){
		febDay = 29;
	} else{
		febDay = 28;
	}*/
	
	//febDay = (year % 4 == 0) ? 29: 28; // Ternary Operators
	
	/*if (month == 2){
		daysInMonth = febDay;
	} else if (month == 4){
		daysInMonth = 30;
	} else if (month == 4){
		daysInMonth = 30;
	} else if (month == 6){
		daysInMonth = 30;
	} else if (month == 9){
		daysInMonth = 30;
	} else if (month == 11){
		daysInMonth = 30;
	} else{
		daysInMonth = 31;
	}*/
	
	switch (month){
		case 2:
			daysInMonth = (year % 4 == 0) ? 29: 28;
			break;
		case 4:
		case 6:
		case 9:
		case 11:
			daysInMonth = 30;
			break;
		default:
			daysInMonth = 31;
	}
	
	cout << "These are " << daysInMonth << " days in this month." << endl;
	
	return 0;
}
