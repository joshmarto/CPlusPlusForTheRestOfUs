#include <iostream>

using namespace std;

int main(int argc, char** argv) {
	const int minsPerHour = 60;
	int numHours = 11;
	int minutes = 0;
	
	//minsPerHour++;
	numHours++;
	
	minutes = numHours * minsPerHour;
	cout << "There are " << minutes << " mins in " << numHours << " hrs.\n";
	unsigned int zeroHour = 0;
	zeroHour--;
	cout << "1 hour before zero hour is " << numHours + zeroHour << endl;
	return 0;
}
