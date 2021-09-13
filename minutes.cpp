#include <iostream>

using namespace std;

int main(int argc, char** argv) {
	const int secsMinutes = 60;
	int minutes = 5;
	int seconds;
	
	seconds = minutes * secsMinutes;
	
	cout << "There are " << seconds << " seconds in " << minutes << " minutes\n";
	return 0;
}
