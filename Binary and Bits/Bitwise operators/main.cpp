#include <iostream>
#include <bitset>
#include <string>

using namespace std;

void display(string message, int value){
	bitset<8> myBitset(value);
	cout << message;
	cout << myBitset.to_string() << " (" << myBitset.to_ulong() << ")" << endl;
}

int main(int argc, char** argv) {
	int myNumber = 15;
	int valueA = 12;
	int valueB = 139;
	
	display("Starting value: ", myNumber);
	cout << endl;
	
	return 0;
}
