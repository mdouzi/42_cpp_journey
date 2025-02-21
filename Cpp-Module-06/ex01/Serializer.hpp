/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouzi < mdouzi@student.1337.ma>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 03:43:57 by mdouzi            #+#    #+#             */
/*   Updated: 2024/01/18 03:18:23 by mdouzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP
#include <iostream>
#include <cstdint>
#include "Data.hpp"
#include <aio.h>

class Serializer{
    public:
       static uintptr_t serialize(Data* ptr);
       static Data* deserialize(uintptr_t rw);
};

#endif
