/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouzi < mdouzi@student.1337.ma>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 03:59:26 by mdouzi            #+#    #+#             */
/*   Updated: 2024/01/13 11:52:18 by mdouzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"
#include <iostream>
#include <exception>


class Bureaucrat;
class Form {
    private:
        const std::string name;
        bool isSigned;
        const int s_grade;
        const int ex_grade;

    public:
        Form(void);
        Form(const std::string _name, int const &sGrade, int const &exGrade);
        Form(Form const &other);
        ~Form(void);

        class GradeTooHighException : public std::exception {
        public:
            const char *what() const throw();
        };

        class GradeTooLowException : public std::exception {
        public:
            const char *what() const throw();
        };

        // member functions
        bool getIsSigned() const;
        int getSignedGrade() const;
        int getExGrade() const;
        const std::string getName() const;
        // main member function
        void beSigned(Bureaucrat &bureaucrat);
        Form &operator=(const Form &other);
};

std::ostream& operator<<(std::ostream& os, const Form& form);

#endif
