#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern &oth) {
    (void)oth;
}

Intern &Intern::operator=(const Intern &oth) {
    (void)oth;
    return *this;
}

Intern::~Intern() {}

// Function pointer type for form creation
typedef AForm* (*FormCreator)(const std::string &target);

// Form creation functions
static AForm* createShrubberyForm(const std::string &target) {
    return new ShrubberyCreationForm(target);
}

static AForm* createRobotomyForm(const std::string &target) {
    return new RobotomyRequestForm(target);
}

static AForm* createPresidentialForm(const std::string &target) {
    return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(const std::string &formName, const std::string &target) {
    // Array of form names and their corresponding creators
    const std::string formNames[3] = {
        "shrubbery creation",
        "robotomy request", 
        "presidential pardon"
    };
    
    FormCreator formCreators[3] = {
        createShrubberyForm,
        createRobotomyForm,
        createPresidentialForm
    };

    // Find the matching form name
    for (int i = 0; i < 3; i++) {
        if (formName == formNames[i]) {
            std::cout << "Intern creates " << formName << std::endl;
            return formCreators[i](target);
        }
    }

    // No matching form found
    std::cout << "Intern could not create form: " << formName << " (unknown form type)" << std::endl;
    return NULL;
}