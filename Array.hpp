#ifndef ARRAY_HEADER
#define ARRAY_HEADER


#include <iostream>
#include <stdexcept>
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
    int get_length() const;
    void add(T data);
    void insert(T data, int index);
    T* del(int index);
    T* lshift();
    void lrotate(int pos = 1);
    void reverse();
    void display();
    T& operator[](int index);
    const T& operator[](int index) const;
};


// constructors
template <class T>
Array<T>::Array() : arr(new T[10]), size(10), length(0) {}

template <class T>
Array<T>::Array(int size) : arr(new T[size]), size(size), length(0) {
    if (size <= 0) throw std::logic_error("Invalid size");
}

template <class T>
Array<T>::Array(T arr[], int size) : arr(new T[size]), size(size), length(size) {
    if (size <= 0) throw std::logic_error("Invalid size");
    for (int i = 0; i < size; i++) this->arr[i] = arr[i];
}


// destructor
template <class T>
Array<T>::~Array() {
    delete[] arr;
    arr = nullptr;
}


// insertion methods
template <class T>
void Array<T>::add(T data) {
    if (length == size) throw std::length_error("Array is full");
    arr[length++] = data;
}

template <class T>
void Array<T>::insert(T data, int index) {
    if (length == size) throw std::length_error("Array is full");
    if (index < 0 || index >= size) throw std::out_of_range("Index out of bounds");
    // assigning length to i will start at first empty cell
    for (int i = length; i > index; i--) { arr[i] = arr[i - 1]; }
    arr[index] = data;
    length++;
}


// removal methods
template <class T>
T* Array<T>::del(int index) {
    if (length == 0) throw std::length_error("Array is empty");
    if (index < 0 || index >= length) throw std::out_of_range("Index out of bounds");
    T* data = new T(arr[index]);
    for (int i = index; i < length; i++) { arr[i] = arr[i + 1]; }
    length--;
    return data;
}

template <class T>
T* Array<T>::lshift() {
    if (length == 0) throw std::length_error("Array is empty");
    T* data = new T(arr[0]);
    for (int i = 0; i < length; i++) {
        arr[i] = arr[i + 1];
    }
    length--;
    return data;
}


// element shifters
template <class T>
void Array<T>::reverse() {
    for (int i = 0, j = length - 1; i < length; i++, j--) {
        T& temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

template <class T>
void Array<T>::lrotate(int pos) {
    if (pos <= 0) throw std::logic_error("Invalid rotation");
    for (int i = 0; i < size; i++) {
        arr[i] = arr[i - pos >= 0 ? i - pos - 1 : size + i - pos];
    }
}

// getters
template <class T>
int Array<T>::get_length() const { return length; }

template <class T>
T& Array<T>::operator[](int index) {
    if ((index * -1) > length || index >= length) throw std::out_of_range("Index out of bounds");
    if (index < 0 && index * -1 <= length) return arr[length + index];
    return arr[index];
}

template <class T>
const T& Array<T>::operator[](int index) const {
    if ((index * -1) > length || index >= length) throw std::out_of_range("Index out of bounds");
    if (index < 0 && index * -1 <= length) return arr[(index * -1) - 1];
    return arr[index];
}


// print
template <class T>
void Array<T>::display() {
    for (int i = 0; i < length; i++) { std::cout << arr[i] << ' '; }
}

#endif
