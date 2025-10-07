#include "DiamondTrap.hpp"

int main()
{
    DiamondTrap d("Diamond");

    d.attack("Enemy");
    d.takeDamage(20);
    d.beRepaired(15);
    d.whoAmI();

    return 0;
}
