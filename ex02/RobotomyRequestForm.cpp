#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : AForm("RobotomyRequestForm", 72, 45), _target(target) {
    std::srand(std::time(0));
}

RobotomyRequestForm::~RobotomyRequestForm() {
    std::cout << "RobotomyRequestForm Destructor called" << std::endl; 
}

void RobotomyRequestForm::execute(const Bureaucrat& executor) const {
    if (!isSigned())
        throw AForm::FormNotSignedException();
    if (executor.getGrade() > getGradeToExecute())
        throw AForm::GradeTooLowException();

    std::cout << "Drilling noises... " << std::endl;
    if (std::rand() % 2 == 0) {
        std::cout << _target << " has been robotomized successfully!" << std::endl;
    } else {
        std::cout << "Robotomy failed for " << _target << "!" << std::endl;
    }
}
