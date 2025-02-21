/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouzi < mdouzi@student.1337.ma>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 03:07:26 by mdouzi            #+#    #+#             */
/*   Updated: 2024/01/13 12:10:09 by mdouzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include <iostream>
#include "AForm.hpp"
#include "Bureaucrat.hpp"

class Bureaucrat;

class PresidentialPardonForm : public AForm {
private:
     std::string _target;

public:
    PresidentialPardonForm(void);
    PresidentialPardonForm(PresidentialPardonForm const& other);
    PresidentialPardonForm(std::string const& target);
    virtual ~PresidentialPardonForm(void);

    // operator = 
   PresidentialPardonForm &operator=(const PresidentialPardonForm &other);
    
    // main member function
    void execute(Bureaucrat const &executor) const;
};
std::ostream& operator<<(std::ostream& os, const PresidentialPardonForm& form);
#endif
