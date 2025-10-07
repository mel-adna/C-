#pragma once
#include <iostream>

class Brain
{
private:
    std::string ideas[100];

public:
    Brain();
    Brain(const Brain &other);
    Brain &operator=(const Brain &other);
    ~Brain();

    void setIdeas(int index, const std::string &idea);
    std::string getIdea(int index) const;
};