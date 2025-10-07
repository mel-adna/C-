#include "ClapTrap.hpp"

int main()
{
    ClapTrap a("Mohamed");

    a.attack("Enemy");
    a.takeDamage(3);
    a.beRepaired(2);
    a.attack("Enemy");

    return 0;
}
