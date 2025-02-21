/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouzi <mdouzi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 03:52:38 by mdouzi            #+#    #+#             */
/*   Updated: 2024/05/15 04:52:54 by mdouzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"


BitcoinExchange::BitcoinExchange():errorMessage("") {
    if(loadExchangeRates() == -1) {
        throw std::runtime_error("Error: could not open data file");
    }
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &src) {
    exchangeRates = src.exchangeRates;
}

BitcoinExchange::~BitcoinExchange() {
    
}

void BitcoinExchange::setErrorMessage(const std::string &str)
{
    this->errorMessage = str;
}

std::string BitcoinExchange::getErrorMessage(void) const
{
    return(this->errorMessage);
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &src) {
    if(this != &src){
        exchangeRates = src.exchangeRates;
    }
    return(*this);
}

int BitcoinExchange::loadExchangeRates() {
    std::fstream datafile;
    datafile.open(DB_NAME);

    if(!datafile.is_open()) {
        return (-1);
    }

    std::string line;
    std::getline(datafile, line); // header file ++
    
    while(std::getline(datafile, line)) {
        std::istringstream iss(line);
        std::string date;
        std::string value_str;
        std::getline(iss, date, ',');
        std::getline(iss, value_str);
        exchangeRates[date] = std::stod(value_str.c_str());
    }
    datafile.close();
    return(0);
}

void BitcoinExchange::output_values(const std::string &inputFileName) {
    std::ifstream inputFile(inputFileName);

    if (!inputFile.is_open()) {
        throw std::runtime_error("Error: could not open input file");
    }

    // Check if the input file is empty
    inputFile.seekg(0, std::ios::end);
    if (inputFile.tellg() == 0) {
        throw std::runtime_error("Error: input file is empty");
    }
    inputFile.seekg(0, std::ios::beg);

    std::string line;
    while (std::getline(inputFile, line)) {
        if (!line.empty() && line.find_first_of("0123456789,.") != std::string::npos) {
            if (isValidInputLine(line)) {
                double value = calculateValue(line);
                if (value == -1) {
                    std::cout << "Error: Date out of range." << std::endl;
                } else {
                    std::istringstream ss(line);
                    std::string date, valueStr;
                    std::getline(ss, date, '|');
                    std::getline(ss, valueStr, '|');
                    std::cout << date << " => " << valueStr << " = " << value << std::endl;
                }
            } else {
                std::cout << getErrorMessage() << std::endl;
            }
        }
    }
}


double BitcoinExchange::calculateValue(const std::string &line) {
    std::istringstream ss(line);
    std::string date;
    std::getline(ss, date, '|');
    std::string valueStr;
    std::getline(ss, valueStr, '|');
    
    double value = std::stod(valueStr);


    std::map<std::string, double>::iterator it; 

    // Find the closest date in the map
    it = exchangeRates.lower_bound(date);
    
    if (it == exchangeRates.end()) {
        // If the date is after the last date in the map, use the last date
        --it;
    } else if (it != exchangeRates.begin() && it->first != date) {
        // If the exact date is not found, use the lower date
        std::map<std::string, double>::iterator prev = it;
        --prev;
        it = prev;
    }
    return  value * it->second;
}




// input line Error check 

bool BitcoinExchange::isValidInputLine(const std::string &line) {
    std::istringstream iss(line);
    std::string dateStr;
    std::getline(iss, dateStr, '|');
    if (!isValidDate(dateStr)) {
        return false; 
    }
    std::string valueStr;
    std::getline(iss, valueStr, '|');
    return isValidValue(valueStr);
}

// check Date format
bool BitcoinExchange::isValidDate(const std::string &dateStr) {
    if (dateStr.size() < 10)
    {
        setErrorMessage("Error: date format is not valid");
        return false;
    }
    if (dateStr[4] != '-' || dateStr[7] != '-')
    {
        setErrorMessage("Error: date format is not valid");
        return false;
    }

    for (int i = 0; i < 10; ++i) {
        if (i == 4 || i == 7)
            continue; // Skip '-'
        if (!isdigit(dateStr[i]))
        {
           setErrorMessage("Error: date format is not valid");
            return false;
        }
    }
    return true;
}

// check Value format
bool BitcoinExchange::isValidValue(const std::string &valueStr) {
    try{
      double value = std::stod(valueStr);
      if(value < 0)
      {
        setErrorMessage("Error: not a positive number");
        return(false); 
      }
      else if(value > 1000)
      {
        setErrorMessage("Error: not a valid value");
        return(false);
      }
      else
        return(true);
    } catch(std::invalid_argument &s) {
        setErrorMessage("Error: value is not a digit");
        return false;
    }
}

// end (input line Error check)


