/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouzi < mdouzi@student.1337.ma>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 15:23:53 by mdouzi            #+#    #+#             */
/*   Updated: 2024/02/25 14:33:34 by mdouzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


// main.cpp
#include "RPN.hpp"
#include <iostream>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <RPN_expression>" << std::endl;
        return 1;
    }

    std::string expression = argv[1];
    int result = RPN::evaluate(expression);
    if (result != 0) {
        std::cout << result << std::endl;
        return 0;
    } else {
        return 1;
    }
}
