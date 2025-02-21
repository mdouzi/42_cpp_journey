/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouzi < mdouzi@student.1337.ma>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 03:22:36 by mdouzi            #+#    #+#             */
/*   Updated: 2024/02/14 07:28:02 by mdouzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <iostream>

template <typename T>
void easyfind(T* container, int value)
{
    typename T::iterator res = std::find(container->begin(), container->end(), value);

    if (res == container->end())
        throw std::out_of_range("Index value out of range");
    else
    {
        int pos = std::distance(container->begin(), res);
        std::cout << "found value == " << value << " at pos == " << pos << std::endl;
    }
}

#endif // EASYFIND_HPP
