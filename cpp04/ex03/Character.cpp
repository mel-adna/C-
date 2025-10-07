#include "Character.hpp"

Character::Character() : name("unknown")
{
    for (int i = 0; i < 4; i++)
        inventory[i] = 0;
    for (int i = 0; i < 100; i++)
        floor[i] = 0;
    itemCount = 0;
}

Character::Character(std::string const &name) : name(name)
{
    for (int i = 0; i < 4; i++)
        inventory[i] = 0;
    for (int i = 0; i < 100; i++)
        floor[i] = 0;
    itemCount = 0;
}

Character::Character(const Character &other) : name(other.name)
{
    for (int i = 0; i < 4; i++)
    {
        if (other.inventory[i])
            inventory[i] = other.inventory[i]->clone();
        else
            inventory[i] = 0;
    }
}

Character &Character::operator=(const Character &other)
{
    if (this != &other)
    {
        name = other.name;
        for (int i = 0; i < 4; i++)
        {
            delete inventory[i];
            inventory[i] = 0;
        }
        for (int i = 0; i < 4; i++)
        {
            if (other.inventory[i])
                inventory[i] = other.inventory[i]->clone();
        }
    }
    return *this;
}

Character::~Character()
{
    for (int i = 0; i < 4; i++)
        delete inventory[i];
    for (int i = 0; i < itemCount; i++)
        delete floor[i];
}

std::string const &Character::getName() const
{
    return name;
}

// Equip: put Materia in first free slot
void Character::equip(AMateria *m)
{
    if (!m)
        return;
    for (int i = 0; i < 4; i++)
    {
        if (!inventory[i])
        {
            inventory[i] = m;
            return;
        }
    }
}

void Character::unequip(int idx)
{
    if (idx >= 0 && idx < 4)
    {
        if (itemCount < 100)
            floor[itemCount++] = inventory[idx];
        inventory[idx] = 0;
    }
}

void Character::use(int idx, ICharacter &target)
{
    if (idx >= 0 && idx < 4 && inventory[idx])
        inventory[idx]->use(target);
}
