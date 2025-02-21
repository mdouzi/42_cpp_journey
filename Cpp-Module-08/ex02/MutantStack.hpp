/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouzi < mdouzi@student.1337.ma>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 13:22:50 by mdouzi            #+#    #+#             */
/*   Updated: 2024/02/10 03:57:58 by mdouzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANSTACK_HPP
#define MUTANSTACK_HPP

#include <iostream>
#include <stack>

template <typename T>
class MutantStack: public std::stack<T>
{
public:
    MutantStack() : std::stack<T>() {}

    MutantStack(const MutantStack& src) : std::stack<T>(src) {}

    MutantStack& operator=(const MutantStack& src) {
        if (this != &src) {
            std::stack<T>::operator=(src);
        }
        return *this;
    }

    ~MutantStack() {
        std::cout << "MutantStack destructor been called" << std::endl;   
    }

    typedef typename std::stack<T>::container_type::iterator iterator;

    iterator begin() {
        return this->c.begin();
    }

    iterator end() {
        return this->c.end();
    }
};

#endif
