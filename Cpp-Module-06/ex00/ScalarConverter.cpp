/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouzi < mdouzi@student.1337.ma>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 15:49:14 by mdouzi            #+#    #+#             */
/*   Updated: 2024/01/21 03:35:10 by mdouzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>
#include <sstream>
#include <iomanip>
#include <limits.h>
#include <limits>
#include <cfloat>

ScalarConverter::ScalarConverter()
{
    std::cout << "default constructor called" << std::endl;
}

ScalarConverter::~ScalarConverter()
{
    std::cout << "destructor called" << std::endl;
}

int is_digit(const std::string& s, double& holder) {
    
    std::istringstream num(s);
    num >> holder;

    if (!num.fail() && num.eof()) {
        return 1;
    }

    return 0;
}


void print_error(bool inf, std::string str)
{
    
    std::cout << "char: " << str << std::endl;
    std::cout << "int: " << str << std::endl;
    std::cout << "float: " << str << std::endl;
    if (inf)
        str = "inf";
    std::cout << "double: " << str << std::endl;
}

void print_char(double nbr)
{
    char charvar = static_cast<char>(nbr);

    if (nbr >= 0 && nbr < 128)
    {
      if(std::isprint(charvar))
          std::cout << "char: " << charvar << std::endl;
      else 
          std::cout << "char: Non displayable" << std::endl;
    }
    else 
    {
        std::cout << "char: impossible" << std::endl;
    }
}

void print_int(double nbr)
{
    int intvar = static_cast<int>(nbr);
    
    if (nbr <= INT_MAX && nbr >= INT_MIN)
        std::cout << "int: " << intvar << std::endl;
    else
    {
        std::cout << "int: impossible" << std::endl;
    }
}

int calculate_precision(int len, double nbr)
{
    int holder = static_cast<long>(nbr);
    int i = 0;
    while (holder != 0)
    {
        holder = holder / 10; 
        i++;
    }
    return (len - i); 
}

void print_float(double nbr, int len, bool with_dot)
{
    float floatvar = static_cast<float>(nbr);

    if (nbr > FLT_MAX) 
        std::cout << "float: inff" << std::endl;
    else if (nbr < -FLT_MAX)
        std::cout << "float: -inff" << std::endl;
    else if (!with_dot)
        std::cout << "float: " << std::fixed << std::setprecision(1) << floatvar << "f" << std::endl;
    else
        std::cout << "float: " << std::fixed << std::setprecision(calculate_precision(len, nbr)) << floatvar << "f" << std::endl;
}

void print_double(double nbr, int len, bool with_dot)
{    
    if (!with_dot && nbr == nbr)
        std::cout << "double: " << std::fixed << std::setprecision(1) << nbr << std::endl;
    else
        std::cout << "double: " << std::fixed << std::setprecision(calculate_precision(len, nbr)) << nbr << std::endl;
}

void print_result(double nbr, std::string str)
{ 
    bool with_dot = str.find(".") != std::string::npos;
    print_char(nbr);
    print_int(nbr); 
    print_float(nbr, str.length(), with_dot);
    print_double(nbr, str.length(), with_dot);
}

void ScalarConverter::convert(std::string str)
{
    bool inf = false;
    double holder;
    if (!is_digit(str, holder))
    {
        if (holder == std::numeric_limits<double>::infinity())
            inf = true;
        print_error(inf, "impossible"); 
    }
    else
    {
        print_result(holder, str); 
    }
}

