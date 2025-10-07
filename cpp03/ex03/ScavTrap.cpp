#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("DefaultScav")
{
    HitPoint = 100;
    EnergyPoint = 50;
    AttackDamage = 20;
    std::cout << "ScavTrap " << Name << " default constructed!" << std::endl;
}

// Param constructor
ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name)
{
    HitPoint = 100;
    EnergyPoint = 50;
    AttackDamage = 20;
    std::cout << "ScavTrap " << Name << " constructed!" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other) // Call base class copy constructor
{
    std::cout << "ScavTrap " << Name << " copy constructed!" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
    ClapTrap::operator=(other); // Reuse base assignment
    std::cout << "ScavTrap " << Name << " copy assigned!" << std::endl;
    return *this;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap " << Name << " destroyed!" << std::endl;
}

// Override attack
void ScavTrap::attack(const std::string &target)
{
    if (HitPoint <= 0)
    {
        std::cout << "ScavTrap " << Name << " can't attack (no hit points)." << std::endl;
        return;
    }
    if (EnergyPoint <= 0)
    {
        std::cout << "ScavTrap " << Name << " can't attack (no energy points)." << std::endl;
        return;
    }
    EnergyPoint -= 1;
    std::cout << "ScavTrap " << Name << " fiercely attacks " << target
              << ", causing " << AttackDamage << " points of damage!" << std::endl;
}

// Special ability
void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << Name << " is now in Gate keeper mode." << std::endl;
}
