#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), target("default") {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &oth) : AForm(oth), target(oth.target) {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &oth)
{
    if (this != &oth)
    {
        AForm::operator=(oth);
        this->target = oth.target;
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("ShrubberyCreationForm", 145, 137), target(target) {}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
    AForm::execute(executor);
    
    std::ofstream file((this->target + "_shrubbery").c_str());
    if (file.is_open())
    {
        file << "       /\\      " << std::endl;
        file << "      /  \\     " << std::endl;
        file << "     /    \\    " << std::endl;
        file << "    /______\\   " << std::endl;
        file << "       ||      " << std::endl;
        file << "       ||      " << std::endl;
        file << std::endl;
        file << "     /\\   /\\   " << std::endl;
        file << "    /  \\ /  \\  " << std::endl;
        file << "   /    X    \\ " << std::endl;
        file << "  /    / \\    \\" << std::endl;
        file << " /_____\\_/_____\\" << std::endl;
        file << "       ||      " << std::endl;
        file << "       ||      " << std::endl;
        file.close();
    }
}