#include <iostream>
#include <string>

using namespace std;

class Contact
{
    private:
        string name;
        string phoneNumber;
    public:
        Contact();
        ~Contact();
};

Contact::Contact()
{
}

Contact::~Contact()
{
}

class PhoneBook
{
    private:
        Contact contacts[8];
    public:
        PhoneBook();
        ~PhoneBook();
};

PhoneBook::PhoneBook()
{
}

PhoneBook::~PhoneBook()
{
}

int main()
{
    PhoneBook phonebook;
    return 0;
}