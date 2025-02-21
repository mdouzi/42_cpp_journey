/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouzi < mdouzi@student.1337.ma>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 03:48:50 by mdouzi            #+#    #+#             */
/*   Updated: 2024/01/12 08:10:07 by mdouzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

// GradeTooHighException implementation
const char* AForm::GradeTooHighException::what() const throw() {
    return "Grade is too high";
}

// GradeTooLowException implementation
const char* AForm::GradeTooLowException::what() const throw() {
    return "Grade is too low";
}

// AForm class implementation

// Default constructor
AForm::AForm(void) : name("Default"), isSigned(false), s_grade(1), ex_grade(1) {};

// Parameterized constructor
AForm::AForm(const std::string _name, int const& sGrade, int const& exGrade)
    : name(_name), isSigned(false), s_grade(sGrade), ex_grade(exGrade) {
    if (sGrade < 1 || exGrade < 1)
        throw AForm::GradeTooHighException();
    else if (sGrade > 150 || exGrade > 150)
        throw AForm::GradeTooLowException();
}

// Copy constructor
AForm::AForm(AForm const& other)
    : name(other.getName()), isSigned(other.getIsSigned()), s_grade(other.getSignedGrade()), ex_grade(other.getExGrade()) {}

// Destructor
AForm::~AForm(void) {}

// Getter functions
bool AForm::getIsSigned() const {
    return isSigned;
}

int AForm::getSignedGrade() const {
    return s_grade;
}

int AForm::getExGrade() const {
    return ex_grade;
}

const std::string AForm::getName() const {
    return name;
}

// beSigned function
void AForm::beSigned(Bureaucrat& bureaucrat) 
{
    if (bureaucrat.getGrade() <= s_grade)
        isSigned = true;
    else
        throw AForm::GradeTooLowException();
}

std::ostream& operator<<(std::ostream& os, const AForm& form) {
    os << "AForm" << form.getName() << ", is Signed : " << form.getIsSigned() << ", sign grade :" << form.getSignedGrade() <<  ", ex Grade : " << form.getExGrade() << std::endl;
    return os;
}

