/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouzi < mdouzi@student.1337.ma>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 04:39:19 by mdouzi            #+#    #+#             */
/*   Updated: 2024/02/04 12:09:54 by mdouzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>

// int main() {
//     // Test with an integer array
//     int intArray[] = {1, 2, 3, 4, 5};
//     size_t intArrayLength = sizeof(intArray) / sizeof(intArray[0]);

//     std::cout << "Iterating over intArray: ";
//     iter(intArray, intArrayLength, printElement<int>);
//     std::cout << std::endl;

//     // Test with a double array
//     double doubleArray[] = {1.1, 2.2, 3.3, 4.4, 5.5};
//     size_t doubleArrayLength = sizeof(doubleArray) / sizeof(doubleArray[0]);

//     std::cout << "Iterating over doubleArray: ";
//     iter(doubleArray, doubleArrayLength, printElement<double>);
//     std::cout << std::endl;

//     // Test with a character array
//     char charArray[] = {'a', 'b', 'c', 'd', 'e'};
//     size_t charArrayLength = sizeof(charArray) / sizeof(charArray[0]);

//     std::cout << "Iterating over charArray: ";
//     iter(charArray, charArrayLength, printElement<char>);
//     std::cout << std::endl;

//     return 0;
// }


class Awesome
{
  public:
    Awesome( void ) : _n( 42 ) { return; }
    int get( void ) const { return this->_n; }
  private:
    int _n;
};

std::ostream & operator<<( std::ostream & o, Awesome const & rhs )
{
  o << rhs.get();
  return o;
}

template< typename T >
void print( T& x )
{
  std::cout << x << std::endl;
  return;
}

int main() {
  int tab[] = { 0, 1, 2, 3, 4 };
  Awesome tab2[5];

  iter( tab, 5, print<const int> );
  iter( tab2, 5, print<Awesome> );

  return 0;
}
