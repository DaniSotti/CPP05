#ifndef INTER_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <string>
#include <iostream>

class Intern {
    public:
        Intern();
        Intern(const Intern& other);
        ~Intern();

        Intern& operator=(const Intern& other);

        AForm* makeForm(const std::string& formName, const std::string& target);
};

#endif