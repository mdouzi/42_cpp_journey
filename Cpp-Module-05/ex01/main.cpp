/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouzi < mdouzi@student.1337.ma>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 03:53:16 by mdouzi            #+#    #+#             */
/*   Updated: 2024/01/11 11:35:21 by mdouzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    try {
        // Creating bureaucrats
        Bureaucrat john("John", 50);
        Bureaucrat alice("Alice", 120);

        // Creating forms
        Form vacationForm("Vacation Request", 30, 70);
        Form expenseForm("Expense Report", 80, 120);

        // Displaying initial states
        std::cout << john << std::endl;
        std::cout << alice << std::endl;
        std::cout << vacationForm << std::endl;
        std::cout << expenseForm << std::endl;

        // Attempting to sign forms
        john.signForm(vacationForm);
        alice.signForm(vacationForm); // Should throw GradeTooLowException

        john.signForm(expenseForm);   // Should throw GradeTooLowException
        alice.signForm(expenseForm);

        // Displaying final states
        std::cout << john << std::endl;
        std::cout << alice << std::endl;
        std::cout << vacationForm << std::endl;
        std::cout << expenseForm << std::endl;

    } catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
