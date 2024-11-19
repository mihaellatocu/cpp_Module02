#pragma once
#include <iostream>
#include <cmath>

class Fixed
{
private:
    int x;
    static const int fractionalBits = 8;
public:
    //Constructors
    Fixed();
    Fixed(const int number);
    Fixed(const float number);
    
    Fixed(const Fixed& other); // copy constructor
    
    Fixed& operator=(const Fixed& other); // coppy assign
    
    //Getter
    int getRawBits(void) const;
    //Setter
    void setRawBits(int const raw);
    
    //Destructor
    ~Fixed();

    //Public methods
    float toFloat(void)const; //conversie to float
    int toInt(void) const; //conversie la intreg
};

std::ostream    &operator<<(std::ostream &os, const Fixed& fixed);
