#include <iostream>
#include <iomanip>

using namespace std;

float processLineItem (int quantity, const char *description, float price){
	float lineTotal = price * quantity;
	//cout << quantity << "\t" << description << "\t$" << price << "\t$" << lineTotal << endl; //Possible solution 1
	cout << setiosflags(ios::fixed);
	cout << setw(10) << quantity
	<< setw(20) << description
	<< "  $" << setw(6) << setprecision(2) << price
	<< "  $" << setw(6) << setprecision(2) << lineTotal << endl;
	return lineTotal;
}

int main(int argc, char** argv) {
	//Groceries
	float runningTotal = 0;
	
	cout << setw(10) << "Quantity"
	<< setw(20) << "Description"
	<< setw(9) << "Price"
	<< setw(9) << "Total" << endl;
	
	runningTotal += processLineItem(3, "Apples", .5F);
	runningTotal += processLineItem(2, "Oranges", .45F);
	runningTotal += processLineItem(1, "Lobster", 21.99F);
	
	cout << endl;
	cout << "The grocery bill totals $" << setprecision(2) << runningTotal << endl;
	
	return 0;
}
