#pragma once

#include <iostream>

template<typename T>
class SharedPointer {
private:
    T *ptr;
    size_t *counts;

    void release() {
        if (ptr && --(*counts) == 0) {
            delete ptr;
            delete counts;
        }
    }

public:
    // Constructor
    explicit SharedPointer(T *ptr = nullptr)
        : ptr(ptr), counts(new size_t(ptr ? 1 : 0)) {}

    // Copy Constructor
    SharedPointer(const SharedPointer<T> &other)
        : ptr(other.ptr), counts(other.counts) {
        if (ptr) {
            ++(*counts);
        }
    }

    // Move Constructor
    SharedPointer(SharedPointer<T> &&other) noexcept
        : ptr(other.ptr), counts(other.counts) {
        other.ptr = nullptr;
        other.counts = nullptr;
    }

    // Copy Assignment
    SharedPointer<T> &operator=(const SharedPointer<T> &other) {
        if (this != &other) {
            release();
            ptr = other.ptr;
            counts = other.counts;
            if (ptr) {
                ++(*counts);
            }
        }
        return *this;
    }

    // Move Assignment
    SharedPointer<T> &operator=(SharedPointer<T>&& other) noexcept {
        if (this != &other) {
            release();
            ptr = other.ptr;
            counts = other.counts;
            other.ptr = nullptr;
            other.counts = nullptr;
        }
        return *this;
    }

    // Destructor
    ~SharedPointer() {
        release();
    }

    // Overload dereference operator
    T &operator*() const {
        return *ptr;
    }

    // Overload arrow operator
    T *operator->() const {
        return ptr;
    }

    // Get the raw pointer
    T *get() const {
        return ptr;
    }

    // Get the reference count
    size_t use_count() const {
        return ptr ? *counts : 0;
    }
};
