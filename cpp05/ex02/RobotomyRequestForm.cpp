#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), target("default") {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &oth) : AForm(oth), target(oth.target) {}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &oth)
{
    if (this != &oth)
    {
        AForm::operator=(oth);
        this->target = oth.target;
    }
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm("RobotomyRequestForm", 72, 45), target(target) {}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
    AForm::execute(executor);
    
    std::cout << "* drilling noises *" << std::endl;
    
    static bool initialized = false;
    if (!initialized) {
        std::srand(std::time(NULL));
        initialized = true;
    }
    
    if (std::rand() % 2 == 0)
        std::cout << this->target << " has been robotomized successfully!" << std::endl;
    else
        std::cout << "The robotomy failed on " << this->target << "." << std::endl;
}