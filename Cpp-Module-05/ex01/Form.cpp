/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouzi < mdouzi@student.1337.ma>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 03:48:50 by mdouzi            #+#    #+#             */
/*   Updated: 2024/01/13 11:52:28 by mdouzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

// GradeTooHighException implementation
const char* Form::GradeTooHighException::what() const throw() {
    return "Grade is too high";
}

// GradeTooLowException implementation
const char* Form::GradeTooLowException::what() const throw() {
    return "Grade is too low";
}

// Form class implementation

// Default constructor
Form::Form(void) : name("Default"), isSigned(false), s_grade(1), ex_grade(1) {};

// Parameterized constructor
Form::Form(const std::string _name, int const& sGrade, int const& exGrade)
    : name(_name), isSigned(false), s_grade(sGrade), ex_grade(exGrade) {
    if (sGrade < 1 || exGrade < 1)
        throw Form::GradeTooHighException();
    else if (sGrade > 150 || exGrade > 150)
        throw Form::GradeTooLowException();
}

// Copy constructor
Form::Form(Form const& other)
    : name(other.getName()), isSigned(other.getIsSigned()), s_grade(other.getSignedGrade()), ex_grade(other.getExGrade()) {}

// Destructor
Form::~Form(void) {}

// Getter functions
bool Form::getIsSigned() const {
    return isSigned;
}

int Form::getSignedGrade() const {
    return s_grade;
}

int Form::getExGrade() const {
    return ex_grade;
}

const std::string Form::getName() const {
    return name;
}

// beSigned function
void Form::beSigned(Bureaucrat& bureaucrat) 
{
    if (bureaucrat.getGrade() <= s_grade)
        isSigned = true;
    else
        throw Form::GradeTooLowException();
}


std::ostream& operator<<(std::ostream& os, const Form& form) {
    os << "Form" << form.getName() << ", is Signed : " << form.getIsSigned() << ", sign grade :" << form.getSignedGrade() <<  ", ex Grade : " << form.getExGrade() << std::endl;
    return os;
}

Form &Form::operator=(const Form &other)
{
    if (this != &other) {
        this->isSigned = other.isSigned;
    }
    return *this;
}