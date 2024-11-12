#include "Fixed.hpp"

// Fixed::Fixed(int number): x(number) {} //Constructor

Fixed::Fixed()
{
    std::cout << "Default constructor called \n";
    x = 0;
}

Fixed::Fixed(Fixed& other) //copy constructor
{
    std::cout << "Copy constructor called \n";
     x = other.getRawBits();
     
}
 
Fixed& Fixed::operator=(Fixed& other) // copy assigned constructor
{
    std::cout << "Copy assignment operator called\n";
    if (this != &other)
        x = other.getRawBits();

    return *this;
}

// Fixed& Fixed::operator>(const Fixed& other)
// {
//     if (x > other.x)
//         return *this;
//     else
//         return other;
// }

Fixed::~Fixed() {
     std::cout << "Destructor called\n";
} //destructor

int Fixed::getRawBits()
{
    std::cout << "getRawBits member function called\n";
    return x;
}

void Fixed::setRawBits(int const raw)
{
    std::cout << "setRawBits member function called\n";
    x = raw;
}
