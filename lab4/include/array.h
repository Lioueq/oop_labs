#pragma once
#include <iostream>
#include <concepts>
#include <memory>
#include <cassert>

template <class T>
concept Arrayable = std::is_default_constructible<T>::value;

template <Arrayable T>
class Array {
public:
    Array() : _size(0), _capacity(1), _array(std::make_shared<T[]>(1)) {}

    Array(const std::initializer_list<T>& t) : _size(t.size()), _capacity(t.size()), _array(std::make_shared<T[]>(t.size())) {
        size_t i{0};
        for (const auto& c : t)
            _array[i++] = c;
    }

    Array(const Array& other) : _size(other._size), _capacity(other._capacity), _array(std::make_shared<T[]>(other._capacity)) {
        for (size_t i{0}; i < _size; ++i)
            _array[i] = other._array[i];
    }

    Array(Array&& other) noexcept : _size(other._size), _capacity(other._capacity), _array(std::move(other._array)) {
        other._size = 0;
        other._capacity = 0;
    }

    T& operator[](size_t index) {
        assert(index < _size);
        return _array[index];
    }

    size_t size() const {
        return _size;
    }

    void add(const T& value) {
        if (_size == _capacity) {
            resize(_capacity * 2);
        }
        _array[_size++] = value;
    }

    void remove(size_t index) {
        assert(index < _size);
        for (size_t i = index; i < _size - 1; ++i) {
            _array[i] = std::move(_array[i + 1]);
        }
        --_size;
    }

    ~Array() noexcept {}

private:
    void resize(size_t new_capacity) {
        std::shared_ptr<T[]> new_array = std::make_shared<T[]>(new_capacity);
        for (size_t i = 0; i < _size; ++i) {
            new_array[i] = _array[i];
        }
        _array = new_array;
        _capacity = new_capacity;
    }

    size_t _size;
    size_t _capacity;
    std::shared_ptr<T[]> _array;
};