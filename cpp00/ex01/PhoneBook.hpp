#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>

class PhoneBook
{
	private:
		Contact contacts[8];
		int totalContact;
	public:
		PhoneBook();
		~PhoneBook();

		void	addContact();
		void	searchContacts() const;
};

#endif
