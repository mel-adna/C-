#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"


int main()
{
    // Create a MateriaSource (the "teacher")
    IMateriaSource *src = new MateriaSource();
    src->learnMateria(new Ice());  // teacher learns Ice
    src->learnMateria(new Cure()); // teacher learns Cure

    // Create a character "me"
    ICharacter *me = new Character("me");

    // Ask teacher to create Ice & Cure, and equip them
    AMateria *tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    // me->unequip(1);

    // Create another character "bob"
    ICharacter *bob = new Character("bob");

    // Use the spells on bob
    me->use(0, *bob); // Ice attack
    me->use(1, *bob); // Cure heal

    // Clean up memory
    delete bob;
    delete me;
    delete src;

    return 0;
}
