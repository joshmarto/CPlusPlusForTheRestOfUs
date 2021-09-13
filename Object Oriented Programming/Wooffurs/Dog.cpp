#include "Dog.h"
#include <iostream>
#include <string>

using namespace std;

Dog::Dog()
{
	this->basePremium = 0;
	this->actualPremium = 0;
	this->weight = 0;
	this->age = 0;
	this->subjectToDiscount = false;
	this->dogName = "";
	this->breed = "";
}

void Dog::calculatePremium(){
	float premium = 0;
	switch(this->breedCode){
		case 'p':
			if(this->weight < 20){
				this->basePremium = 30.20;
			} else{
				this->basePremium = 35.15;
			}
			break;
		case 'd':
			if(this->weight < 35){
				this->basePremium = 28.16;
			} else{
				this->basePremium = 30.0;
			}
			break;
		case 'r':
			if(this->weight < 45){
				this->basePremium = 28;
			} else{
				this->basePremium = 29.75;
			}
			break;
		case 'g':
			if(this->weight < 30){
				this->basePremium = 27.50;
			} else{
				this->basePremium = 29.75;
			}
			break;
		case 'c':
			if(this->weight < 24){
				this->basePremium = 25.10;
			} else{
				this->basePremium = 27.50;
			}
			break;
		case 't':
			if(this->weight < 55){
				this->basePremium = 25.10;
			} else{
				this->basePremium = 25.20;
			}
			break;
		case 's':
			if(this->weight < 45){
				this->basePremium = 20.01;
			} else{
				this->basePremium = 20.55;
			}
			break;
		case 'k':
			this->basePremium = 30.20;
			break;
		case 'm':
			if(this->weight < 38){
				this->basePremium = 15.50;
			} else{
				this->basePremium = 18.15;
			}
			break;
		case 'h':
			if(this->weight < 20){
				this->basePremium = 9.95;
			} else{
				this->basePremium = 12.00;
			}
			break;
		case 'b':
			if(this->weight < 35){
				this->basePremium = 4.95;
			} else{
				this->basePremium = 8.95;
			}
			break;
		default:
			cout << "Verify your input." << endl;
	}
	
	this->actualPremium = this->basePremium;
	
	if (this->weight > 50){
		this->actualPremium -= this->basePremium * 0.25;
	}
}

void Dog::discount(){
	switch(this->breedCode){
		case 'p':
			this->breed = "pitbull";
			this->subjectToDiscount = false;
			break;
		case 'd':
			this->breed = "doberman";
			this->subjectToDiscount = true;
			break;
		case 'r':
			this->breed = "rottweiler";
			this->subjectToDiscount = false;
			break;
		case 'g':
			this->breed = "german shepherd";
			this->subjectToDiscount = true;
			break;
		case 'c':
			this->breed = "chow chow";
			this->subjectToDiscount = true;
			break;
		case 't':
			this->breed = "great dane";
			this->subjectToDiscount = false;
			break;
		case 's':
			this->breed = "presa canario";
			this->subjectToDiscount = false;
			break;
		case 'k':
			this->breed = "akita";
			this->subjectToDiscount = false;
			break;
		case 'm':
			this->breed = "alaskan malamute";
			this->subjectToDiscount = true;
			break;
		case 'h':
			this->breed = "husky";
			this->subjectToDiscount = true;
			break;
		case 'b':
			this->breed = "other breed";
			this->subjectToDiscount = true;
			break;
		default:
			cout << "Sorry. That is not a valid breed code. Please re- enter this dog's information." << endl;
	}
}

void Dog::seniorDiscount(){
	if(this->subjectToDiscount == true && this->age > 13){
		this->actualPremium -= this->basePremium * 0.20;
	}
}

void Dog::displayBreed(){
	cout << this->dogName << " is a " << this->breed << endl;
}

void Dog::displayPremium(){
	cout << "The monthly premium for " << this->dogName << " is " << this->actualPremium << endl;
}

