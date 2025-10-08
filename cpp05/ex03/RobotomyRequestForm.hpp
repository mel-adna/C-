#pragma once
#include "AForm.hpp"
#include <cstdlib>
#include <ctime>

class RobotomyRequestForm : public AForm
{
private:
    std::string target;

public:
    RobotomyRequestForm();
    RobotomyRequestForm(const RobotomyRequestForm &oth);
    RobotomyRequestForm &operator=(const RobotomyRequestForm &oth);
    virtual ~RobotomyRequestForm();

    RobotomyRequestForm(const std::string &target);

    virtual void execute(Bureaucrat const & executor) const;
};