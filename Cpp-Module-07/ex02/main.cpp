/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouzi < mdouzi@student.1337.ma>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 06:19:03 by mdouzi            #+#    #+#             */
/*   Updated: 2024/01/25 09:35:08 by mdouzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// main.cpp

#include <iostream>
#include "Array.hpp"

int main() {
   try {
        // Test default constructor
        Array<int> arr1;
        std::cout << "Size of arr1: " << arr1.getSize() << std::endl;

        // Test parameterized constructor
        Array<double> arr2(5);
        std::cout << "Size of arr2: " << arr2.getSize() << std::endl;

        // Test copy constructor and assignment operator
        Array<int> arr3 = arr1;
        Array<int> arr4;
        arr4 = arr1;

        // Test subscript operator
        arr2[2] = 3.14;
        std::cout <<"Element at index 2 of arr2: "<< arr2[20] << std::endl;

        // Trying to access out-of-bounds index
        // Uncommenting the next line should throw an exception
        std::cout << arr2[10] << std::endl;


    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}


