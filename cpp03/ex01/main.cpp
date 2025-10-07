#include "ScavTrap.hpp"

int main()
{
    // std::cout << "=== Constructors Test ===" << std::endl;
    // ScavTrap scav1("Guardian");
    // ScavTrap scav2(scav1);
    // ScavTrap scav3("Temp");
    ScavTrap  *sp = new ScavTrap;
    // scav3 = scav1;

    // std::cout << "\n=== Actions Test ===" << std::endl;
    // scav1.attack("Enemy1");
    // scav1.takeDamage(30);
    // scav1.beRepaired(20);
    // scav1.guardGate();

    sp->attack("gehgioew");
    // std::cout << "\n=== More Attacks until energy runs out ===" << std::endl;
    // for (int i = 0; i < 55; i++)
    //     scav1.attack("Dummy");

    // std::cout << "\n=== Destructors will be called automatically ===" << std::endl;

    delete sp;
    return 0;
}
