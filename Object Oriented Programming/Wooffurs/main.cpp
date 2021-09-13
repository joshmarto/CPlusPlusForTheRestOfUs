#include <iostream>
#include <iomanip>
#include <string>
#include "Dog.h"

using namespace std;

int main(int argc, char** argv) {
	cout << setiosflags(ios::fixed);
	cout << setprecision(2);
	
	int dogCount = 0;
	float totalPremium = 0;
	
	cout << "Please enter the number of dogs in your household." << endl;
	cin >> dogCount;
	
	int c = 1;
	float actualPremium = 0;
	while(c <= dogCount){
		Dog currentDog;
		cout << "Enter the name of dog #" << c << ": ";
		cin >> currentDog.dogName;
		cin.ignore();
		cout << "Enter the breed code for " << currentDog.dogName << ": ";
		cin >> currentDog.breedCode;
		cin.ignore();
		currentDog.discount();
		currentDog.displayBreed();
		cout << "Enter the current age for " << currentDog.dogName << ": ";
		cin >> currentDog.age;
		cin.ignore();
		cout << "Enter the weight for " << currentDog.dogName << " (nearest kg): ";
		cin >> currentDog.weight;
		cin.ignore();
		currentDog.calculatePremium();
		currentDog.seniorDiscount();
		currentDog.displayPremium();
		
		actualPremium += currentDog.actualPremium;
		c++;
	}
	cout << "The total monthly premium for all dogs is " << actualPremium << endl;
	return 0;
}
