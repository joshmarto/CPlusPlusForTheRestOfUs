#ifndef ENHANCEDSTRING_H
#define ENHANCEDSTRING_H

#include <string>

using namespace std;

class EnhancedString /*: public std::string*/ // Inheritance
{
	public:
		static const string oneSpace;
		static const string twoSpaces;
		static const string vowels;
		string data; // Encapsulation
		EnhancedString(string value);
		void getFromKeyboard(string message);
		void singleSpace();
		void trim();
		int countWords();
		int countVowels();
		~EnhancedString(); // Deconstructor
	protected:
};

#endif
