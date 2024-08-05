#pragma once

template<typename T>
class UniquePtr {
private:
    T *ptr; // Raw pointer to manage

public:
    // Constructor
    explicit UniquePtr(T *p = nullptr) noexcept : ptr(p) {}

    // Destructor
    ~UniquePtr() {
        delete ptr; // Delete the managed object
    }

    // Move constructor
    UniquePtr(UniquePtr &&other) noexcept : ptr(other.ptr) {
        other.ptr = nullptr; // Transfer ownership
    }

    // Move assignment operator
    UniquePtr &operator=(UniquePtr &&other) noexcept {
        if (this != &other) {
            delete ptr; // Release current resource
            ptr = other.ptr; // Transfer ownership
            other.ptr = nullptr; // Nullify the other pointer
        }
        return *this;
    }

    // Delete copy constructor and copy assignment operator to enforce unique ownership
    UniquePtr(const UniquePtr&) = delete;
    UniquePtr &operator=(const UniquePtr&) = delete;

    // Access the raw pointer
    T *get() const noexcept {
        return ptr;
    }

    // Dereference the raw pointer
    T &operator*() const noexcept {
        return *ptr;
    }

    // Arrow operator to access members of the managed object
    T *operator->() const noexcept {
        return ptr;
    }

    // Assign a new value to the managed object (Not typically a part of unique_ptr but included per request)
    UniquePtr &operator=(T *newPtr) noexcept {
        if (ptr != newPtr) {
            delete ptr; // Release the old resource
            ptr = newPtr; // Assign the new pointer
        }
        return *this;
    }

    // Release ownership of the managed object and return the raw pointer
    T *release() noexcept {
        T *oldPtr = ptr;
        ptr = nullptr; // Nullify the pointer
        return oldPtr; // Return the old pointer
    }

    // Reset the managed object to a new pointer or nullptr
    void reset(T *newPtr = nullptr) noexcept {
        if (ptr != newPtr) {
            delete ptr; // Release the old resource
            ptr = newPtr; // Assign the new pointer
        }
    }
};