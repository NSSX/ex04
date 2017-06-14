#include "Fixed.class.hpp"


const int Fixed::_fractionalBits = 8;




bool    Fixed::operator>(Fixed const & rhs) const{

    if(this->_n > rhs.getRawBits()){
        return true;
    }else{
        return false;
    }
}

bool    Fixed::operator<(Fixed const & rhs) const{
    if(this->_n < rhs.getRawBits()){
        return true;
    }else{
        return false;
    }
}

bool    Fixed::operator>=(Fixed const & rhs) const{
    if(this->_n >= rhs.getRawBits()){
        return true;
    }else{
        return false;
    }
}

bool    Fixed::operator<=(Fixed const & rhs) const{
    if(this->_n <= rhs.getRawBits()){
        return true;
    }else{
        return false;
    }
}

bool    Fixed::operator==(Fixed const & rhs) const{
    if(this->_n == rhs.getRawBits()){
        return true;
    }else{
        return false;
    }
}

bool    Fixed::operator!=(Fixed const & rhs) const{
    if(this->_n != rhs.getRawBits()){
        return true;
    }else{
        return false;
    }
}

Fixed & Fixed::operator++(){
    ++this->_n;
    return *this;
}
Fixed & Fixed::operator--(){
    --this->_n;
    return *this;
}

Fixed   Fixed::operator++(int){
    Fixed myResult(*this);
    ++(*this);
    return myResult;
}
Fixed   Fixed::operator--(int){
    Fixed myResult(*this);
    --(*this);
    return myResult;
}

Fixed  Fixed::operator+(Fixed const & rhs) const{
    Fixed temp;
    temp.setRawBits(this->_n + rhs.getRawBits());
    return temp;
}

Fixed  Fixed::operator-(Fixed const & rhs) const{
    Fixed temp;
    temp.setRawBits(this->_n - rhs.getRawBits());
    return temp;
}

Fixed  Fixed::operator*(Fixed const & rhs) const{
     Fixed temp;

     int myResult = this->_n * rhs.getRawBits();

     myResult = myResult + (1 << (_fractionalBits - 1));
     myResult = myResult >> _fractionalBits;
     temp.setRawBits(myResult);
     return temp;
}

//2.525
Fixed  Fixed::operator/(Fixed const & rhs) const{
    Fixed temp;

    int myResult = this->_n << _fractionalBits;
    myResult += rhs.getRawBits() / 2;
    myResult /= rhs.getRawBits();

    temp.setRawBits(myResult);
    return temp;
}

int Fixed::getRawBits( void ) const{
    return(this->_n);
}
void Fixed::setRawBits( int const raw ){
//    std::cout << "setRawBits member function called" << std::endl;
    this->_n = raw;
}

Fixed::Fixed( Fixed const & src){
    //std::cout << "Copy constructor called" << std::endl;
    *this = src;
    return;
}

Fixed::Fixed(void) : _n(0){
//    std::cout << "Default constructor called" << std::endl;
    return;
}

Fixed::Fixed(const int mInteger){
    //std::cout << "Int constructor called" << std::endl;
    this->_n = mInteger << _fractionalBits;
}

Fixed::Fixed(const float mFloat){
    //std::cout << "Float constructor called" << std::endl;
    this->_n = (int)(roundf((1 << _fractionalBits) * mFloat));
}

float Fixed::toFloat( void ) const{
    return (float)(this->_n) / (1 << _fractionalBits);
}

int Fixed::toInt( void ) const{
    return ((int)(this->_n) >> _fractionalBits);
}

Fixed::~Fixed(void){
//    std::cout << "Destructor called" << std::endl;
    return;
}

Fixed & Fixed::operator=(Fixed const & rhs){
//    std::cout << "Assignation operator called" << std::endl;
    this->_n = rhs.getRawBits();
    return *this;
}

Fixed &Fixed::min(Fixed &a, Fixed &b){
    if(a < b){
        return a;
    }else{
        return b;
    }
}

Fixed &Fixed::max(Fixed &a, Fixed &b){
    if(a > b){
        return a;
    }else{
        return b;
    }
}
Fixed const &Fixed::min(Fixed const &a, Fixed const &b) {
    if(a < b){
        return a;
    }else{
        return b;
    }
}

Fixed const &Fixed::max(Fixed const &a, Fixed const &b) {
    if(a > b){
        return a;
    }else{
        return b;
    }
}

std::ostream & operator<<(std::ostream & o, Fixed const & rhs){
    o << rhs.toFloat();
    return o;
}
