#include "FragTrap.hpp"

int main()
{
    std::cout << "=== FragTrap Tests ===" << std::endl;

    FragTrap f1("Rocky");
    FragTrap f2(f1);
    FragTrap f3("Temporary");
    f3 = f1;

    std::cout << "\n=== Actions ===" << std::endl;
    f1.attack("Target");
    f1.takeDamage(20);
    f1.beRepaired(15);
    f1.highFivesGuys();

    std::cout << "\n=== Destructors at end of scope ===" << std::endl;
    return 0;
}
