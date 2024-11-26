#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : AForm("ShrubberyCreationForm", 145, 137), _target(target) {
    std::cout << "Constructor called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
    std::cout << "Destructor called" << std::endl;
}

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const{
    if (!this->isSigned())
        throw AForm::FormNotSignedException();
    if (executor.getGrade() > this->getGradeToExecute())
        throw AForm::GradeTooLowException();
    
    std::ofstream outFile((_target + "_shrubbery").c_str());
    if (outFile.is_open()) {
        outFile << "ASCII trees" << std::endl;
        outFile.close();
    } else {
        std::cerr << "Failed to create file" << std::endl;
    }
}
