#include <iostream>

using namespace std;

void showBoard(char * pSquare){
	cout << "+--------+" << endl;
	for (int y = 0; y < 8; y++){
		cout << "|";
		for (int x = 0; x < 8; x++){
			char outChar = *pSquare;
			cout << outChar;
			pSquare++;
		}
		cout << "|" << endl;
	}
	cout << "+--------+" << endl;
}

int main(int argc, char** argv) {
	const char redSquare = ' ';
	const char blkSquare = '#';
	const char redPlayer = '@';
	const char gryPlayer = 'O';
	
	char checkedBoard[8][8] = {
		{redSquare, redPlayer, redSquare, redPlayer, redSquare, redPlayer, redSquare, redPlayer},
		{redPlayer, redSquare, redPlayer, redSquare, redPlayer, redSquare, redPlayer, redSquare},
		{redSquare, redPlayer, redSquare, redPlayer, redSquare, redPlayer, redSquare, redPlayer},
		
		{blkSquare, redSquare, blkSquare, redSquare, blkSquare, redSquare, blkSquare, redSquare},
		{redSquare, blkSquare, redSquare, blkSquare, redSquare, blkSquare, redSquare, blkSquare},
		
		{gryPlayer, redSquare, gryPlayer, redSquare, gryPlayer, redSquare, gryPlayer, redSquare},
		{redSquare, gryPlayer, redSquare, gryPlayer, redSquare, gryPlayer, redSquare, gryPlayer},
		{gryPlayer, redSquare, gryPlayer, redSquare, gryPlayer, redSquare, gryPlayer, redSquare},
	};
	
	char * pFirstSquare = &checkedBoard [0][0];
	showBoard(pFirstSquare);
	
	
	return 0;
}
