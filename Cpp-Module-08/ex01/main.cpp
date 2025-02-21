/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouzi < mdouzi@student.1337.ma>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 09:42:07 by mdouzi            #+#    #+#             */
/*   Updated: 2024/04/05 00:29:37 by mdouzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <stdlib.h>

void _main2() {
    
    srand((unsigned)time(NULL));
    Span sp(10000);

    for(int i = 0; i < 10000; i++) {
        sp.addNumber(i);
    }
    std::cout << "Shortest span is " << sp.shortestSpan() << std::endl;
    std::cout << "Longest span is " << sp.longestSpan() << std::endl;
}



void _main1() {
    Span sp = Span(1);
    sp.addNumber(12);
    sp.shortestSpan();
}

void _main3() {
    Span sp = Span(10);
    sp.createNumbers(0, 9);
    std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
    std::cout << "Longest Span: " << sp.longestSpan() << std::endl;

}


int main()
{
    try {
        Span sp = Span(7);
        sp.addNumber(6);
        sp.addNumber(130);
        sp.addNumber(17);
        sp.addNumber(10);
        sp.addNumber(20);
        sp.addNumber(16);
        sp.addNumber(206);
        sp.shortestSpan();
        std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest Span: " << sp.longestSpan() << std::endl;

        _main2();
        _main3();
        // exception 
        _main1();
     } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    
    return 0;
}