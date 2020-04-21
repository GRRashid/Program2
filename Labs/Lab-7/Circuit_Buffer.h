#include <utility>

#pragma once

class CircuitBufferException: std::exception {
public:
    CircuitBufferException(std::string  ex): ex_(std::move(ex)) {};

private:
    std::string ex_;
};

template <typename T>
class CircuitBuffer {
public:
    CircuitBuffer() = default;
    explicit CircuitBuffer(unsigned N) {
        capacity_ = N;
        array = new T[N];
    }
    void Resize(unsigned N) {
        if (N < size_)
            return;
        T* b = new T[N];
        for (int i = 0; i < size_; i++)
            b[i] = array[i];
        capacity_ = N, array = b;
    }

    [[nodiscard]] unsigned capacity() const {
        return capacity_;
    }
    [[nodiscard]] unsigned size() const {
        return size_;
    }

    bool AddStart(const T& t) {
        if (size_ >= capacity_)
            return false;
        T* b = new T[capacity_];
        b[0] = t;
        for (int i = 0; i < size_; i++)
            b[i + 1] = array[i];
        size_++;
        array = b;
        return true;
    }
    T EreaseStart() {
        if (size_ <= 0)
            throw CircuitBufferException("Buffer is empty");
        T* b = new T[capacity_];
        T t = array[0];
        for (int i = 0; i < size_ - 1; i++)
            b[i] = array[i + 1];
        size_--;
        array = b;
        return t;
    }

    bool AddEnd(const T& t) {
        if (size_ >= capacity_)
            return false;
        array[size_] = t;
        size_++;
        return true;
    }
    T EreaseEnd() {
        if (size_ <= 0)
            throw CircuitBufferException("Buffer is empty");
        size_--;
        return array[size_];
    }

    T operator[](unsigned N) {
        if (N > size_)
            throw CircuitBufferException("Cann't use this cell");
        return array[N];
    }

    T* begin() const {
        return &array[0];
    }
    T* end() const {
        return &array[size_];
    }

    bool operator<(const CircuitBuffer<T>& second) const {
        if (this->size() < second.size())
            return true;
        if (this->size() > second.size())
            return false;
        for (int i = 0; i < this->size(); i++) {
            if (this[i] >= second[i])
                return false;
        }
        return true;
    }
    bool operator>(const CircuitBuffer<T>& second) const {
        if (this->size() > second.size())
            return true;
        if (this->size() < second.size())
            return false;
        for (int i = 0; i < this->size(); i++) {
            if (this[i] <= second[i])
                return false;
        }
        return true;
    }
    bool operator==(const CircuitBuffer<T>& second) const {
        if (this->size() != second.size())
            return false;
        for (int i = 0; i < this->size(); i++) {
            if (this[i] != second[i])
                return false;
        }
        return true;
    }
    bool operator!=(const CircuitBuffer<T>& second) const {
        return !(this==second);
    }
    bool operator>=(const CircuitBuffer<T>& second) const {
        return !(this<second);
    }
    bool operator<=(const CircuitBuffer<T>& second) const {
        return !(this>second);
    }

    ~CircuitBuffer() {
        delete[] array;
    }

private:
    unsigned capacity_ = 10, size_ = 0;
    T* array = new T[10];
};