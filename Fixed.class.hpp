#ifndef FIXED_CLASS_HPP
# define FIXED_CLASS_HPP

#include <iostream>
#include <cmath>

class Fixed{

public:
    Fixed(void);
    Fixed(const int mInteger);
    Fixed(const float mFloat);
    Fixed( Fixed const & src);
    ~Fixed(void);

    Fixed & operator=(Fixed const & rhs);
    Fixed  operator+(Fixed const & rhs) const;
    Fixed  operator-(Fixed const & rhs) const;
    Fixed  operator*(Fixed const & rhs) const;
    Fixed  operator/(Fixed const & rhs) const;

    bool    operator>(Fixed const & rhs) const;
    bool    operator<(Fixed const & rhs) const;
    bool    operator>=(Fixed const & rhs) const;
    bool    operator<=(Fixed const & rhs) const;
    bool    operator==(Fixed const & rhs) const;
    bool    operator!=(Fixed const & rhs) const;

    Fixed & operator++();
    Fixed & operator--();
    Fixed   operator++(int);
    Fixed   operator--(int);

    float toFloat( void ) const;
    int toInt( void ) const;
    int getRawBits( void ) const;
    void setRawBits( int const raw );

    static Fixed &min(Fixed &a, Fixed &b);
    static Fixed &max(Fixed &a, Fixed &b);

    static Fixed const &min(Fixed const &a, Fixed const &b);
    static Fixed const &max(Fixed const &a, Fixed const &b);

private:
    int _n;
    static const int  _fractionalBits;
};

std::ostream & operator<<(std::ostream & o, Fixed const & rhs);
Fixed	inOperation(char **expr);
#endif
