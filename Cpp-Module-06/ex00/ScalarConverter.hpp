/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouzi < mdouzi@student.1337.ma>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:27:16 by mdouzi            #+#    #+#             */
/*   Updated: 2024/01/16 17:33:19 by mdouzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP
#include <iostream>
#include <fstream>

class  ScalarConverter {

  private:
    ScalarConverter();
  public:
    ~ScalarConverter();   
    static void convert(std::string str);
};


#endif
