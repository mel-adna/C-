#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : name("default AForm"), isSigned(false), gradeToSign(150), gradeToExecute(150) {}

AForm::AForm(const AForm &oth) : name(oth.name), isSigned(oth.isSigned), gradeToSign(oth.gradeToSign), gradeToExecute(oth.gradeToExecute) {}

AForm &AForm::operator=(const AForm &oth)
{
    if (this != &oth)
        this->isSigned = oth.isSigned;
    return *this;
}

AForm::~AForm() {}

AForm::AForm(const std::string &name, int gradeToSign, int gradeToExecute) : name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
}

std::string AForm::getName() const
{
    return this->name;
}

bool AForm::getIsSigned() const
{
    return this->isSigned;
}

int AForm::getGradeToSign() const
{
    return this->gradeToSign;
}

int AForm::getGradeToExecute() const
{
    return this->gradeToExecute;
}

void AForm::beSigned(const Bureaucrat &b)
{
    if (b.getGrade() <= this->gradeToSign)
        this->isSigned = true;
    else
        throw GradeTooLowException();
}

void AForm::execute(Bureaucrat const & executor) const
{
    if (!this->isSigned)
        throw GradeTooLowException();
    if (executor.getGrade() > this->gradeToExecute)
        throw GradeTooLowException();
}

const char *AForm::GradeTooHighException::what() const throw()
{
    return "AForm: Grade too high!";
}

const char *AForm::GradeTooLowException::what() const throw()
{
    return "AForm: Grade too low!";
}

std::ostream &operator<<(std::ostream &os, const AForm &oth)
{
    os << "AForm " << oth.getName()
       << " | Signed: " << (oth.getIsSigned() ? "true" : "false")
       << " | Grade to sign: " << oth.getGradeToSign()
       << " | Grade to execute: " << oth.getGradeToExecute();
    return os;
}