/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouzi < mdouzi@student.1337.ma>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 15:08:48 by mdouzi            #+#    #+#             */
/*   Updated: 2024/01/13 12:20:19 by mdouzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYcEATIONFORM_HPP
#define SHRUBBERYcEATIONFORM_HPP
#include "AForm.hpp"
#include <iostream>
#include <fstream>

class  ShrubberyCreationForm: public AForm {
    
    private:
        std::string _target;
    public:
        ShrubberyCreationForm(void);
        ShrubberyCreationForm(ShrubberyCreationForm const& other);
        ShrubberyCreationForm(std::string const& target);
        virtual ~ShrubberyCreationForm(void);
    
        ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);

        void execute(Bureaucrat const & executor) const;
};

std::ostream& operator<<(std::ostream& os, const ShrubberyCreationForm& form);

#endif