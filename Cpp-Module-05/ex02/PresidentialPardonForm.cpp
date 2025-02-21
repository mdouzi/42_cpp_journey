/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouzi < mdouzi@student.1337.ma>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 03:06:58 by mdouzi            #+#    #+#             */
/*   Updated: 2024/01/13 12:16:13 by mdouzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) : AForm(), _target("default") {}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &other) : AForm(other), _target(other._target) {}

PresidentialPardonForm::PresidentialPardonForm(std::string const &target) : AForm("PresidentialPardonForm", 25, 5), _target(target) {}

PresidentialPardonForm::~PresidentialPardonForm(void) {}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const {
    if (this->getIsSigned() == true) {
        if (executor.getGrade() > this->getExGrade())
            throw AForm::GradeTooLowException();
        else
            std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
    } else
        throw AForm::GradeTooLowException();
}

std::ostream& operator<<(std::ostream& os, const PresidentialPardonForm& form){
    os << "AForm" << form.getName() << ", is Signed : " << form.getIsSigned() << ", sign grade :" << form.getSignedGrade() <<  ", ex Grade : " << form.getExGrade() << std::endl;
    return os;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
    if (this != &other)
    {
        this->_target = other._target;
    }
    return *this;
}

