#pragma once
#include <iostream>
#include <string>

class ClapTrap
{
protected:
    std::string Name;
    int HitPoint;
    int EnergyPoint;
    int AttackDamage;

public:
    ClapTrap();
    ClapTrap(const std::string &name);
    ClapTrap(const ClapTrap &other);
    ClapTrap &operator=(const ClapTrap &other);
    virtual ~ClapTrap(); // <<-- virtual

    virtual void attack(const std::string &target); // <<-- virtual
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
};
