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
	
	myNumber = myNumber << 1;
	display("Shifted left 1:  ", myNumber);
	cout << endl;
	
	myNumber >>= 2;
	display("Shifted right 2: ", myNumber);
	cout << endl;
	
	display("bitwise NOT:     ", ~myNumber);
	cout << endl;
	
	display("First number:    ", valueA);
	display("Second number:   ", valueB);
	display("    OR number:   ", valueA | valueB);
	cout << endl;
	
	display("First number:    ", valueA);
	display("Second number:   ", valueB);
	display("   AND number:   ", valueA & valueB);
	cout << endl;
	
	display("First number:    ", valueA);
	display("Second number:   ", valueB);
	display("   XOR number:   ", valueA ^ valueB);
	cout << endl;
	return 0;
}
