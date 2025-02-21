/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouzi < mdouzi@student.1337.ma>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 03:08:25 by mdouzi            #+#    #+#             */
/*   Updated: 2024/01/21 04:43:41 by mdouzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "Data.hpp"

int main() {
    Data dataObject(42);

    // Use serialize on the address of the Data object
    uintptr_t serializedPtr = Serializer::serialize(&dataObject);

    Data* deserializedPtr = Serializer::deserialize(serializedPtr);

    if (deserializedPtr == &dataObject) {
        std::cout << "Serialization and deserialization successful!" << std::endl;
    } else {
        std::cout << "Serialization and deserialization failed!" << std::endl;
    }
    return 0;
}