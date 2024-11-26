#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>
#include "Form.hpp"

class Form;

class Bureaucrat
{
private:
    const std::string name;
    int grade;
    Bureaucrat( void );
public:
    //exceptions
    class GradeTooHighException : public std::exception {
        public:
            virtual const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
        public:
            virtual const char* what() const throw();
    };

    //constructor and Destructor
    Bureaucrat(const std::string& name, int grade);
    ~Bureaucrat();
    Bureaucrat(const Bureaucrat& other);
    Bureaucrat& operator=(const Bureaucrat& other);

    //getters
    std::string getName() const;
    int getGrade() const;
    void incrementGrade();
    void decrementGrade();
    void signForm(Form &form) const;
};

//Function overload of the insertion operator outside the class
std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

#endif