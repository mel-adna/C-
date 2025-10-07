#include "FragTrap.hpp"

// Default constructor
FragTrap::FragTrap() : ClapTrap("DefaultFrag")
{
    HitPoint = 100;
    EnergyPoint = 100;
    AttackDamage = 30;
    std::cout << "FragTrap " << Name << " default constructed!" << std::endl;
}

// Param constructor
FragTrap::FragTrap(const std::string &name) : ClapTrap(name)
{
    HitPoint = 100;
    EnergyPoint = 100;
    AttackDamage = 30;
    std::cout << "FragTrap " << Name << " constructed!" << std::endl;
}

// Copy constructor
FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
    std::cout << "FragTrap " << Name << " copy constructed!" << std::endl;
}

// Copy assignment
FragTrap &FragTrap::operator=(const FragTrap &other)
{
    if (this != &other)
    {
        ClapTrap::operator=(other);
    }
    std::cout << "FragTrap " << Name << " copy assigned!" << std::endl;
    return *this;
}

// Destructor
FragTrap::~FragTrap()
{
    std::cout << "FragTrap " << Name << " destroyed!" << std::endl;
}

// Special ability
void FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap " << Name << " requests positive high fives! ✋" << std::endl;
}
