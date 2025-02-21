/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouzi <mdouzi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 09:37:18 by mdouzi            #+#    #+#             */
/*   Updated: 2024/05/15 00:53:30 by mdouzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"


int main(int ac, char **av) {
    if(ac != 2)
    {
        std::cerr << "Error : no file" << std::endl;
        return(1);
    }
    try {
        
        BitcoinExchange exchange;
        exchange.output_values(av[1]);
    } catch (const std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}

