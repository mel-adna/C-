#pragma once
#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
private:
    std::string target;

public:
    PresidentialPardonForm();
    PresidentialPardonForm(const PresidentialPardonForm &oth);
    PresidentialPardonForm &operator=(const PresidentialPardonForm &oth);
    virtual ~PresidentialPardonForm();

    PresidentialPardonForm(const std::string &target);

    virtual void execute(Bureaucrat const & executor) const;
};