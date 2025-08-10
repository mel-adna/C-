#include <iostream>
#include <string>
#include "PhoneBook.hpp"

int main()
{
    PhoneBook phoneBook;
    std::string command;

    std::cout << "Welcome to My Awesome PhoneBook!" << std::endl;

    while (true)
    {
        std::cout << "Enter a command (ADD, SEARCH, EXIT): ";
        std::getline(std::cin, command);

        if (std::cin.eof())
        {
            std::cout << "\nEOF detected. Exiting." << std::endl;
            break;
        }
        else if (command == "ADD")
        {
            phoneBook.addContact();
        }
        else if (command == "SEARCH")
        {
            phoneBook.searchContacts();
        }
        else if (command == "EXIT")
        {
            std::cout << "GoodBye!" << std::endl;
            break;
        }
        else
        {
            continue;
        }
    }
    return 0;
}