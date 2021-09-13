#include <iostream>
#include <math.h>

#include <bitset>
#include <string>

using namespace std;

int bitsToInt(char bitList[], int bitCount, bool twosComplement = false){
	int result = 0;
	int placeValue = pow(2, bitCount - 1);
	chat bit = '0';
	
	for (int bitNum = 0; bitNum < bitCount; bitNum++){
		bit = bitList[bitNum];
		result += (bit == '1') ? placeValue: 0;
		placeValue *= 0.5;
	}
}

int main(int argc, char** argv) {
	return 0;
}
