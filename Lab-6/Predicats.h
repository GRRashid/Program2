#pragma once

template <typename T> bool none_of(T& start,const T& stop, bool (*predicate)(T& param)) {
    while (start != stop) {
        if (predicate(start))
            return false;
        start++;
    }
    return !predicate(start);
}

template <typename T> bool is_sorted(T* start,const T* stop, bool (*predicate)(T& first, T& second)) {
    while (start != stop) {
        if (!predicate(*start, *(start + 1)))
            return false;
        start++;
    }
     return true;
}

template <typename T> T* find_backward(const T& start, T& stop, bool (*predicate)(T& first)) {
    while (start != stop) {
        if (predicate(stop))
            return &stop;
        stop--;
    }
    if (predicate(stop)) {
        return &stop;
    }
    return nullptr;
}
