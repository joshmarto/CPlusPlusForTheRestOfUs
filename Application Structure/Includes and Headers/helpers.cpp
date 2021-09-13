#include <iostream>
#include <bitset>
#include <string>

using namespace std;

namespace helpers{
	
	void display(string message, int value){
		bitset<8> myBitset(value);
		cout << message;
		cout << myBitset.to_string() << " (" << myBitset.to_ulong() << ")" << endl;
	}
}
