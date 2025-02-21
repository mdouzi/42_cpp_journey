/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouzi < mdouzi@student.1337.ma>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 03:15:32 by mdouzi            #+#    #+#             */
/*   Updated: 2024/01/18 03:17:33 by mdouzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data::Data(int _value) :value(_value) {
    std::cout << "Data constructor been called" << std::endl;
}

Data::~Data() {
    std::cout << "Data deconstructor been called" << std::endl;
}