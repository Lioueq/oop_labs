#pragma once
#include "memory_resource.h"
#include "iterator.h"
#include <memory_resource>
#include <memory>

template<typename T>
struct Node {
    T data;
    Node* next;
    Node* prev;
};

template<typename T>
class List {
public:
    using allocator_type = std::pmr::polymorphic_allocator<Node<T>>;
    using iterator = ListIterator<Node<T>>;

    List(allocator_type alloc = {}) : alloc_(alloc), head_(nullptr), tail_(nullptr) {}

    ~List() {
        clear();
    }

    void push_back(const T& value) {
        Node<T>* node = alloc_.allocate(1);
        alloc_.construct(node, Node<T>{value, nullptr, tail_});
        if (tail_) {
            tail_->next = node;
        } 
        else {
            head_ = node;
        }
        tail_ = node;
    }

    void push_front(const T& value) {
        Node<T>* node = alloc_.allocate(1);
        alloc_.construct(node, Node<T>{value, head_, nullptr});
        if (head_) {
            head_->prev = node;
        } 
        else {
            tail_ = node;
        }
        head_ = node;
    }

    void pop_back() {
        if (tail_) {
            Node<T>* node = tail_;
            tail_ = tail_->prev;
            if (tail_) {
                tail_->next = nullptr;
            } else {
                head_ = nullptr;
            }
            std::allocator_traits<allocator_type>::destroy(alloc_, node);
            alloc_.deallocate(node, 1);
        }
    }

    void pop_front() {
        if (head_) {
            Node<T>* node = head_;
            head_ = head_->next;
            if (head_) {
                head_->prev = nullptr;
            } else {
                tail_ = nullptr;
            }
            std::allocator_traits<allocator_type>::destroy(alloc_, node);
            alloc_.deallocate(node, 1);
        }
    }

    void clear() {
        Node<T>* current = head_;
        while (current) {
            Node<T>* next = current->next;
            std::allocator_traits<allocator_type>::destroy(alloc_, current);
            alloc_.deallocate(current, 1);
            current = next;
        }
        head_ = tail_ = nullptr;
    }

    iterator begin() { return iterator(head_); }
    iterator end() { return iterator(nullptr); }

private:
    allocator_type alloc_;
    Node<T>* head_;
    Node<T>* tail_;
};