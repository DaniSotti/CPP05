#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

class RobotomyRequestForm : public AForm {
    private:
        std::string _target;
    
    public:
        RobotomyRequestForm(const std::string& target);
        ~RobotomyRequestForm();

        void execute(const Bureaucrat& executor) const;
};

#endif