#pragma once
#include <ostream>

class Form;

class Bureaucrat
{
private:
    std::string name;
    int Grade;

public:
    Bureaucrat();
    Bureaucrat(const Bureaucrat &oth);
    Bureaucrat(const std::string &name, int grade);
    Bureaucrat &operator=(const Bureaucrat &oth);
    ~Bureaucrat();

    std::string getName() const;
    int getGrade() const;

    void signForm(Form &form);
    void incrementGrade();
    void decrementGrade();

    class GradeTooHighException : public std::exception
    {
    public:
        const char *what() const throw();
    };
    class GradeTooLowException : public std::exception
    {
    public:
        const char *what() const throw();
    };
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &oth);