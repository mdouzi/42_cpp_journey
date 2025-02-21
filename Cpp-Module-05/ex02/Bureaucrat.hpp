/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouzi < mdouzi@student.1337.ma>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 02:58:23 by mdouzi            #+#    #+#             */
/*   Updated: 2024/01/12 11:01:26 by mdouzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>
#include "AForm.hpp"

class AForm;
class Bureaucrat {
    private:
        const std::string name;
        int grade;

    public:
        // Constructors
        Bureaucrat();
        Bureaucrat(std::string _name, int _grade);
        Bureaucrat(const Bureaucrat &other);

        // Destructor
        ~Bureaucrat();

        // Getters
        const std::string &getName() const;
        int getGrade() const;

        // Exception classes
        class GradeTooHighException : public std::exception {
        public:
            const char* what() const throw();
        };

        class GradeTooLowException : public std::exception {
        public:
            const char* what() const throw();
        };

        // Member functions
        void gradeUp();
        void gradeDown();
        void signForm(AForm &Form);
        void executeForm(AForm const & form);
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);

#endif
