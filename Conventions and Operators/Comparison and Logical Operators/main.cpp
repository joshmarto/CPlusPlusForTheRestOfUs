#include <iostream>

using namespace std;

int main(int argc, char** argv) {
	float myPrice = 200.0F;
	myPrice--;
	
	bool myResult = false;
	myResult = (myPrice == 200.0F); // Comparison ==, <, >, <=, >=
	cout << myResult << endl;
	!myResult; // Logical !, &, |
	cout << myResult << endl;
	
	
	int year = 2016;
	int mont = 2;
	
	bool isLeapYear = (year % 4 == 0);
	bool has28 = (!isLeapYear && month == 2);
	bool has29 = (isLeapYear && month == 2);
	bool has30 = (month==11 || month == 4 || month == 6 || month == 9);
	bool has31 = (!has28 && !has29 && !has30);
	
	return 0;
}
