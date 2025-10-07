#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : Name("Default"), HitPoint(10), EnergyPoint(10), AttackDamage(0)
{
    std::cout << "ClapTrap " << Name << " constructed!" << std::endl;
}

ClapTrap::ClapTrap(const std::string &name) : Name(name), HitPoint(10), EnergyPoint(10), AttackDamage(0)
{
    std::cout << "ClapTrap " << Name << " constructed!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
    : Name(other.Name),
      HitPoint(other.HitPoint),
      EnergyPoint(other.EnergyPoint),
      AttackDamage(other.AttackDamage)
{
    std::cout << "ClapTrap " << Name << " copy constructed!" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
    if (this != &other)
    {
        Name = other.Name;
        HitPoint = other.HitPoint;
        EnergyPoint = other.EnergyPoint;
        AttackDamage = other.AttackDamage;
    }
    std::cout << "ClapTrap " << Name << " copy assigned!" << std::endl;
    return *this;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap " << Name << " destroyed!" << std::endl;
}

void ClapTrap::attack(const std::string &target)
{
    if (HitPoint <= 0)
    {
        std::cout << "ClapTrap " << Name << " can't attack (no hit points)." << std::endl;
        return;
    }
    if (EnergyPoint <= 0)
    {
        std::cout << "ClapTrap " << Name << " can't attack (no energy points)." << std::endl;
        return;
    }
    EnergyPoint -= 1;
    std::cout << "ClapTrap " << Name << " attacks " << target
              << ", causing " << AttackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (HitPoint <= 0)
    {
        std::cout << "ClapTrap " << Name << " is already at 0 HP." << std::endl;
        return;
    }
    HitPoint -= amount;
    if (HitPoint < 0)
        HitPoint = 0;
    std::cout << "ClapTrap " << Name << " takes " << amount
              << " damage! HP left: " << HitPoint << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (HitPoint <= 0 || EnergyPoint <= 0)
    {
        std::cout << "ClapTrap " << Name << " can't repair." << std::endl;
        return;
    }
    EnergyPoint -= 1;
    HitPoint += amount;
    std::cout << "ClapTrap " << Name << " repairs itself, recovering "
              << amount << " hit points! HP now: " << HitPoint << std::endl;
}
