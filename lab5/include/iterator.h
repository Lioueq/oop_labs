#pragma once
#include <iterator>

template<typename T>
class ListIterator {
public:
    using iterator_category = std::forward_iterator_tag;
    using value_type = T;
    using difference_type = std::ptrdiff_t;
    using pointer = T*;
    using reference = T&;

    ListIterator(pointer ptr) : ptr_(ptr) {}

    reference operator*() const { return *ptr_; }
    pointer operator->() { return ptr_; }

    ListIterator& operator++() {
        ptr_ = ptr_->next;
        return *this;
    }

    ListIterator operator++(int) {
        ListIterator tmp = *this;
        ++(*this);
        return tmp;
    }

    friend bool operator==(const ListIterator& a, const ListIterator& b) { return a.ptr_ == b.ptr_; }
    friend bool operator!=(const ListIterator& a, const ListIterator& b) { return a.ptr_ != b.ptr_; }

private:
    pointer ptr_;
};