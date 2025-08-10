#include <iostream>
#include <iomanip>
#include <limits>
#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
    contactCount = 0;
}

static std::string formatField(std::string str)
{
    if (str.length() > 10)
        return str.substr(0, 9) + ".";
    return str;
}

bool hasTab(const std::string &str)
{
    return str.find('\t') != std::string::npos;
}

void PhoneBook::addContact()
{
    Contact newContact;
    std::string input;

    std::cout << "Enter First Name: ";
    std::getline(std::cin, input);
    if (input.empty() || hasTab(input))
    {
        std::cout << "Error: Tabs are not allowed!" << std::endl;
        return;
    }
    newContact.setFirstName(input);

    std::cout << "Enter Last Name: ";
    std::getline(std::cin, input);
    if (input.empty() || hasTab(input))
    {
        std::cout << "Error: Tabs are not allowed!" << std::endl;
        return;
    }
    newContact.setLastName(input);

    std::cout << "Enter Nickname: ";
    std::getline(std::cin, input);
    if (input.empty() || hasTab(input))
    {
        std::cout << "Error: Tabs are not allowed!" << std::endl;
        return;
    }
    newContact.setNickname(input);

    std::cout << "Enter Phone Number: ";
    std::getline(std::cin, input);
    if (input.empty() || hasTab(input))
    {
        std::cout << "Error: Tabs are not allowed!" << std::endl;
        return;
    }
    newContact.setPhoneNumber(input);

    std::cout << "Enter Darkest Secret: ";
    std::getline(std::cin, input);
    if (input.empty() || hasTab(input))
    {
        std::cout << "Error: Tabs are not allowed!" << std::endl;
        return;
    }
    newContact.setDarkestSecret(input);

    int index = contactCount % 8;
    contacts[index] = newContact;
    contactCount++;

    std::cout << "Contact added at index " << index << "!" << std::endl;
}

void PhoneBook::searchContacts()
{
    int total = (contactCount < 8) ? contactCount : 8;

    if (total == 0)
    {
        std::cout << "No contacts available!" << std::endl;
        return;
    }

    std::cout << std::setw(10) << "Index" << "|"
              << std::setw(10) << "First Name" << "|"
              << std::setw(10) << "Last Name" << "|"
              << std::setw(10) << "Nickname" << "|" << std::endl;

    for (int i = 0; i < total; i++)
    {
        std::cout << std::setw(10) << i << "|"
                  << std::setw(10) << formatField(contacts[i].getFirstName()) << "|"
                  << std::setw(10) << formatField(contacts[i].getLastName()) << "|"
                  << std::setw(10) << formatField(contacts[i].getNickname()) << std::endl;
    }

    std::cout << "Enter index to view full contact: ";
    std::string input;
    std::getline(std::cin, input);

    if (input.length() == 1 && std::isdigit(input[0]))
    {
        int index = input[0] - '0';
        if (index >= 0 && index < total)
        {
            Contact c = contacts[index];
            std::cout << "First Name: " << c.getFirstName() << std::endl;
            std::cout << "Last Name: " << c.getLastName() << std::endl;
            std::cout << "Nickname: " << c.getNickname() << std::endl;
            std::cout << "Phone Number: " << c.getPhoneNumber() << std::endl;
            std::cout << "Darkest Secret: " << c.getDarkestSecret() << std::endl;
        }
        else
        {
            std::cout << "Invalid index." << std::endl;
        }
    }
    else
    {
        std::cout << "Invalid index." << std::endl;
    }
}
