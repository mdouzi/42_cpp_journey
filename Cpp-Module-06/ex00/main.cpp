/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouzi < mdouzi@student.1337.ma>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 16:26:29 by mdouzi            #+#    #+#             */
/*   Updated: 2024/01/20 19:51:22 by mdouzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>

int main(int argc, char **argv)
{
  if(argc == 2)
  {
    ScalarConverter::convert(argv[1]);
    return(0);
  }
  else 
  {
    std::cerr << "error in arg" << std::endl;
    return(1);
  }
}
