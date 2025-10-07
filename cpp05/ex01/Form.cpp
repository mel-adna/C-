#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : name("default Form"), isSigned(false), gradeToSign(150), gradeToExecute(150) {}

Form::Form(const Form &oth) : name(oth.name), isSigned(oth.isSigned), gradeToSign(oth.gradeToSign), gradeToExecute(oth.gradeToExecute) {}

Form &Form::operator=(const Form &oth)
{
    if (this != &oth)
        this->isSigned = oth.isSigned;
    return *this;
}

Form::~Form() {}

Form::Form(const std::string &name, int gradeToSign, int gradeToExecute) : name(name), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
}

std::string Form::getName() const
{
    return this->name;
}

bool Form::getIsSigned() const
{
    return this->isSigned;
}

int Form::getGradeToSign() const
{
    return this->gradeToSign;
}

int Form::getGradeToExecute() const
{
    return this->gradeToExecute;
}

void Form::beSigned(const Bureaucrat &b)
{
    if (b.getGrade() <= this->gradeToSign)
        this->isSigned = true;
    else
        throw GradeTooLowException();
}

const char *Form::GradeTooHighException::what() const throw()
{
    return "Form: Grade too high!";
}

const char *Form::GradeTooLowException::what() const throw()
{
    return "Form: Grade too low!";
}

std::ostream &operator<<(std::ostream &os, const Form &oth)
{
    os << "Form " << oth.getName()
       << " | Signed: " << (oth.getIsSigned() ? "true" : "false")
       << " | Grade to sign: " << oth.getGradeToSign()
       << " | Grade to execute: " << oth.getGradeToExecute();
    return os;
}