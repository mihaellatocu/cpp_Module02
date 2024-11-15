#include "Fixed.hpp"
#include <iostream>

int main()
{
    Fixed a(10);
   // a.setRawBits(7);
    Fixed b(a);
    Fixed c;
    Fixed d(10.5f);
    std::cout << d.getRawBits() << "\n";
    c = a;
    std::cout << c.getRawBits();

    return (0);
}