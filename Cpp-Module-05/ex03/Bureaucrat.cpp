/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouzi < mdouzi@student.1337.ma>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 05:12:15 by mdouzi            #+#    #+#             */
/*   Updated: 2024/01/07 14:51:52 by mdouzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

// Constructors
Bureaucrat::Bureaucrat() : name("none") {
    this->grade = 150;
    std::cout << "Bureaucrat Default constructor been called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string _name, int _grade) : name(_name) {
    this->grade = _grade;
    if (grade < 1)
        throw GradeTooHighException();
    else if (grade > 150)
        throw GradeTooLowException();
    std::cout << "Bureaucrat arg Constructor been called " << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : name(other.getName() + " copied"), grade(other.getGrade()) {
    std::cout << "Bureaucrat copy constructor been called" << std::endl;
}

// Exception classes functions
const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return "Grade is too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return "Grade is too low";
}

// Destructor
Bureaucrat::~Bureaucrat() {
    std::cout << "Bureaucrat Destructor been called" << std::endl;
}

// Getters functions
const std::string &Bureaucrat::getName() const {
    return (this->name);
}

int Bureaucrat::getGrade() const {
    return (this->grade);
}

// Member functions
void Bureaucrat::gradeUp() {
    if (grade > 1)
        grade--;
    else
        throw GradeTooHighException();
}

void Bureaucrat::gradeDown() {
    if (grade < 150)
        grade++;
    else
        throw GradeTooLowException();
}

void Bureaucrat::signForm(AForm &Form)
{
    try 
    {
        Form.beSigned(*this);
        std::cout << this->getName() << " signed " << Form.getName() << std::endl;
    }
    catch(std::exception &e)
    {
        std::cout << this->getName() << " couldn’t sign " << Form.getName() << "Because " << e.what() << std::endl;  
    }
}

void Bureaucrat::executeForm(AForm const & form)
{
    try
    {
        form.execute(*this);
        std::cout << this->getName() << " executed " << form.getName() << std::endl;
    }
    catch(std::exception &e)
    {
        std::cout << this->getName() << "couldn't sign " << form.getName() << " Because " << e.what() << std::endl;
    }
}

// Overloaded insertion operator
std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat) {
    os << "Bureaucrat " << bureaucrat.getName() << ", Grade: " << bureaucrat.getGrade();
    return os;
}

