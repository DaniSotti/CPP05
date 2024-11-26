#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>

class Bureaucrat {
private:
    const std::string name;
    int grade;

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
    const std::string& getName() const;
    int getGrade() const;

    //Functions of motifiers
    void incrementGrade();
    void decrementGrade();
};

//Function overload of the insertion operator outside the class
std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

#endif