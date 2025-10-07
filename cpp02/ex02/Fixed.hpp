#pragma once

#include <iostream>
#include <cmath>

class Fixed
{
private:
    int _rawBits;
    static const int _fractionalBits = 8;

public:
    Fixed();                              // Default constructor
    Fixed(const int n);                   // From int
    Fixed(const float f);                 // From float
    Fixed(const Fixed &other);            // Copy constructor
    Fixed &operator=(const Fixed &other); // Copy assignment
    ~Fixed();                             // Destructor

    // Comparison operators
    bool operator>(const Fixed &other) const;
    bool operator<(const Fixed &other) const;
    bool operator>=(const Fixed &other) const;
    bool operator<=(const Fixed &other) const;
    bool operator==(const Fixed &other) const;
    bool operator!=(const Fixed &other) const;

    // arithmetic operators
    Fixed operator+(const Fixed &other) const;
    Fixed operator-(const Fixed &other) const;
    Fixed operator*(const Fixed &other) const;
    Fixed operator/(const Fixed &other) const;

    // Static min/max functions
    static Fixed &min(Fixed &a, Fixed &b);
    static const Fixed &min(const Fixed &a, const Fixed &b);
    static Fixed &max(Fixed &a, Fixed &b);
    static const Fixed &max(const Fixed &a, const Fixed &b);

    // Increment / Decrement operators
    Fixed &operator++();   // Pre-increment
    Fixed operator++(int); // Post-increment
    Fixed &operator--();   // Pre-decrement
    Fixed operator--(int); // Post-decrement

    // Getters/Setters
    int getRawBits() const;
    void setRawBits(int const raw);

    // Conversions
    float toFloat() const;
    int toInt() const;
};

// Output operator (outside the class)
std::ostream &operator<<(std::ostream &out, const Fixed &fixed);
