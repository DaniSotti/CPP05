#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
    private:
        const std::string _name;
        bool              _isSigned;
        const int         _gradeToSign;
        const int         _gradeToExecute;
        Form ( void );
    
    public:
        Form(std::string name, int gradeToSign, int gradeToexecute);
        Form(const Form&);
        ~Form();
        Form &operator=(const Form &);

        std::string getName() const;
        bool        isSigned() const;
        int         getGradeToSign() const;
        int         getGradeToExecute() const;

        void beSigned(const Bureaucrat &bureaucrat);

        class GradeTooHighException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };

        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
};

std::ostream &operator<<(std::ostream &os, const Form &form);

#endif