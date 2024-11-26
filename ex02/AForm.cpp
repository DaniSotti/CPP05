#include "AForm.hpp"

AForm::AForm(std::string name, int gradeToSign, int gradeToExecute)
    :
        _name(name),
        _isSigned(false),
        _gradeToSign(gradeToSign),
        _gradeToExecute(gradeToExecute)
{
     std::cout << "AForm constructor called for " << _name << std::endl;
    // if (gradeToSign < 1 || gradeToExecute < 1)
    //     throw GradeTooHighException();
    // if (gradeToSign > 150 || gradeToExecute > 150)
    //     throw GradeTooLowException();
}


AForm::AForm(const AForm &other)
:
    _name(other._name),
    _isSigned(other._isSigned),
    _gradeToSign(other._gradeToSign),
    _gradeToExecute(other._gradeToExecute){
        std::cout << "Copy constructor called" << std::endl;
    }

AForm::~AForm(){
    std::cout << "Destructor called" << std::endl;
}

AForm &AForm::operator=(const AForm &other){
    std::cout << "Operator Constructor called" << std::endl;
    if (this != &other) {
        _isSigned = other._isSigned;
    }
    return *this;
}

std::string AForm::getName() const {
    return _name;
}

bool AForm::isSigned() const {
    return _isSigned;
}

int AForm::getGradeToSign() const {
    return _gradeToSign;
}

int AForm::getGradeToExecute() const {
    return _gradeToExecute;
}

void AForm::beSigned(const Bureaucrat &Bureaucrat)
{
    if (Bureaucrat.getGrade() > _gradeToSign)
        throw GradeTooLowException();
    _isSigned = true;
}

const char* AForm::GradeTooHighException::what() const throw(){
    return "AForm grade is too high!";
}

const char* AForm::GradeTooLowException::what() const throw(){
    return "AForm grade is too low!";
}

const char* AForm::FormNotSignedException::what() const throw(){
    return "Form is not signed!";
}

std::ostream &operator<<(std::ostream &os, const AForm &form)
{
    os << "Form " << form.getName() << " requires grade "   << form.getGradeToSign() << " to sign and grade "   << form.getGradeToExecute() << " to execute." << " Signed status: " << (form.isSigned() ? "Yes" : "No");
    return os;
}
