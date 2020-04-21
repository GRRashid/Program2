#pragma once

template <typename T> bool none_of(T& start,const T& stop, bool (*predicate)(T param)) {
    T* i = &start;
    while (i != &stop) {
        if (predicate(*i))
            return false;
        i++;
    }
    return !predicate(stop);
}

template <typename T> bool is_sorted(T& start,const T& stop, bool (*predicate)(T first, T second)) {
    T* i = &start;
    while (i != &stop) {
        if (!predicate(*i, *(i + 1)))
            return false;
        i++;
    }
    return true;
}

template <typename T> T* find_backward(const T& start, T& stop, bool (*predicate)(T first)) {
    T* i = &stop;
    while (i != &start) {
        if (predicate(*i))
            return i;
        i--;
    }
    if (predicate(stop)) {
        return &stop;
    }
    return nullptr;
}
