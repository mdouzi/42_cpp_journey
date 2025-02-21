/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouzi < mdouzi@student.1337.ma>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 09:42:01 by mdouzi            #+#    #+#             */
/*   Updated: 2024/04/05 00:07:42 by mdouzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

class Span {
    public:
        Span(unsigned int capacity);
        Span(const Span &other);
        void addNumber(int num);
        void createNumbers(int start, int end);
        int shortestSpan();
        int longestSpan(void);
        Span &operator=(const Span &other);
    private:
        void checkSpanValidity(void);
        unsigned int N;
        std::vector<int> numbers;
};

#endif