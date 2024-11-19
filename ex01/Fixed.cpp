#include "Fixed.hpp"

Fixed::Fixed()
{
    std::cout << "Default constructor called \n";
    x = 0;
}
// *!conversie la INT
Fixed::Fixed(const int number) //normall constr
{
    std::cout << "Int constructor called \n";
    x = number << fractionalBits;
}

Fixed::Fixed(const float number) // float to fixed
{
    std::cout << "Float constructor  called \n";
    x = roundf(number * (1 << fractionalBits));
}

Fixed::Fixed(const Fixed& other) //copy constr
{
    std::cout << "Copy constructor called \n";
    this->x = other.x;
}

int Fixed::getRawBits(void) const
{
    //std::cout << "getRawBits member function called\n";
    return this->x; // sau x?
}
//!! to explain the pointer
Fixed& Fixed::operator=(const Fixed& other)
{
    std::cout << "Copy assignment operator called\n";
    if (this != &other) 
        this->x = other.getRawBits();
    
    return *this;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called\n";
}

void Fixed::setRawBits(int const raw)
{
    std::cout << "setRawBits member function called\n";
    this->x = raw;
}

//**! convert fix point nr to float(zecimal)
float Fixed::toFloat(void) const
{
    return ((float)(x) / ( 1 << fractionalBits)); // x/256
}

// !convert to int
int Fixed::toInt(void) const
{
    return (x >> fractionalBits); // ex 010000 >> 2 = 010000(2^16) >> 2 = 0100(2^2 = 4)
}

std::ostream    &operator<<(std::ostream &os, const Fixed& fixed)
{
    os << fixed.toFloat();
    return (os);
}