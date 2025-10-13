// #include "Bureaucrat.hpp"
// #include "AForm.hpp"
// #include "ShrubberyCreationForm.hpp"
// #include "RobotomyRequestForm.hpp"
// #include "PresidentialPardonForm.hpp"
// #include "Intern.hpp"
// #include <iostream>


// int main() {

//     std::cout << "=== Testing Intern Class ===" << std::endl;

//     try {
//         // Create bureaucrats
//         Bureaucrat alice("Alice", 1);   // High-level bureaucrat
//         Bureaucrat bob("Bob", 50);      // Mid-level bureaucrat

//         std::cout << alice << std::endl;
//         std::cout << bob << std::endl;

//         // Create an intern
//         Intern someRandomIntern;

//         std::cout << "\n=== Testing Form Creation by Intern ===" << std::endl;

//         // Test creating valid forms
//         AForm* rrf = someRandomIntern.makeForm("robotomy request", "Bender");
//         if (rrf) {
//             std::cout << *rrf << std::endl;
//             alice.signForm(*rrf);
//             alice.executeForm(*rrf);
//             delete rrf;
//         }

//         std::cout << std::endl;

//         AForm* scf = someRandomIntern.makeForm("shrubbery creation", "home");
//         if (scf) {
//             std::cout << *scf << std::endl;
//             bob.signForm(*scf);
//             bob.executeForm(*scf);
//             delete scf;
//         }

//         std::cout << std::endl;

//         AForm* ppf = someRandomIntern.makeForm("presidential pardon", "Arthur Dent");
//         if (ppf) {
//             std::cout << *ppf << std::endl;
//             alice.signForm(*ppf);
//             alice.executeForm(*ppf);
//             delete ppf;
//         }

//         std::cout << "\n=== Testing Invalid Form Names ===" << std::endl;

//         // Test creating invalid forms
//         AForm* invalidForm1 = someRandomIntern.makeForm("invalid form", "target");
//         if (invalidForm1) {
//             delete invalidForm1;
//         }

//         AForm* invalidForm2 = someRandomIntern.makeForm("", "target");
//         if (invalidForm2) {
//             delete invalidForm2;
//         }

//         AForm* invalidForm3 = someRandomIntern.makeForm("random nonsense", "target");
//         if (invalidForm3) {
//             delete invalidForm3;
//         }

//         std::cout << "\n=== Testing Multiple Interns ===" << std::endl;

//         Intern intern1;
//         Intern intern2;
        
//         AForm* form1 = intern1.makeForm("robotomy request", "Target1");
//         AForm* form2 = intern2.makeForm("shrubbery creation", "Target2");
        
//         if (form1) {
//             std::cout << *form1 << std::endl;
//             delete form1;
//         }
        
//         if (form2) {
//             std::cout << *form2 << std::endl;
//             delete form2;
//         }

//     }
//     catch (std::exception &e) {
//         std::cerr << "Exception caught: " << e.what() << std::endl;
//     }

//     return 0;
// }


#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    Intern someRandomIntern;               // create an Intern object
    AForm* form;                           // pointer to a form (base class)

    // 1️⃣ Intern tries to create a known form
    form = someRandomIntern.makeForm("robotomy request", "Bender");
    if (form) {
        std::cout << *form << std::endl;   // just to show form info (optional)
        delete form;                       // always delete to avoid leaks
    }

    std::cout << "-----------------------------" << std::endl;

    // 2️⃣ Intern tries to create an unknown form
    form = someRandomIntern.makeForm("unknown form", "TargetX");
    if (!form) {
        std::cout << "No form created." << std::endl;
    }

    return 0;
}

