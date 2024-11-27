#include "Fixed.hpp"

Fixed::Fixed()
{
    //std::cout << "Default constructor called \n";
    x = 0;
}

Fixed::Fixed(const int number)// transforming int to fix in constructor
{
    //std::cout << "Int constructor called \n";
    x = number << fractionalBits;
}
Fixed::Fixed(const float number) // transforming float to fix
{
    //std::cout << "Float constructor  called \n";
    x = roundf(number * (1 << fractionalBits));
}

Fixed::Fixed(const Fixed& other)
{
    //std::cout << "Copy constructor called \n";
    this->x = other.x;
}

int Fixed::getRawBits(void) const
{
    //std::cout << "getRawBits member function called\n";
    return this->x;
}

void Fixed::setRawBits(int const raw)
{
    //std::cout << "setRawBits member function called\n";
    this->x = raw;
}

Fixed& Fixed::operator=(const Fixed& other)
{
    //std::cout << "Copy assignment operator called\n";
    if (this != &other) 
        this->x = other.getRawBits();
    return *this;
}


Fixed::~Fixed()
{
    //std::cout << "Destructor called\n";
}

float Fixed::toFloat(void)const //conversie la float
{
    return ((float)(x) / (1 << fractionalBits));
}

int Fixed::toInt(void) const //conversie la intreg
{
    return (x >> fractionalBits);
}


std::ostream &operator<<(std::ostream &os, const Fixed& fixed)
{
    os << fixed.toFloat();
    return (os);
}


int Fixed::operator<(const Fixed& other) const
{
    if (this->getRawBits() < other.getRawBits())
        return (1);
    return (0);
}

int Fixed::operator>(const Fixed& other) const
{
    if (this->x > other.x)
        return (1);
    return (0);
}

int Fixed::operator<=(const Fixed& other) const
{
    if (this->getRawBits() <= other.getRawBits())
        return (1);
    return (0);
}

int Fixed::operator>=(const Fixed& other) const
{
    if (this->x >= other.x)
        return (1);
    return (0);
}

int Fixed::operator==(const Fixed& other) const
{
    if (this->x == other.x)
        return (1);
    return (0);
}

int Fixed::operator!=(const Fixed& other) const
{
    if (this->x != other.x)
        return (1);
    return (0);
}

Fixed Fixed::operator+(const Fixed& other) const
{
    return (this->toFloat() + other.toFloat());
}

Fixed Fixed::operator*(const Fixed& other) const
{
    return (this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed& other) const
{
    if (other.toFloat() != 0)
        return (this->toFloat() / other.toFloat());
    return (0);
}

Fixed Fixed::operator-(const Fixed& other) const
{
    return (this->toFloat() - other.toFloat());
}

Fixed& Fixed::operator++(void) //echivalent cu ++a
{
    this->x += 1;
    return *this;
}

Fixed& Fixed::operator--(void)// decrementare inainte de utilizare --a
{
    this->x -= 1;
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed temp = *this;
    this->x += 1;
    return temp;
}

Fixed Fixed::operator--(int)
{
    Fixed temp = *this;
    this->x -= 1;
    return temp;
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
    if (a > b)
        return (a);
    return (b);
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
    if (a > b)
        return (a);
    return (b);
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
    if (a < b)
        return (a);
    return (b);
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
    if (a < b)
        return (a);
    return (b);
}