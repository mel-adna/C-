#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;

    i->makeSound(); // cat sound
    j->makeSound(); // dog sound
    meta->makeSound(); // animal sound

    const WrongAnimal *w = new WrongAnimal();
    const WrongAnimal *t = new WrongCat();

    std::cout << t->getType() << " " << std::endl;
    w->makeSound();
    t->makeSound();

    delete i;
    delete j;
    delete meta;

    return 0;
}
