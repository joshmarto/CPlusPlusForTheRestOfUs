#include <iostream>
#include <string>
#include <bitset>

using namespace std;

int rotateLeft (int value, int amount)
{
    //four bit rotate left

    const int OVERFLOW = 0b10000;
        while (amount > 0)
        {
            value = value << 1;
            if (((value & OVERFLOW) == OVERFLOW))
            {
           value = value & 0b1111;  //remove overflow bit
                value = value | 0b0001;  //set the rightmost bit
    }
    amount--;
    }
    return value;
}

int main(int argc, char** argv) {
	int inValvesOpen = 0b0011;
	int outValvesOpen = 0b0100;
	int pistonUp = 0b1010;
	int cylinderFire = 0b0000;
	
	for (int x = 0; x < 5; x++){
		string d1 = "   1        2        3        4   ";
		string d2 = "  ___      ___      ___      ___  ";
		string d3 = "x|   |x  x|   |x  x|   |x  x|   |x";
		string d4 = " |   |    |   |    |   |    |   | ";
		string d5 = "  ---      ---      ---      ---  ";
		string d6 = "   ?        ?        ?        ?   ";
		for (int c = 0; c < 4; c++){
			int offset = 3;
			int positionMask = c + 1;
			char stateLabel = 'C'; char inValve = 'x'; char outValve = 'x'; char upPiston = ' '; char downPiston = 'T'; char chamber = ' ';
			int i1 = 0; int i2 = 0; int i3 = 0; int i4 = 0; int i5 = 0; int i6 = 0;
			switch (x){
				case 0: case 4:
					switch (c){
						case 0:
							i1 = 0;
							break;
						case 1:
							i1 = 9;
							break;
						case 2:
							i1 = 18;
							break;
						case 3:
							i1 = 27;
							break;
					}
					break;
				case 1:
					switch (c){
						case 0:
							i1 = 18;
							break;
						case 1:
							i1 = 27;
							break;
						case 2:
							i1 = 0;
							break;
						case 3:
							i1 = 9;
							break;
					}
					break;
				case 2:
					switch (c){
						case 0:
							i1 = 9;
							break;
						case 1:
							i1 = 18;
							break;
						case 2:
							i1 = 27;
							break;
						case 3:
							i1 = 0;
							break;
					}
					break;
				case 3:
					switch (c){
						case 0:
							i1 = 27;
							break;
						case 1:
							i1 = 0;
							break;
						case 2:
							i1 = 9;
							break;
						case 3:
							i1 = 18;
							break;
					}
					break;
			}
			i2 = i1 + 6; i3 = i1 + 2; i4 = i1 + 3; i5 = i1 + 4; i6 = i1 + 3;
			if (positionMask == 1){
				chamber = '*';
				upPiston = '*';
				stateLabel = 'P';
				d3[i1] = inValve;
				d3[i2] = outValve;
				d3[i3] = upPiston;
				d3[i4] = downPiston;
				d3[i5] = chamber;
				d6[i6] = stateLabel;
			} else if (positionMask == 2){
				outValve = 'o';
				stateLabel = 'E';
				d3[i1] = inValve;
				d3[i2] = outValve;
				d4[i3] = upPiston;
				d4[i4] = downPiston;
				d4[i5] = chamber;
				d6[i6] = stateLabel;
			} else if (positionMask == 3){
				inValve = 'o';
				stateLabel = 'I';
				d3[i1] = inValve;
				d3[i2] = outValve;
				d3[i3] = upPiston;
				d3[i4] = downPiston;
				d3[i5] = chamber;
				d6[i6] = stateLabel;
			} else if (positionMask == 4){
				upPiston = ' ';
				downPiston = 'T';
				d3[i1] = inValve;
				d3[i2] = outValve;
				d4[i3] = upPiston;
				d4[i4] = downPiston;
				d4[i5] = chamber;
				d6[i6] = stateLabel;
			}
			//cout << stateLabel << " " << inValve << " " << outValve << " " << upPiston << " " << downPiston << " " << chamber << endl;
		}
		cout << x + 1 << endl;
		cout << d1 << endl;
		cout << d2 << endl;
		cout << d3 << endl;
		cout << d4 << endl;
		cout << d5 << endl;
		cout << d6 << endl;
		cout << "\n" << endl;
	}
	return 0;
}
