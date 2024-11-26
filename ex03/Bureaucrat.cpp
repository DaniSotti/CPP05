#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat( void ) : name("default"), grade(150)
{
    std::cout << "Void Bureaucrat constructo called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : name(name), grade(grade)
{
    std::cout << "Bureaucrat Constructor called for " << name << std::endl;
    if (grade < 1){
        throw GradeTooHighException();
    } else if (grade > 150) {
        throw GradeTooLowException();
    }
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : name(other.getName()), grade(other.getGrade()) {
    std::cout << "Bureacrat copy constructior called" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
    std::cout << "Bureaucrat operator called" << std::endl;
    if (this != &other) {
        this->grade = other.grade;
    }
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
    return *this;
}

Bureaucrat::~Bureaucrat(){
    std::cout << "Bureaucrat destructor called" << std::endl;
};

std::string Bureaucrat::getName(void) const {
    return name;
}

int Bureaucrat::getGrade() const {
    return grade;
}

void Bureaucrat::incrementGrade() {
    if (grade <= 1) {
        throw GradeTooHighException();
    }
    grade--;
}

void Bureaucrat::decrementGrade() {
    if (grade >= 150) {
        throw GradeTooHighException();
    }
    grade++;
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return "Grade is too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return "Grade is too low!";
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b) {
    os << b.getName() << ",bureaucrat grade " << b.getGrade() << "." << std::endl;
    return os;
}

void Bureaucrat::signForm(AForm &form) const {
    try {
        form.beSigned(*this);
        std::cout << name << " signed " << form.getName() << std::endl;
    } catch (AForm::GradeTooLowException &e) {
        std::cout << name << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
    }
}

void Bureaucrat::executeForm(const AForm& form) const {
    try {
        form.execute(*this);
        std::cout << name << " execute " << form.getName() << std::endl;
    } catch (const std::exception& e) {
        std::cout << name << " couldn't execute " << form.getName() << "because" << e.what() << std::endl;
    }
}
