#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), target("default") {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &oth) : AForm(oth), target(oth.target) {}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &oth)
{
    if (this != &oth)
    {
        AForm::operator=(oth);
        this->target = oth.target;
    }
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : AForm("PresidentialPardonForm", 25, 5), target(target) {}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
    AForm::execute(executor);
    
    std::cout << this->target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}