/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouzi <mdouzi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 03:52:34 by mdouzi            #+#    #+#             */
/*   Updated: 2024/04/25 16:05:24 by mdouzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <limits>
#include <map>

#define DB_NAME "data.csv"


class BitcoinExchange
{
public:
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange &src);
    ~BitcoinExchange();
    BitcoinExchange &operator=(const BitcoinExchange &src);
    void output_values(const std::string &input_file_name);

private:
    std::map<std::string, double> exchangeRates;
    std::string errorMessage;
    void setErrorMessage(const std::string &str);
    std::string getErrorMessage(void) const;

    int loadExchangeRates();
    double calculateValue(const std::string &line);
    bool isValidDate(const std::string &dateStr);
    bool isValidInputLine(const std::string &line);
    bool isValidValue(const std::string &valueStr);
};

#endif