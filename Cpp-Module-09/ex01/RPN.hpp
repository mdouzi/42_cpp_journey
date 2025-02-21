/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouzi <mdouzi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 15:18:39 by mdouzi            #+#    #+#             */
/*   Updated: 2024/05/15 04:37:35 by mdouzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// RPN.hpp
#ifndef RPN_HPP
#define RPN_HPP

#include <string>

class RPN {
public:
    static int evaluate(const std::string& expression);
    
private:

    RPN& operator=(const RPN& src);
    static bool isOperator(char c);
    static int applyOperator(int a, int b, char op);
};

#endif // RPN_HPP
