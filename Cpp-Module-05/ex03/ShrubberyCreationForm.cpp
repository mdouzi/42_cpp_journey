/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouzi < mdouzi@student.1337.ma>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 15:08:43 by mdouzi            #+#    #+#             */
/*   Updated: 2024/01/13 12:19:36 by mdouzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("ShrubberyCreationForm", 145, 137), _target("default") {}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &other) : AForm(other), _target(other._target) {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target) : AForm("ShrubberyCreationForm", 145, 137), _target(target) {}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
    if (this->getIsSigned()) 
    {
        if (executor.getGrade() > this->getExGrade())
            throw AForm::GradeTooHighException();
        else {
            std::string filename = this->_target + "_shrubbery";
            std::ofstream outputFile(filename.c_str());

            if (outputFile.is_open()) {
                outputFile << "   *\n";
                outputFile << "  ***\n";
                outputFile << " *****\n";
                outputFile << "*******\n";

                outputFile.close();

                std::cout << "Shrubbery created for " << this->_target << std::endl;
            } else {
                std::cerr << "Error: Unable to open file for shrubbery creation." << std::endl;
            }
        }
    } else
        throw AForm::GradeTooLowException();
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
    if (this != &other)
    {
        this->_target = other._target;
    }
    return *this;
}

std::ostream& operator<<(std::ostream& os, const ShrubberyCreationForm& form) {
    os << "AForm" << form.getName() << ", is Signed : " << form.getIsSigned() << ", sign grade :" << form.getSignedGrade() <<  ", ex Grade : " << form.getExGrade() << std::endl;
    return os;
}
