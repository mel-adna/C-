#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() 
    : ClapTrap("Default_clap_name"), FragTrap(), ScavTrap(), Name("Default")
{
    HitPoint = FragTrap::HitPoint;    // 100
    EnergyPoint = ScavTrap::EnergyPoint; // 50
    AttackDamage = FragTrap::AttackDamage; // 30
    std::cout << "DiamondTrap " << Name << " default constructed!" << std::endl;
}

DiamondTrap::DiamondTrap(const std::string &name) 
    : ClapTrap(name + "_clap_name"), FragTrap(), ScavTrap(), Name(name)
{
    HitPoint = FragTrap::HitPoint;    
    EnergyPoint = ScavTrap::EnergyPoint; 
    AttackDamage = FragTrap::AttackDamage; 
    std::cout << "DiamondTrap " << Name << " constructed!" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other)
    : ClapTrap(other), FragTrap(other), ScavTrap(other), Name(other.Name)
{
    std::cout << "DiamondTrap " << Name << " copy constructed!" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other)
{
    if (this != &other)
    {
        ClapTrap::operator=(other);
        Name = other.Name;
    }
    std::cout << "DiamondTrap " << Name << " copy assigned!" << std::endl;
    return *this;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap " << Name << " destroyed!" << std::endl;
}

void DiamondTrap::attack(const std::string &target)
{
    ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
    std::cout << "DiamondTrap name: " << Name
              << ", ClapTrap name: " << ClapTrap::Name << std::endl;
}
