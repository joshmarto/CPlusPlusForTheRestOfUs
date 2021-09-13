#ifndef DOG_H
#define DOG_H
#include <iostream>
#include <string>

using namespace std;

class Dog
{
	public:
		float basePremium; float actualPremium; int weight; int age; bool subjectToDiscount; char breedCode; string dogName; string breed;
		Dog();
		void calculatePremium();
		void discount();
		void seniorDiscount();
		void displayBreed();
		void displayPremium();
	protected:
};

#endif
