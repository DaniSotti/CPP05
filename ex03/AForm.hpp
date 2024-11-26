#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
    private:
        const std::string _name;
        bool              _isSigned;
        const int         _gradeToSign;
        const int         _gradeToExecute;
    
    protected:
        AForm(std::string name, int gradeToSign, int gradeToexecute);
        AForm(const AForm&);
       
        AForm &operator=(const AForm &);

    
    public:
        virtual ~AForm();

        std::string getName() const;
        bool        isSigned() const;
        int         getGradeToSign() const;
        int         getGradeToExecute() const;

        void beSigned(const Bureaucrat &bureaucrat);
        virtual void execute (const Bureaucrat& executor) const = 0; //funcao virtual pura

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

        class FormNotSignedException : public std::exception {
        public:
            const char* what() const throw();
        };
};

std::ostream &operator<<(std::ostream &os, const AForm &form);

#endif