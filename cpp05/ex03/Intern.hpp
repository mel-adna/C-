#pragma once
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
public:
    Intern();
    Intern(const Intern &oth);
    Intern &operator=(const Intern &oth);
    ~Intern();

    AForm* makeForm(const std::string &formName, const std::string &target);
};