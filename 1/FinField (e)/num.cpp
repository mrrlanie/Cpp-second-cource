#include "num.h"

inline Num::Num(const Num &other) {
    this->modulo = 0;
    this->value = other.value;
}

inline Num::Num(int value, int modulo) {
    this->modulo = modulo;
    this->value = value % modulo;
}
