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
        file << "                  %%%,%%%%%%%" << std::endl;
        file << "                   ,'%% \\-*%%%%%%%" << std::endl;
        file << "             ;%%%%%*%   _%%%%\"" << std::endl;
        file << "              ,%%%       \\(_.*%%%%." << std::endl;
        file << "              % *%%, ,%%%%*(    '" << std::endl;
        file << "            %^     ,*%%% )\\|,%%*%,_" << std::endl;
        file << "                 *%    \\/ ).-\"*%%*" << std::endl;
        file << "                     _./ / *%," << std::endl;
        file << "             _________/#/_____________" << std::endl;
        file << "            mel-adna" << std::endl;
        file.close();
    }
}