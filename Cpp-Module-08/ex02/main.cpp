/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouzi < mdouzi@student.1337.ma>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 05:06:52 by mdouzi            #+#    #+#             */
/*   Updated: 2024/02/16 09:43:42 by mdouzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

int main() {
    MutantStack<int> stack;

    // Push some elements onto the stack

    srand((unsigned) time(NULL));
    for (int i = 1; i < 100; ++i) {
        stack.push(rand() % 100 );
    }

    // Iterate over the stack using iterators
    std::cout << "Stack elements: ";
    MutantStack<int>::iterator it = stack.begin();
    MutantStack<int>::iterator itend = stack.end();

    
    for (; it != itend; ++it) {
        std::cout << *it << std::endl;
    }
    return 0;
}
