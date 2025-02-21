/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouzi < mdouzi@student.1337.ma>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 04:45:03 by mdouzi            #+#    #+#             */
/*   Updated: 2024/01/13 12:16:59 by mdouzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void) :AForm("RobotomyRequestForm", 72, 45), _target("default") {}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &copy) :AForm(copy), _target(copy._target) {}

RobotomyRequestForm::RobotomyRequestForm(std::string const &target) :AForm("RobotomyRequestForm", 72, 45), _target(target) {}

RobotomyRequestForm::~RobotomyRequestForm(void) {}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const {
    if (this->getIsSigned()) {
        if (executor.getGrade() > this->getExGrade())
            throw AForm::GradeTooHighException();
        else
            std::cout << this->_target << " has been robotomized successfully 50% of the time" << std::endl;
    } else
        throw AForm::GradeTooLowException();
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
    if (this != &other)
    {
        this->_target = other._target;
    }
    return *this;
}

std::ostream& operator<<(std::ostream& os, const RobotomyRequestForm& form){
    os << "AForm" << form.getName() << ", is Signed : " << form.getIsSigned() << ", sign grade :" << form.getSignedGrade() <<  ", ex Grade : " << form.getExGrade() << std::endl;
    return os;
}

