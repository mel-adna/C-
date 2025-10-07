#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    Bureaucrat bob("Bob", 50);
    Bureaucrat jim("Jim", 120);

    Form taxForm("Tax Form", 75, 100);
    Form secretForm("Secret Form", 40, 30);

    std::cout << taxForm << std::endl;
    std::cout << secretForm << std::endl;
    std::cout << "-----------------------------" << std::endl;

    bob.signForm(taxForm);      // Bob has grade 50 → OK (needs 75)
    jim.signForm(taxForm);      // Jim has grade 120 → too low
    bob.signForm(secretForm);   // Bob has grade 50 → too low (needs 40)

    std::cout << "-----------------------------" << std::endl;
    std::cout << taxForm << std::endl;
    std::cout << secretForm << std::endl;

    return 0;
}
