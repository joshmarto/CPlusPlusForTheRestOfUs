#include <iostream>

using namespace std;

int daysInMonth(int year, int month){
	int days = 0;
	switch (month){
		case 2:
			days = (year % 4 == 0) ? 29: 28;
			break;
		case 4:
		case 6:
		case 9:
		case 11:
			days = 30;
			break;
		default:
			days = 31;
	}
	return days;
}

int main(int argc, char** argv) {
	int month = 0;
	int year = 0;
	int day = 0;
	
	cout << "Enter the year as 4 digits: ";
	cin >> year;
	
	cout << "Enter the month as a number(1-12): ";
	cin >> month;
	
	cout << "Enter the day as a number(1-31): ";
	cin >> day;
	
	int numDays = 0;
	
	/*while (month > 1){
		month--;
		numDays += daysInMonth(year, month);
	}*/
	
	for (int currentMonth = 1; currentMonth < month; currentMonth++){
		numDays += daysInMonth(year, currentMonth);
	}
	
	/*do{
		month--;
		numDays += daysInMonth(year, month);
	} while (month > 1);*/
	
	numDays += day;
	
	cout << "This is day " << numDays << endl;
	
	return 0;
}
