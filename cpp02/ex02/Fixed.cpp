#include "Fixed.hpp"
#include <cmath>

// Default constructor
Fixed::Fixed() : _rawBits(0) {}

// Copy constructor
Fixed::Fixed(const Fixed &other)
{
    *this = other;
}

// Int constructor
Fixed::Fixed(const int n)
{
    _rawBits = n << _fractionalBits;
}

// Float constructor
Fixed::Fixed(const float f)
{
    _rawBits = roundf(f * (1 << _fractionalBits));
}

// Destructor
Fixed::~Fixed() {}

// Copy assignment operator
Fixed &Fixed::operator=(const Fixed &other)
{
    if (this != &other)
        this->_rawBits = other.getRawBits();
    return *this;
}

// Getter for raw bits
int Fixed::getRawBits() const
{
    return _rawBits;
}

// Setter for raw bits
void Fixed::setRawBits(int const raw)
{
    _rawBits = raw;
}

// Convert fixed-point to float
float Fixed::toFloat() const
{
    return (float)_rawBits / (1 << _fractionalBits);
}

// Convert fixed-point to int
int Fixed::toInt() const
{
    return _rawBits >> _fractionalBits;
}

// Comparison operators
bool Fixed::operator>(const Fixed &other) const
{
    return this->_rawBits > other._rawBits;
}

bool Fixed::operator<(const Fixed &other) const
{
    return this->_rawBits < other._rawBits;
}

bool Fixed::operator>=(const Fixed &other) const
{
    return this->_rawBits >= other._rawBits;
}

bool Fixed::operator<=(const Fixed &other) const
{
    return this->_rawBits <= other._rawBits;
}

bool Fixed::operator==(const Fixed &other) const
{
    return this->_rawBits == other._rawBits;
}

bool Fixed::operator!=(const Fixed &other) const
{
    return this->_rawBits != other._rawBits;
}

// Arithmetic operators
Fixed Fixed::operator+(const Fixed &other) const
{
    return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed &other) const
{
    return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed &other) const
{
    return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed &other) const
{
    // Division by zero is not handled, as per subject specification
    return Fixed(this->toFloat() / other.toFloat());
}

// Increment / Decrement operators

// Pre-increment
Fixed &Fixed::operator++()
{
    this->_rawBits++;
    return *this;
}

// Post-increment
Fixed Fixed::operator++(int)
{
    Fixed temp(*this);
    this->_rawBits++;
    return temp;
}

// Pre-decrement
Fixed &Fixed::operator--()
{
    this->_rawBits--;
    return *this;
}

// Post-decrement
Fixed Fixed::operator--(int)
{
    Fixed temp(*this);
    this->_rawBits--;
    return temp;
}

// Static min/max functions
Fixed &Fixed::min(Fixed &a, Fixed &b)
{
    return (a < b) ? a : b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
    return (a < b) ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
    return (a > b) ? a : b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
    return (a > b) ? a : b;
}

// Output stream operator (outside class)
std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
    out << fixed.toFloat();
    return out;
}
