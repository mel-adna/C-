#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
    Animal *meta = new Dog();
    Animal *another = new Cat();

    meta->makeSound();    // Woof!
    another->makeSound(); // Meow!

    delete meta;
    delete another;

    return 0;
}
