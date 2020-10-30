#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdint>
#include <numeric>
 

template<class T>
class rationalNumClass {
 private:
  T numerator;
  T denominator;
 
 public:
  rationalNumClass(const T &num = 0, const T &den = 1) {
    this->numerator = num;
    this->denominator = den;
    
    if (this->denominator < 0) {
      this->numerator = -this->numerator;
      this->denominator = -this->denominator;
    }
    cutterNums();
  }

  T gcd (int a, int b) {
    if (b == 0)
      return a;
    else
      return gcd (b, a % b);
  }

  void cutterNums() {
    auto nod = gcd(this->numerator < 0 ? -this->numerator : this->numerator, this->denominator);
    this->denominator /= nod;
    this->numerator /= nod;
  }
 
  // standart operations

  rationalNumClass<T> &operator+=(const rationalNumClass<T> &other) {
    this->numerator = this->numerator * other.denominator + other.numerator * this->denominator;
    this->denominator = this->denominator * other.denominator;
    cutterNums();
    return *this;
  }

  rationalNumClass<T> &operator-=(const rationalNumClass<T> &other) {
    this->numerator = this->numerator * other.denominator - other.numerator * this->denominator;
    this->denominator = this->denominator * other.denominator;
    cutterNums();
    return *this;
  }

  rationalNumClass<T> &operator*=(const rationalNumClass<T> &other) {
    this->numerator = this->numerator * other.numerator;
    this->denominator = this->denominator * other.denominator;
    cutterNums();
    return *this;
  }

  rationalNumClass<T> &operator/=(const rationalNumClass<T> &other) {
    auto tmp = other.numerator;
    this->numerator = this->numerator * other.denominator;
    this->denominator = this->denominator * tmp;
    cutterNums();
    return *this;
  }
 
  rationalNumClass<T> operator+(const rationalNumClass<T> &other) const {
    auto a = numerator * other.denominator + other.numerator * denominator;
    auto b = denominator * other.denominator;
    return rationalNumClass<T>(a, b);
  }
 
  rationalNumClass<T> operator-(const rationalNumClass<T> &other) const {
    return -other + *this;
  }
 
  rationalNumClass<T> operator*(const rationalNumClass<T> &other) const {
    return rationalNumClass<T>(numerator * other.numerator, denominator * other.denominator);
  }
 
  rationalNumClass<T> operator/(const rationalNumClass<T> &other) const {
    return rationalNumClass<T>(numerator * other.denominator, denominator * other.numerator);
  }
 
  rationalNumClass<T> operator-() const {
    return rationalNumClass<T>(-numerator, denominator);
  }

  rationalNumClass<T> &operator=(const rationalNumClass<T> &other) = default;

  // bool operators

  bool operator>(const rationalNumClass<T> &other) const {
    return this->numerator * other.denominator > other.numerator * this->denominator;
  }

  bool operator<(const rationalNumClass<T> &other) const {
    return other > *this;
  }

  bool operator>=(const rationalNumClass<T> &other) const {
    return *this > other || *this == other;
  }

  bool operator<=(const rationalNumClass<T> &other) const {
    return *this < other || *this == other;
  }

  bool operator==(const rationalNumClass<T> &other) const {
    return this->numerator == other.numerator && this->denominator == other.denominator;
  }
 
  bool operator!=(const rationalNumClass<T> &other) const {
    return !this->operator==(other);
  }

  // other stuff
 
  double toDouble() const {
    return (double) numerator / denominator;
  }
 
  friend std::ostream &operator<< (std::ostream &os,
                                  const rationalNumClass<T> &rtNum) {
    return os << rtNum.getterNum() << "/" << rtNum.getterDen();
  }
 
  T getterNum() const {
    return numerator;
  }
 
  T getterDen() const {
    return denominator;
  }
};