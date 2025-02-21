/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouzi < mdouzi@student.1337.ma>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 09:42:04 by mdouzi            #+#    #+#             */
/*   Updated: 2024/04/05 00:08:12 by mdouzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int capacity) :N(capacity) {};
Span::Span(const Span& other) : N(other.N), numbers(other.numbers) {};

void Span::addNumber(int num) {
    if(numbers.size() >= N){
        throw std::out_of_range("connot add more numbers, span id full");    
    }
    numbers.push_back(num);
}

void Span::createNumbers(int start, int end) {
    if (end < start) {
        throw std::invalid_argument("end should be greater than start");
    }
    if (numbers.size() + (end - start) > N) {
        throw std::out_of_range("connot add more numbers, span id full");
    }
    for (int i = start; i <= end; i++) {
        numbers.push_back(i);
    }
}

int Span::shortestSpan(void) {
    checkSpanValidity();
    std::sort(numbers.begin(), numbers.end());
    int minSpan = INT16_MAX;
    for(size_t i = 1; i < numbers.size() ; i++) 
    {
        int span = numbers[i] - numbers[i - 1];
        minSpan = std::min(minSpan, span);
    }
    return minSpan;
    
}


void Span::checkSpanValidity(void) {
    if(numbers.size() < 2)
    {
        throw std::out_of_range("connot find span with lesss than two numbers.");
    }
}

int Span::longestSpan(void) {
    checkSpanValidity();
    return numbers.back() - numbers.front();
}

Span& Span::operator=(const Span& other) {
    if (this != &other) {
        N = other.N;
        numbers = other.numbers;
    }
    return *this;
}