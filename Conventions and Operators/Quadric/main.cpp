#include <iostream>
#include <math.h>

using namespace std;

int main(int argc, char** argv) {
	float a = 0;
	float b = 0;
	float c = 0;
	
	cout << "Please enter the number A: ";
	cin >> a;
	cout << "Please enter the number B: ";
	cin >> b;
	cout << "Please enter the number C: ";
	cin >> c;
	
	float x1 = 0;
	float x2 = 0;
	
	x1 = ((-b)-sqrt(pow(b, 2) - (4 * a * c)))/(2 * a);
	x2 = ((-b)+sqrt(pow(b, 2) - (4 * a * c)))/(2 * a);
	
	cout << "This quadric has the following roots X=" << x1 << " and X=" << x2 << endl;
	return 0;
}
