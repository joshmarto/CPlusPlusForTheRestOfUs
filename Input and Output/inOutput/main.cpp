#include <iostream>
#include <iomanip>

using namespace std;

int main(int argc, char** argv) {
	float price1 = 0;
	float price2 = 0;
	float price3 = 0;
	float total = 0;
	cout << "Enter a price\n";
	cin >> price1;
	cout << "Enter a price\n";
	cin >> price2;
	cout << "Enter a price\n";
	cin >> price3;
	
	total = price1 + price2 + price3;
	system("cls");
	
	cout << setiosflags(ios::fixed);
	cout << "Price 1 is" << setw(14) << setprecision(2) << price1 << endl;
	cout << "Price 2 is" << setw(14) << setprecision(2) << price2 << endl;
	cout << "Price 3 is" << setw(14) << setprecision(2) << price3 << endl;
	cout << "Total price is" << setw(10) << setprecision(2) << fixed << total;
	return 0;
}
