#ifndef NEWZOMBIE_HPP
#define NEWZOMBIE_HPP

#include <iostream>

class Zombie
{
private:
    std::string name;

public:
    Zombie(std::string name);
    ~Zombie();

    void announce();
};

Zombie *newZombie(std::string name);
void randomChump(std::string name);

#endif