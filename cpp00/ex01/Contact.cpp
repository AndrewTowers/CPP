#include "Contact.hpp"

Contact::Contact() {}

Contact::~Contact() {}

void    Contact::setContact(const std::string &fName, const std::string &lName, const std::string &nName, const std::string &pNumber, const std::string &dSecret) {
    this->firstName = fName;
    this->lastName = lName;
    this->nickname = nName;
    this->phoneNumber = pNumber;
    this->darkestSecret = dSecret;
}

std::string Contact::getFirstName() const {
    return this->firstName;
}

std::string Contact::getLastName() const {
    return this->lastName;
}

std::string Contact::getNickname() const {
    return this->nickname;
}

std::string Contact::getPhoneNumber() const {
    return this->phoneNumber;
}

std::string Contact::getDarkestSecret() const {
    return this->darkestSecret;
}
