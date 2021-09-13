#include <iostream>
#include <stdlib.h>

using namespace std;

char positions[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
const char player1 = 'X';
const char player2 = 'O';
char currentPlayer = player1;
char lastPlayer = player2;

void Field(char * board){
	system("cls");
	cout << "+-----+" << endl;
	for (int x; x < 3; x++){
		cout << "|";
		for (int y = 0; y < 3; y++){
			cout << *board << "|";
			board++;
		}
		cout << endl << "+-----+" << endl;
	}
}

bool Win(char board[], char player){
	if (board[0] == player && board[1] == player && board[2] == player){
		cout << "Player " << player << " wins!" << endl;
		return true;
	} else if (board[3] == player && board[4] == player && board[5] == player){
		cout << "Player " << player << " wins!" << endl;
		return true;
	} else if (board[6] == player && board[7] == player && board[8] == player){
		cout << "Player " << player << " wins!" << endl;
		return true;
	} else if (board[0] == player && board[3] == player && board[6] == player){
		cout << "Player " << player << " wins!" << endl;
		return true;
	} else if (board[1] == player && board[4] == player && board[7] == player){
		cout << "Player " << player << " wins!" << endl;
		return true;
	} else if (board[2] == player && board[5] == player && board[8] == player){
		cout << "Player " << player << " wins!" << endl;
		return true;
	} else if (board[0] == player && board[4] == player && board[8] == player){
		cout << "Player " << player << " wins!" << endl;
		return true;
	} else if (board[2] == player && board[4] == player && board[6] == player){
		cout << "Player " << player << " wins!" << endl;
		return true;
	}
	return false;
}

void getPlayerChoice(){
	for (int turn = 0; turn < 9; turn++){
		char * pointer = &board[0][0];
		Field(pointer);
		if (turn % 2 == 0){
			lastPlayer = player2;
			currentPlayer = player1;
		} else{
			lastPlayer = player1;
			currentPlayer = player2;
		}
		int x = 0;
		int y = 0;
		cout << "Please enter the location (x) player " << currentPlayer << ": ";
		cin >> x;
		cout << "Please enter the location (y) player " << currentPlayer << ": ";
		cin >> y;
		int i = ((x * 3) + (y + 1)) - 1;
		board[x][y] = currentPlayer;
			cout << currentPlayer;
			positions[i] = currentPlayer;
		if (Win(positions, currentPlayer)){
			char * newPointer = &board[0][0];
			Field(newPointer);
			break;
		}
	}
}

int main(int argc, char** argv) {
	getPlayerChoice();
	return 0;
}
