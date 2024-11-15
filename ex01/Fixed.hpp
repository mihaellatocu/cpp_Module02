#include <iostream>
#include <cmath>

class Fixed
{
private:
    int x;
    const int fractionalBits = 8;
public:
    Fixed();
    Fixed(const int number);
    Fixed(const float number);//const float point nr
    Fixed(Fixed& other); // copy constructor
    Fixed& operator=(Fixed& other); // coppy assign
    
    int getRawBits(void);
    void setRawBits(int const raw);
    ~Fixed();

    float toFloat(void); //conversie to float
    int toInt(void); //conversie la intreg
};

Fixed::Fixed()
{
    std::cout << "Default constructor called \n";
    x = 0;
}
// *!conversie la INT
Fixed::Fixed(const int number) //normall constr
{
    std::cout << "Default constructor with integer called \n";
    x = number << fractionalBits;
}

Fixed::Fixed(const float number)
{
    std::cout << "Default constructor with float called \n";
    x = roundf(number * (1 << fractionalBits));
}

Fixed::Fixed(Fixed& other) //copy constr
{
    std::cout << "Copy constructor called \n";
    this->x = other.x;
}

Fixed& Fixed::operator=(Fixed& other)
{
     std::cout << "Copy assignment operator called\n";
    x = other.getRawBits();
    
    return *this;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called\n";
}

int Fixed::getRawBits(void)
{
    std::cout << "getRawBits member function called\n";
    return this->x; // sau x?
}

void Fixed::setRawBits(int const raw)
{
std::cout << "setRawBits member function called\n";
x = raw;
}

//**! convert fix point nr to float(zecimal)
float Fixed::toFloat(void)
{
    return static_cast<float>(x) / ( 1 <<fractionalBits);
}

// !convert to int
int Fixed::toInt(void)
{
    return x >> fractionalBits; // ex 010000 >> 2 = 010000(2^16) >> 2 = 0100(2^2 = 4)
}