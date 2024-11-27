#include "Fixed.hpp"

int main()
{
    Fixed a(10);

    //a++;
    //Fixed b(20.5f - 5.0f);
    //Fixed const c( Fixed( 5.05f ) * Fixed( 2 ) );
    std::cout << a-- << std::endl;
    //++a;
    std::cout << a << std::endl;
    std::cout << --a << std::endl;
    return (0);
}