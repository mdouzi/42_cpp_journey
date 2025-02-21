/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouzi < mdouzi@student.1337.ma>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 03:53:16 by mdouzi            #+#    #+#             */
/*   Updated: 2024/01/11 13:16:04 by mdouzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    try {
        // Creating bureaucrats
        Bureaucrat john("John", 50);
        Bureaucrat alice("Alice", 120);

        // Creating forms
        ShrubberyCreationForm shrubberyForm("Home");
        RobotomyRequestForm robotomyForm("Target");
        PresidentialPardonForm pardonForm("Criminal");

        // Displaying initial states
        std::cout << john << std::endl;
        std::cout << alice << std::endl;
        std::cout << shrubberyForm << std::endl;
        std::cout << robotomyForm << std::endl;
        std::cout << pardonForm << std::endl;

        // Attempting to sign and execute forms
        john.signForm(shrubberyForm);
        alice.signForm(shrubberyForm);
        john.executeForm(shrubberyForm);

        john.signForm(robotomyForm);
        alice.executeForm(robotomyForm);

        john.signForm(pardonForm);
        alice.executeForm(pardonForm);

        // Displaying final states
        std::cout << john << std::endl;
        std::cout << alice << std::endl;
        std::cout << shrubberyForm << std::endl;
        std::cout << robotomyForm << std::endl;
        std::cout << pardonForm << std::endl;

    } catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
