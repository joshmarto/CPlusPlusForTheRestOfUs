#ifndef FULLNAME_H
#define FULLNAME_H

#include "EnhancedString.h"

class FullName : public EnhancedString
{
	public:
		FullName(std::string value);
		string getFirstName();
		string getLastName();
		string getMiddleName();
		string getInitials();
		void displayInfo();
		~FullName();
	protected:
};

#endif
