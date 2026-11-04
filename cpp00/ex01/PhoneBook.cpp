#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : totalContact(0) {}

PhoneBook::~PhoneBook() {}

static std::string	getInput(std::string prompt) {
	std::string input;
	while (input.empty()) {
		std::cout << prompt;
		if (!std::getline(std::cin, input)) {
			if (std::cin.eof()) {
				std::cout << "\nEOF detected. Exiting program." << std::endl;
				std::exit(0);
			}
			return "";
		}
	}
	return input;
}

static std::string truncate(const std::string &str) {
	if (str.length() > 10)
		return str.substr(0, 9) + ".";
	return str;
}

void	PhoneBook::addContact() {
	std::string fName = getInput("Enter first name: ");
	std::string lName = getInput("Enter last name: ");
	std::string nName = getInput("Enter nickname: ");
	std::string pNumber = getInput("Enter phone number: ");
	std::string dSecret = getInput("Enter darkest secret: ");

	if (fName.empty() || lName.empty() || nName.empty() || pNumber.empty() || dSecret.empty()) {
		std::cout << "Error: All fields must be filled. Contact not added." << std::endl;
		return;
	}
	contacts[totalContact % 8].setContact(fName, lName, nName, pNumber, dSecret);
	if (totalContact < 8)
		totalContact++;
	else
		totalContact = 8 + (totalContact % 8) + 1;
	std::cout << "Contact added successfully!" << std::endl;
}

void	PhoneBook::searchContacts() const {
	int count = totalContact < 8 ? totalContact : 8;

	if (count == 0) {
		std::cout << "No contacts to display." << std::endl;
		return;
	}
	std::cout << std::setw(10) << "Index" << "|"
			  << std::setw(10) << "First Name" << "|"
			  << std::setw(10) << "Last Name" << "|"
			  << std::setw(10) << "Nickname" << std::endl;

	for (int i = 0; i < count; ++i) {
		std::cout << std::setw(10) << i + 1 << "|"
				  << std::setw(10) << truncate(contacts[i].getFirstName()) << "|"
				  << std::setw(10) << truncate(contacts[i].getLastName()) << "|"
				  << std::setw(10) << truncate(contacts[i].getNickname()) << std::endl;
	}

	std::string input = getInput("Enter the index of the contact to view details: ");
	if (input.empty())
		return;
	
	if (input.length() != 1 || input[0] < '1' || input[0] > '0' + count)
	{
		std::cout << "Invalid index." << std::endl;
		return;
	}
	int i = input[0] - '1';
	std::cout << "First Name:      " << contacts[i].getFirstName() << std::endl;
	std::cout << "Last Name:       " << contacts[i].getLastName() << std::endl;
	std::cout << "Nick Name:       " << contacts[i].getNickname() << std::endl;
	std::cout << "Phone Number:    " << contacts[i].getPhoneNumber() << std::endl;
	std::cout << "Darkest Secret:  " << contacts[i].getDarkestSecret() << std::endl;
}

