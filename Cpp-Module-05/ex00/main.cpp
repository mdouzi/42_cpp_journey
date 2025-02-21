/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouzi < mdouzi@student.1337.ma>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 03:53:16 by mdouzi            #+#    #+#             */
/*   Updated: 2024/01/11 11:16:28 by mdouzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>


int main() {
    try {
        Bureaucrat bureaucrat("John Doe", 3);
        std::cout << bureaucrat << std::endl;
        bureaucrat.gradeUp();
        std::cout << "After grading up: " << bureaucrat << std::endl;
        bureaucrat.gradeDown();
        std::cout << "After grading down: " << bureaucrat << std::endl;
    } catch (const Bureaucrat::GradeTooHighException& e) {
        std::cerr << "Error creating or modifying bureaucrat: " << e.what() << std::endl;
    } catch (const Bureaucrat::GradeTooLowException& e) {
        std::cerr << "Error creating or modifying bureaucrat: " << e.what() << std::endl;
    }

    return 0;
}


