#include <iostream>

using namespace std;

int main(int argc, char** argv) {
	int toGuess = 0;
	int highest = 100;
	int lowest = 0;
	int attempts = 0;
	int guess = 0;
	char response;
	cout << "Think of a number between 1 and 100" << endl;
	cin >> toGuess;
	
	while (response != 'y'){
		guess = (highest + lowest) / 2;
		attempts++;
		cout << "I guess " << guess << " am I right?" << endl << "'q' to quit, 'y' if correct, 'h' if too high, 'l' if too low.\n";
		cin >> response;
		if (response == 'q'){
			cout << "You quit. Bye.";
			break;
		} else if (response == 'y'){
			cout << "I guessed it in " << attempts << " attempts";
			break;
		} else if (response == 'h'){
			highest = guess;
		} else if (response == 'l'){
			lowest = guess;
		} else{
			cout << "“I didn’t understand that response.";
		}
	}
	return 0;
}
