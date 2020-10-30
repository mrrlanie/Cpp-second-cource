#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdint>

#include "RationalNums.h"

template<class T>
class complexNumClass {
 private:
  rationalNumClass<T> real;
  rationalNumClass<T> image;

 public:
  complexNumClass(const T &number) : real(number), image(0) {}

  complexNumClass(const rationalNumClass<T> &realNum = 0, const rationalNumClass<T> &imageNum= 0)
  : real(realNum), image(imageNum) {}

  //standart operations

  complexNumClass &operator+=(const complexNumClass &other) {
    this->real += other.real;
    this->image += other.image;
    return *this;
  }

  complexNumClass &operator-=(const complexNumClass &other) {
    this->real -= other.real;
    this->image -= other.image;
    return *this;
  }

  complexNumClass &operator*=(const complexNumClass &other) {
    auto this_real = this->real;
    auto other_real = other.real;
    this->real = this->real * other.real - this->image * other.image;
    this->image = this->image * other_real + this_real * other.image;
    return *this;
  }

  complexNumClass &operator/=(const complexNumClass &other) {
    auto this_real = this->real;
    auto other_real = other.real;
    this->real = (this->real * other.real + this->image * other.image)
        / (other.real * other.real + other.image * other.image);
    this->image = (this->image * other_real - this_real * other.image)
        / (other_real * other_real + other.image * other.image);
    return *this;
  }

  complexNumClass operator+(const complexNumClass &other) const {
    auto someReal = this->real + other.real;
    auto someImage = this->image + other.image;
    return complexNumClass(someReal, someImage);
  }

  complexNumClass operator-(const complexNumClass &other) const {
    auto someReal = this->real - other.real;
    auto someImage = this->image - other.image;
    return complexNumClass(someReal, someImage);
  }

  complexNumClass operator*(const complexNumClass &other) const {
    auto someReal = this->real * other.real - this->image * other.image;
    auto someImage = this->image * other.real + this->real * other.image;
    return complexNumClass(someReal, someImage);
  }

  complexNumClass operator/(const complexNumClass &other) const {
    auto someReal = (this->real * other.real + this->image * other.image)
        / (other.real * other.real + other.image * other.image);
    auto someImage = (this->image * other.real - this->real * other.image)
        / (other.real * other.real + other.image * other.image);
    return complexNumClass(someReal, someImage);
  }

  complexNumClass operator-() const {
    auto someReal = -this->real;
    auto someImage = -this->image;
    return complexNumClass(someReal, someImage);
  }

  complexNumClass &operator=(const complexNumClass &other) = default;

  // boolean operations

  bool operator==(const complexNumClass &other) const {
    return (this->real == other.real) && (this->image == other.image);
  }

  bool operator!=(const complexNumClass &other) const {
    return (this->real != other.real) || (this->image != other.image);
  }

  //other stuff

  friend std::ostream &operator<<(std::ostream &os, const complexNumClass &num) {
    return os << "(" << num.real << ", " << num.image << ")";
  }

  double Arg() const {
    auto result = this->real == 0 && this->image == 0 ? 0 : atan(this->image.toDouble() / this->real.toDouble());
    return this->real < 0 ? (this->image < 0 ? result - M_PI : result + M_PI) : result;
  }

  double Abs() const {
    return std::sqrt((this->real * this->real + this->image * this->image).toDouble());
  }

  complexNumClass Pow(const int exp = 2) const {
    complexNumClass a(this->real, this->image), b = a;
    for (int i = 1; i < exp; i++) {
      a *= b;
    }
    return a;
  }

  rationalNumClass<T> getterReal() const {
    return this->real;
  }

  void setterReal(rationalNumClass<T> s_real) {
    this->real = s_real;
  }

  rationalNumClass<T> getterImage() const {
    return this->image;
  }

  void setterImage(rationalNumClass<T> s_imag) {
    this->image = s_imag;
  }
};