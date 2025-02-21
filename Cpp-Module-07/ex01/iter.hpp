/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouzi < mdouzi@student.1337.ma>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 04:23:37 by mdouzi            #+#    #+#             */
/*   Updated: 2024/01/23 05:03:24 by mdouzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP
#include <iostream>

template <typename T, typename Func>

void iter(T* array, int len, Func func) 
{
    for(int i = 0; i < len ; i++)
    {
        func(array[i]);
    }
}

template <typename T>
void printElement(T& A)
{
    std::cout << A << std::endl;
}

#endif