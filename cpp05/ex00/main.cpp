#include "Bureaucrat.hpp"
#include <iostream>

int main() {
    try {
        Bureaucrat bob("Bob", 2);
        std::cout << bob << std::endl;

        bob.incrementGrade();   // 2 → 1
        std::cout << bob << std::endl;

        bob.incrementGrade();   // Error: already at 1
        std::cout << bob << std::endl;  // Won’t be executed
    }
    catch (std::exception &e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "-----------------------------" << std::endl;

    try {
        Bureaucrat jim("Jim", 151);   // Invalid grade
        std::cout << jim << std::endl;
    }
    catch (std::exception &e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "-----------------------------" << std::endl;

    try {
        Bureaucrat alice("Alice", 149);
        std::cout << alice << std::endl;

        alice.decrementGrade();   // 149 → 150
        std::cout << alice << std::endl;

        alice.decrementGrade();   // Error: already at 150
        std::cout << alice << std::endl;  // Won’t be executed
    }
    catch (std::exception &e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
