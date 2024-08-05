#pragma once
#include <iostream>
#include <memory>

template <typename T>
class WeakPtr;

template <typename T>
class SharedPtr {
    friend class WeakPtr<T>;

private:
    void cleanup() {
        if (--(*ref_count_) == 0) {
            delete ptr_;
            delete ref_count_;
        }
    }

    T* ptr_;
    int* ref_count_;

public:
    explicit SharedPtr(T* ptr = nullptr) : ptr_(ptr), ref_count_(new int(1)) {}

    // copy constructor
    SharedPtr(const SharedPtr& other) : ptr_(other.ptr_), ref_count_(other.ref_count_) {
        ++(*ref_count_);
    }

    // assignment operator
    SharedPtr& operator=(const SharedPtr& other) {
        if (this != &other) {
            cleanup();
            ptr_ = other.ptr_;
            ref_count_ = other.ref_count_;
            ++(*ref_count_);
        }
        return *this;
    }

    ~SharedPtr() {
        cleanup();
    }

    T* get() const { return ptr_; }
    T& operator*() const { return *ptr_; }
    T* operator->() const { return ptr_; }
};

template <typename T>
class WeakPtr {
private:
    T* ptr_;
    int* ref_count_;
    
public:
    WeakPtr() : ptr_(nullptr), ref_count_(nullptr) {}

    WeakPtr(const SharedPtr<T>& sharedPtr) : ptr_(sharedPtr.ptr_), ref_count_(sharedPtr.ref_count_) {}

    WeakPtr(const WeakPtr& other) : ptr_(other.ptr_), ref_count_(other.ref_count_) {}

    WeakPtr &operator=(const WeakPtr &other) {
        if (this != &other) {
            ptr_ = other.ptr_;
            ref_count_ = other.ref_count_;
        }
        return *this;
    }

    bool expired() const {
        return !ref_count_ || *ref_count_ == 0;
    }

    SharedPtr<T> lock() const {
        if (expired()) {
            return SharedPtr<T>(nullptr);
        }
        return SharedPtr<T>(ptr_);
    }
};
