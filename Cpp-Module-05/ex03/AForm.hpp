/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouzi < mdouzi@student.1337.ma>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 03:59:26 by mdouzi            #+#    #+#             */
/*   Updated: 2024/01/12 11:03:19 by mdouzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// AForm.hpp
#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"
#include <iostream>

class Bureaucrat;

class AForm {
private:
    const std::string name;
    bool isSigned;
    const int s_grade;
    const int ex_grade;

public:
    AForm(void);
    AForm(const std::string _name, int const &sGrade, int const &exGrade);
    AForm(AForm const &other);
    virtual ~AForm(); // Define the destructor

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

    // pure virtual function
    virtual void execute(Bureaucrat const & executor) const = 0;

    // main member function
    void beSigned(Bureaucrat &bureaucrat);
};

std::ostream& operator<<(std::ostream& os, const AForm& form);

#endif

