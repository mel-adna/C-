#pragma once
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
private:
    AMateria *materias[4]; // can remember up to 4 Materias

public:
    MateriaSource();
    MateriaSource(const MateriaSource &other);
    MateriaSource &operator=(const MateriaSource &other);
    virtual ~MateriaSource();

    virtual void learnMateria(AMateria *m);
    virtual AMateria *createMateria(std::string const &type);
};