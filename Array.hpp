#ifndef ARRAY_HEADER
#define ARRAY_HEADER


#include <iostream>
template <class T>
class Array {
private:
    T* arr;
    int size; // size is the total number of elements arr can hold
    int length; // length is current num of elements AND index of next item to be added

public:
    Array();
    Array(int size);
    Array(T arr[], int size);

    ~Array();

    int get_length() const { return length; }

    bool add(T data) {
        if (length == size) return false;
        arr[length++] = data;
        return true;
    }

    bool insert(T data, int index) {
        if (length == size || index < 0) return false;
        // assigning length to i will start at first empty cell
        for (int i = length; i > index; i--) { arr[i] = arr[i - 1]; }
        arr[index] = data;
        length++;
        return true;
    }

    T& del(int index) {
        if (length == 0 || index > size) return nullptr;
        T data = arr[index];
        for (int i = index; i < length; i++) { arr[i] = arr[i + 1]; }
        length--;
        return data;
    }

    void display() {
        for (int i = 0; i < length; i++) { std::cout << arr[i] << ' '; }
    }

    T& operator[](int index) { return arr[index]; }
    const T& operator[](int index) const { return arr[index]; }
};


template <class T>
Array<T>::Array() : arr(new T[10]), size(10), length(0) {}

template <class T>
Array<T>::Array(int size) : arr(new T[size]), size(size), length(0) {}

template <class T>
Array<T>::Array(T arr[], int size) : arr(new T[size]), size(size), length(length) {
    for (int i = 0; i < size; i++) this->arr[i] = arr[i];
}

template <class T>
Array<T>::~Array() {
    delete[] arr;
    arr = nullptr;
}


#endif
