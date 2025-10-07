#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

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

    delete i;
    delete j;
    delete meta;

    return 0;
}
