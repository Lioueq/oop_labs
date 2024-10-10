#include "three.h"
#include <iostream>
#include <string>

Three::Three() : _size(0), _array{nullptr} {}

Three::Three(const size_t &n, unsigned char t) {
    _array = new unsigned char[n];
    for (size_t i = 0; i < n; ++i) {
        _array[i] = t;
    }
    _size = n;
}

Three::Three(const std::initializer_list <unsigned char> &t) {
    _array = new unsigned char[t.size()];
    size_t i = 0;
    for (auto &c: t) {
        _array[i++] = c;
    }
    _size = t.size();
}

Three::Three(const std::string &t) {
    _array = new unsigned char[size(t)];
    size_t i{0};
    for (auto &c: t) {
        _array[i++] = c;
    }
    _size = size(t);
}

Three::Three(const Three &other) {
    _size = other._size;
    _array = new unsigned char[_size];
    for (size_t i{0}; i < _size; ++i) _array[i] = other._array[i];
}

Three::Three(Three &&other) noexcept {
    _size = other._size;
    _array = other._array;
    other._size = 0;
    other._array = nullptr;
}

bool Three::isGreaterThan(const Three &other) const {
    if (_size > other._size) {
        return true;
    } else if (_size < other._size) {
        return false;
    }
    for (size_t i = _size; i-- > 0;) {
        unsigned char a = (_array[i] - '0');
        unsigned char b = (i < other._size) ? (other._array[i] - '0') : 0;
        if (a > b) {
            return true;
        } else if (a < b) {
            return false;
        }
    }
    return false;
}

bool Three::isLessThan(const Three &other) const {
    return other.isGreaterThan(*this);
} 

bool Three::isEqualTo(const Three &other) const {
    if (_size != other._size) {
        return false;
    }
    for (size_t i = 0; i < _size; ++i) {
        if (_array[i] != other._array[i]) {
            return false;
        }
    }
    return true;
}

Three Three::add(const Three &other) {
    size_t max_size = std::max(_size, other._size);
    unsigned char *result_array = new unsigned char[max_size + 1];
    size_t carry = 0;
    size_t i = 0;
    for (; i < max_size; ++i) {
        unsigned char a = (i < _size) ? _array[i] - '0' : 0;
        unsigned char b = (i < other._size) ? other._array[i] - '0' : 0;
        unsigned char sum = a + b + carry;
        if (sum >= 3) {
            carry = sum / 3;
            result_array[i] = (sum % 3) + '0';
        } else {
            carry = 0;
            result_array[i] = sum + '0';
        }
    }
    if (carry > 0) {
        result_array[i] = carry + '0';
        ++i;
    }
    Three result(i, '0');
    for (size_t j = 0; j < i; ++j) {
        result._array[j] = result_array[j];
    }
    delete[] result_array;
    return result;
}

Three Three::subtract(const Three &other) {
    if (this->isLessThan(other)) {
        throw std::invalid_argument("Result is negative. Subtraction not possible.");
    }
    size_t max_size = std::max(_size, other._size);
    unsigned char *result_array = new unsigned char[max_size];
    size_t borrow = 0;
    for (size_t i = 0; i < max_size; ++i) {
        unsigned char a = (i < _size) ? _array[i] - '0' : 0;
        unsigned char b = (i < other._size) ? other._array[i] - '0' : 0;
        if (a < b + borrow) {
            a += 3;
            borrow = 1;
        } else {
            borrow = 0;
        }
        result_array[i] = (a - b - borrow) + '0';
    }
    size_t result_size = max_size;
    while (result_size > 1 && result_array[result_size - 1] == '0') {
        --result_size;
    }
    Three result(result_size, '0');
    for (size_t j = 0; j < result_size; ++j) {
        result._array[j] = result_array[j];
    }
    delete[] result_array;
    return result;
}

std::ostream &Three::print(std::ostream &os){
    for (size_t i = _size; i > 0; --i)
        os << _array[i - 1];
    return os;
}

std::string Three::toString() {
    std::string s = "";
    for (int i = _size; i > 0; --i) {
        s += _array[i - 1];
    }
    return s;
}


Three::~Three() noexcept {
    if (_size > 0) {
        _size = 0;
        delete[] _array;
        _array = nullptr;
    }
}