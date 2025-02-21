
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouzi < mdouzi@student.1337.ma>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 07:19:59 by mdouzi            #+#    #+#             */
/*   Updated: 2024/01/24 05:11:05 by mdouzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP
#include <iostream>
template <typename T>
class Array{
    private:
        T* elements;
        size_t size;
    public:
        Array();
        Array(unsigned int size);
        Array(const Array &other);
        

        ~Array();
        unsigned int getSize() const;
        Array& operator=(const Array& other);
        T& operator[](unsigned int index);
};

#include "Array.tpp"

#endif
