/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   myarray.hpp
 * Author: Malinka
 *
 * Created on 6. November 2016, 12:11
 */

#ifndef MYARRAY_HPP
#define MYARRAY_HPP

#include <iostream>
#include <initializer_list>
#include <stdexcept>

template< class T, int N > class myArray {
public:
    myArray();
    explicit myArray(T);
    myArray(const myArray&);
    myArray(std::initializer_list<T>);
    myArray& operator=(const myArray&);
    T& operator[](int n);
    const T& operator[](int n) const;
    T& at(int n);
    T* dataPtr(int n);
    int size() const;
    void fill(myArray<T, N>& a, const T& val);
    void printAll() const;

private:
    T elem[N];
};

template <class T, int N>
myArray<T,N>::myArray() : myArray{ T{} } {

}
template <class T, int N>
myArray<T,N>::myArray(T t){
    for(size_t i{}; i<N; ++i) elem[i] = t;
}
template <class T, int N>
myArray<T,N>& myArray<T,N>::operator=( const myArray<T,N>& r){
    for(size_t i{}; i<N; ++i) elem[i] = r.elem[i];
    return *this;
}

template <class T, int N>
myArray<T,N>::myArray(const myArray& r){
    *this = r;
}

template <class T, int N>
myArray<T,N>::myArray(std::initializer_list<T> in){
    std::copy(in.begin(), in.end(), elem);
}
template <class T, int N>
T& myArray<T,N>::operator[](int n) {
    return elem[n];
}

template <class T, int N>
T& myArray<T,N>::at(int n) {
    if (n < 0 || N <= n) throw std::out_of_range{"bad index"};
    return elem[n];
}

template <class T, int N>
T* myArray<T,N>::dataPtr(int n) {
    return &(elem[n]);
}

template <class T, int N>
int myArray<T,N>::size() const {
    return N;
}

template <class T, int N>
void myArray<T,N>::fill(myArray<T, N>& a, const T& val) {
    for (size_t i{}; i < N; ++i) a[i] = val;
}

template <class T, int N>
void myArray<T,N>::printAll() const{
    int b = 0;
    for(size_t i{}; b<i;++i) std::cout << elem[b] << std::endl;
}

#endif /* MYARRAY_HPP */

