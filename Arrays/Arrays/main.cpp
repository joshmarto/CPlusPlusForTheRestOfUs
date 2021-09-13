#include <iostream>

using namespace std;

int main(int argc, char** argv) {
	//ARRAYS
	//int daysInMonth[12];
	int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	char monthName[] = "April"; // Is an array of individually letters
	
	int currentMonth = 3;
	int daysThisMonth = daysInMonth[currentMonth];
	
	cout << "There are " << daysThisMonth << " days in " << monthName << endl;
	
	//ITERATION
	for (int i = 0; i < 12; i++){
		cout << "There are " << daysInMonth[i] << " days in month " << i + 1 << endl;	
	}
	return 0;
}
