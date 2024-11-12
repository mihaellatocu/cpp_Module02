#include <iostream>

class Fixed
{
    private:
        int x;
        static int const z = 8; 

    public:
        Fixed();
        Fixed(Fixed& other);
        Fixed& operator=(Fixed& other);
        ~Fixed();

        int getRawBits();

        void setRawBits(int const raw);

};