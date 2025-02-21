/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouzi < mdouzi@student.1337.ma>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 04:45:13 by mdouzi            #+#    #+#             */
/*   Updated: 2024/01/13 12:17:34 by mdouzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <iostream>
#include "AForm.hpp"
#include "Bureaucrat.hpp"

class Bureaucrat;

class RobotomyRequestForm : public AForm {
private:
    std::string _target;

public:
    RobotomyRequestForm(void);
    RobotomyRequestForm(RobotomyRequestForm const &copy);
    RobotomyRequestForm(std::string const &target);
    virtual ~RobotomyRequestForm(void);

    // operator =
   RobotomyRequestForm &operator=(const RobotomyRequestForm &other);

    // main member function
    void execute(Bureaucrat const &executor) const;
};

std::ostream& operator<<(std::ostream& os, const RobotomyRequestForm& form);

#endif

