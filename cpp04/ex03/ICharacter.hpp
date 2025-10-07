#pragma once
#include <string>

class AMateria; // just tell the compiler it exists

class ICharacter
{
public:
    virtual ~ICharacter() {}

    // Returns the character's name
    virtual std::string const &getName() const = 0;

    // Equip a Materia (put it in inventory)
    virtual void equip(AMateria *m) = 0;

    // Unequip a Materia (does NOT delete it)
    virtual void unequip(int idx) = 0;

    // Use a Materia at slot idx on target
    virtual void use(int idx, ICharacter &target) = 0;
};