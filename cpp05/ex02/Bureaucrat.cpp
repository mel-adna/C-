#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat() : name("Default Name"), grade(150) {}

Bureaucrat::Bureaucrat(const Bureaucrat &oth) : name(oth.name), grade(oth.grade) {}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : name(name)
{
    if (grade < 1)
        throw GradeTooHighException();
    else if (grade > 150)
        throw GradeTooLowException();
    this->grade = grade;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &oth)
{
    if (this != &oth)
        this->grade = oth.grade;
    return *this;
}

Bureaucrat::~Bureaucrat() {}

std::string Bureaucrat::getName() const
{
    return this->name;
}

int Bureaucrat::getGrade() const
{
    return this->grade;
}

void Bureaucrat::incrementGrade()
{
    if (grade - 1 < 1)
        throw GradeTooHighException();
    grade--;
}

void Bureaucrat::decrementGrade()
{
    if (grade + 1 > 150)
        throw GradeTooLowException();
    grade++;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grade too high!";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grade too low!";
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &oth)
{
    return os << oth.getName() << ", bureaucrat grade " << oth.getGrade() << ".";
}

void Bureaucrat::signForm(AForm &form)
{
    try
    {
        form.beSigned(*this);
        std::cout << this->getName() << " signed " << form.getName() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << this->getName() << " couldn't sign " << form.getName()
                  << " because " << e.what() << std::endl;
    }
}

void Bureaucrat::executeForm(AForm const & form) const
{
    try
    {
        form.execute(*this);
        std::cout << this->getName() << " executed " << form.getName() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << this->getName() << " couldn't execute " << form.getName()
                  << " because " << e.what() << std::endl;
    }
}
