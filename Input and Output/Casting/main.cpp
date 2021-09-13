#include <iostream>
#include <climits>

using namespace std;

int main(int argc, char** argv) {
	char myChar = 'A';
	bool myBool = true;
	bool myOtherBool = false;
	
	int myConvertedChar = (int)myChar; //Casting
	int myConvertedBool = (int)myBool;
	int myConvertedOtherBool = (int)myOtherBool;
	
	char myChar2 = (char)myConvertedChar;
	bool myBool2 = (bool)myConvertedBool;
	bool myOtherBool2 = (bool)myConvertedOtherBool;
	
	float approxPi = 3.14F;
	int sputnikYear = 1957;
	
	int convertedPi = (int)approxPi;
	char convertedYear = (char)sputnikYear;
	
	float approxPi2 = (float)convertedPi;
	int sputnikYear2 = (int)convertedYear;
	return 0;
}
