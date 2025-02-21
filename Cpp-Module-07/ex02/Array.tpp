/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouzi < mdouzi@student.1337.ma>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 06:16:54 by mdouzi            #+#    #+#             */
/*   Updated: 2024/02/04 12:35:49 by mdouzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_TPP
#define ARRAY_TPP
#include <iostream>
#include "Array.hpp"

// Array.tpp

template <typename T>
Array<T>::Array() : elements(NULL), size(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : size(n) 
{
    elements = new T[size](); 
}

template <typename T>
Array<T>::Array(const Array& other) : size(other.size) 
{
    elements = new T[size];
    for (unsigned int i = 0; i < size; ++i) {
        elements[i] = other.elements[i];
    }
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& other) 
{
    if (this != &other) {
        delete[] elements;
        size = other.size;
        elements = new T[size];
        for (unsigned int i = 0; i < size; ++i) {
            elements[i] = other.elements[i];
        }
    }
    return *this;
}

template <typename T>
Array<T>::~Array() 
{
    delete[] elements;
}

template <typename T>
T& Array<T>::operator[](unsigned int index) 
{
    if (index >= size) {
        throw std::out_of_range("Index out of bounds");
    }
    return elements[index];
}

template <typename T>
unsigned int Array<T>::getSize() const 
{
    return size;
}



#endif // ARRAY_TPP
