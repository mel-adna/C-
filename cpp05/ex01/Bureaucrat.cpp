#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat() : name("Defult Name"), Grade(150) {}

Bureaucrat::Bureaucrat(const Bureaucrat &oth) : name(oth.name), Grade(oth.Grade) {}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : name(name)
{
    if (grade < 1)
        throw GradeTooHighException();
    else if (grade > 150)
        throw GradeTooLowException();
    this->Grade = grade;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &oth)
{
    if (this != &oth)
        this->Grade = oth.Grade;
    return *this;
}

Bureaucrat::~Bureaucrat() {}

std::string Bureaucrat::getName() const
{
    return this->name;
}

int Bureaucrat::getGrade() const
{
    return this->Grade;
}

void Bureaucrat::incrementGrade()
{
    if (Grade - 1 < 1)
        throw GradeTooHighException();
    Grade--;
}

void Bureaucrat::decrementGrade()
{
    if (Grade + 1 > 150)
        throw GradeTooLowException();
    Grade++;
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

void Bureaucrat::signForm(Form &form)
{
    try
    {
        form.beSigned(*this);
        std::cout << this->getName() << " signed " << form.getName() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << this->getName() << " couldn’t sign " << form.getName()
                  << " because " << e.what() << std::endl;
    }
}