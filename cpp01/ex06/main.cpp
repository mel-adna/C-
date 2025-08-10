#include "Harl.hpp"
#include <iostream>

int main(int ac, char **av)
{
    if (ac != 2 || std::string(av[1]).empty())
        return 1;

    Harl harl;
    harl.complain(av[1]);
    return 0;
}
