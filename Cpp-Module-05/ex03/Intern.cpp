/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouzi < mdouzi@student.1337.ma>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 12:05:16 by mdouzi            #+#    #+#             */
/*   Updated: 2024/01/13 12:38:34 by mdouzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern(void) {}

Intern::~Intern(void) {}

AForm *Intern::createPresidentialPardonForm(std::string target) {
    return new PresidentialPardonForm(target);
}

AForm *Intern::createRobotomyRequestForm(std::string target) {
    return new RobotomyRequestForm(target);
}

AForm *Intern::createShrubberyCreationForm(std::string target) {
    return new ShrubberyCreationForm(target);
}

AForm *Intern::makeForm(std::string formName, std::string formTarget) {
    AForm *newForm = NULL;

    std::string validFormNames[3] = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};
    AForm *(Intern::*createFormPtr[3])(std::string) = {&Intern::createPresidentialPardonForm, &Intern::createRobotomyRequestForm, &Intern::createShrubberyCreationForm};

    for (int i = 0; i < 3; ++i) {
        if (formName == validFormNames[i]) {
            newForm = (this->*createFormPtr[i])(formTarget);
            break;
        }
    }
    if(newForm == NULL)
        std::cout << "error Form Name in wrong " << std::endl;

    return newForm;
}

Intern &Intern::operator=(const Intern &other)
{
    (void)other;
    return(*this);
}