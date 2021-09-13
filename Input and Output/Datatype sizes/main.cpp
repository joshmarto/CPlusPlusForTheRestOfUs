#include <iostream>
#include <climits>

using namespace std;

int main(int argc, char** argv) {
	int numBytes = 0;
	unsigned int myUnsignedInt = UINT_MAX;
	cout << "The maximum value an integer can hold is " << myUnsignedInt << endl;
	numBytes = sizeof(myUnsignedInt);
	cout << "The number of bytes required to store our integer is " << numBytes << endl;
	
	unsigned long myUnsignedLong = ULONG_MAX;
	cout << "The maximum value a long integer can hold is " << myUnsignedLong << endl;
	numBytes = sizeof(myUnsignedLong);
	cout << "The number of bytes required to store our long integer is " << numBytes << endl;
	
	unsigned long long myUnsignedDoubleLong = ULONG_LONG_MAX;
	cout << "The maximum value a long-long integer can hold is " << myUnsignedDoubleLong << endl;
	numBytes = sizeof(myUnsignedDoubleLong);
	cout << "The number of bytes required to store our long-long integer is " << numBytes << endl;
	
	unsigned short myUnsignedShort = USHRT_MAX;
	cout << "The maximum value a short integer can hold is " << myUnsignedShort << endl;
	numBytes = sizeof(myUnsignedShort);
	cout << "The number of bytes required to store our short integer is " << numBytes << endl;
	
	unsigned char myUnsignedByte = UCHAR_MAX;
	cout << "The maximum value a char integer can hold is " << (int)myUnsignedByte << endl;
	numBytes = sizeof(myUnsignedByte);
	cout << "The number of bytes required to store our char integer is " << numBytes << endl;
	
	wchar_t myWideChar = WCHAR_MAX;
	cout << "The maximum value a wide char integer can hold is " << (int)myWideChar << endl;
	numBytes = sizeof(myWideChar);
	cout << "The number of bytes required to store our wide char integer is " << numBytes << endl;
	return 0;
}
