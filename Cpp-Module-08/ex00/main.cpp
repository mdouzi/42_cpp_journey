/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouzi < mdouzi@student.1337.ma>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 03:34:34 by mdouzi            #+#    #+#             */
/*   Updated: 2024/02/08 02:48:17 by mdouzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <array>
#include "easyfind.hpp"

using namespace std;

int main()
{
    // creating an array
    array<int, 5> arr = {10, 11, 12, 12, 13};

    // creating an iterator for the array
    array<int, 5>::iterator it;

    // iterating through each element of the array using the iterator
    cout << "The array is: ";
    for (it = arr.begin(); it < arr.end(); it++)
    {
        cout << *it << " ";
    }

    try
    {
        easyfind(&arr, 11);
    }
    catch (const std::exception& e)
    {
        cerr << "Exception: " << e.what() << endl;
    }

    cout << endl;

    cout << "Size of the array is: " << arr.size() << endl;

    return 0;
}
