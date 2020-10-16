#include "num.h"
#include <iostream>

int64_t newValue;

inline Num::Num(int value, int modulo) {
     this->modulo = modulo;
    this->value = value % modulo;
}

inline Num &Num::operator=(const Num& other) {
    value = other.value;
    modulo = other.modulo;
    return *this;
}

inline Num Num::operator+(const Num& other) {
    newValue = (this->value + other.value) % modulo;
    return Num(newValue, modulo);
}

inline Num Num::operator-(const Num& other) {
    newValue = (this->value - other.value) % modulo;
    return Num(newValue, modulo);
}

inline Num Num::operator*(const Num& other) {
    newValue = (this->value * other.value) % modulo;
    return Num(newValue, modulo);
}

inline Num &Num::operator+=(const Num &other) {
    value = (value + other.value) % modulo;
    return *this;
}

inline Num &Num::operator-=(const Num &other) {
    if (value < other.value) {
        value = (value - other.value + modulo) % modulo;
    } else {
        value = (value - other.value) % modulo;
    }
    return *this;
}

inline Num &Num::operator*=(const Num &other) {
    value = (value * other.value) % modulo;
    return *this;
}

inline Num Num::operator+(int num) {
    newValue = (this->value + num) % modulo;
    return Num(newValue, modulo);
}

inline Num Num::operator-(int num) {
    newValue = (this->value - num) % modulo;
    return Num(newValue, modulo);
}

inline Num Num::operator*(int num) {
    newValue = (this->value * num) % modulo;
    return Num(newValue, modulo);
}

inline Num &Num::operator+=(int num) {
    newValue = this->value;
    newValue = (newValue + num) % modulo;
    this->value = newValue;
    return *this;
}

inline Num &Num::operator-=(int num) {
    if (value < num) {
        value = (value - num + modulo) % modulo;
    } else {
        value = (value - num) % modulo;
    }
    return *this;
}

inline Num &Num::operator*=(int num) {
    newValue = this->value;
    newValue = (newValue * num) % modulo;
    this->value = newValue;
    return *this;
}
