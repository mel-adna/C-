#pragma once

#include <iostream>

class Fixed
{
private:
    int _rawBits;
    static const int _fractionalBits = 8;

public:
    Fixed();                              // Default constructor
    Fixed(const Fixed &other);            // Copy constructor
    Fixed &operator=(const Fixed &other); // Copy assignment
    ~Fixed();                             // Destructor

    int getRawBits() const;
    void setRawBits(int const raw);
};
