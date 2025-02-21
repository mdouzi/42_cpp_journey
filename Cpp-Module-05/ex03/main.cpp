/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouzi < mdouzi@student.1337.ma>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 03:53:16 by mdouzi            #+#    #+#             */
/*   Updated: 2024/01/12 11:46:36 by mdouzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include "Intern.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main() {
    Intern intern;

    // Test creating specific forms
    AForm* presidentialPardon = intern.createPresidentialPardonForm("John Doe");
    AForm* robotomyRequest = intern.createRobotomyRequestForm("Jane Doe");
    AForm* shrubberyCreation = intern.createShrubberyCreationForm("Home");

    // Test creating forms using makeForm
    AForm* customForm1 = intern.makeForm("ShrubberyCreationForm", "Garden");
    AForm* customForm2 = intern.makeForm("RobotomyRequestForm", "Lab");
    AForm* customForm3 = intern.makeForm("PresidentialPardonForm", "Alice");

    // Display results
    std::cout << "Created forms using specific functions:\n";
    std::cout << *presidentialPardon << "\n";  // Dereference the pointer to access the object
    std::cout << *robotomyRequest << "\n";
    std::cout << *shrubberyCreation << "\n";

    std::cout << "\nCreated forms using makeForm:\n";
    std::cout << *customForm1 << "\n";
    std::cout << *customForm2 << "\n";
    std::cout << *customForm3 << "\n";

    // Cleanup
    delete presidentialPardon;
    delete robotomyRequest;
    delete shrubberyCreation;
    delete customForm1;
    delete customForm2;
    delete customForm3;

    return 0;
}
