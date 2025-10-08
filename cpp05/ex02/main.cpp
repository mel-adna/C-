#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main() {
    std::cout << "=== Testing AForm and Concrete Forms ===" << std::endl;

    try {
        // Create bureaucrats
        Bureaucrat alice("Alice", 1);   // High-level bureaucrat
        Bureaucrat bob("Bob", 50);      // Mid-level bureaucrat
        Bureaucrat charlie("Charlie", 150); // Low-level bureaucrat

        std::cout << alice << std::endl;
        std::cout << bob << std::endl;
        std::cout << charlie << std::endl;

        std::cout << "\n=== Testing ShrubberyCreationForm ===" << std::endl;
        
        ShrubberyCreationForm shrub("garden");
        std::cout << shrub << std::endl;

        // Charlie tries to sign (should fail)
        charlie.signForm(shrub);
        
        // Bob signs successfully  
        bob.signForm(shrub);
        
        // Bob executes successfully
        bob.executeForm(shrub);

        std::cout << "\n=== Testing RobotomyRequestForm ===" << std::endl;
        
        RobotomyRequestForm robot("Bender");
        std::cout << robot << std::endl;

        // Bob signs successfully
        bob.signForm(robot);
        
        // Alice executes successfully
        alice.executeForm(robot);
        
        // Test multiple executions to see random results
        alice.executeForm(robot);
        alice.executeForm(robot);

        std::cout << "\n=== Testing PresidentialPardonForm ===" << std::endl;
        
        PresidentialPardonForm pardon("Arthur Dent");
        std::cout << pardon << std::endl;

        // Alice signs and executes
        alice.signForm(pardon);
        alice.executeForm(pardon);
        
        // Bob tries to execute (should fail - not high enough grade)
        bob.executeForm(pardon);

        std::cout << "\n=== Testing Error Cases ===" << std::endl;
        
        // Try to execute unsigned form
        RobotomyRequestForm unsignedForm("Test");
        alice.executeForm(unsignedForm);

    }
    catch (std::exception &e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
