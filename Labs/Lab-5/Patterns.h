#pragma once

#include <string>

class Extention: public std::exception {
public:
    explicit Extention(std::string  error) : error_(std::move(error)) {};
    [[nodiscard]] std::string Error() const {
        return error_;
    };
private:
    std::string error_;
};


template <typename T>
class Stack {
public:
    Stack() = default;
    void Add(const T& obj) {
        if (capasity_ >= 99)
            throw Extention("overflow stack");
        arr[capasity_] = obj;
        capasity_++;
    };
    void Pop() {
        if (capasity_ == 0)
            throw Extention("Empty Stack");
        capasity_--;
        arr[capasity_] = (T)NULL;
    };
    T operator()() {
        return arr[capasity_ - 1];
    };
private:
    unsigned capasity_ = 0;
    T arr[100];
};

