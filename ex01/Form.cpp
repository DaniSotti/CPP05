#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(std::string _name, int gradeToSign, int gradeToExecute)
    :
        _name(_name),
        _isSigned(false),
        _gradeToSign(gradeToSign),
        _gradeToExecute(gradeToExecute)
{
     std::cout << "Form constructor called for " << _name << std::endl;
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
}


Form::Form(const Form &other)
:
    _name(other._name),
    _isSigned(other._isSigned),
    _gradeToSign(other._gradeToSign),
    _gradeToExecute(other._gradeToExecute){
        std::cout << "Copy constructor called" << std::endl;
    }

Form::~Form(){
    std::cout << "destructor called" << std::endl;
}

Form &Form::operator=(const Form &other){
    std::cout << "Operator Constructor called" << std::endl;
    if (this != &other) {
        _isSigned = other._isSigned;
    }
    return *this;
}

std::string Form::getName() const {
    return _name;
}

bool Form::isSigned() const {
    return _isSigned;
}

int Form::getGradeToSign() const {
    return _gradeToSign;
}

int Form::getGradeToExecute() const {
    return _gradeToExecute;
}

void Form::beSigned(const Bureaucrat &Bureaucrat)
{
    if (Bureaucrat.getGrade() > _gradeToSign)
        throw GradeTooLowException();
    _isSigned = true;
}

const char* Form::GradeTooHighException::what() const throw(){
    return "Form grade is too high!";
}

const char* Form::GradeTooLowException::what() const throw(){
    return "Form grade is too low!";
}

std::ostream &operator<<(std::ostream &os, const Form &form)
{
    os << "Form " << form.getName() << " requires grade "   << form.getGradeToSign() << " to sign and grade "   << form.getGradeToExecute() << " to execute." << " Signed status: " << (form.isSigned() ? "Yes" : "No");
    return os;
}
