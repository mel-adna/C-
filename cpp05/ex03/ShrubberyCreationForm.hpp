#pragma once
#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm
{
private:
    std::string target;

public:
    ShrubberyCreationForm();
    ShrubberyCreationForm(const ShrubberyCreationForm &oth);
    ShrubberyCreationForm &operator=(const ShrubberyCreationForm &oth);
    virtual ~ShrubberyCreationForm();

    ShrubberyCreationForm(const std::string &target);

    virtual void execute(Bureaucrat const & executor) const;
};