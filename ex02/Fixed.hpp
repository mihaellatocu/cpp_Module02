#include <iostream>
#include <cmath>

class Fixed
{
private:
    int x;
    static const int fractionalBits = 8;
public:
    Fixed();
    Fixed(const int number);
    Fixed(const float number);

    Fixed(const Fixed& other);
    Fixed& operator=(const Fixed& other);

   
    //Getter
    int getRawBits(void) const;
    //Setter
    void setRawBits(int const raw);
    
    //Public methods
    float toFloat(void)const; //conversie to float
    int toInt(void) const; //conversie la intreg

     ~Fixed();

    int operator<(const Fixed& other) const;
    int operator>(const Fixed& other) const;
    int operator<=(const Fixed& other) const;
    int operator>=(const Fixed& other) const;
    int operator==(const Fixed& other) const;
    int operator!=(const Fixed& other) const;

    Fixed operator+(const Fixed& other) const;
    Fixed operator*(const Fixed& other) const;
    Fixed operator/(const Fixed& other) const;
    Fixed operator-(const Fixed& other) const;

    Fixed& operator++(void);
    Fixed& operator--(void);
    Fixed  operator++(int);
    Fixed  operator--(int);

};

std::ostream &operator<<(std::ostream &os, const Fixed& fixed);

