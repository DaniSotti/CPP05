#include "Intern.hpp"

Intern::Intern() {
    std::cout << "Intern created" << std::endl;
}

Intern:: Intern(const Intern& other) {
    (void)other;
    std::cout << "Intern copy constructed" << std::endl;
}

Intern::~Intern() {
    std::cout << "Intern destructor called" << std::endl;
}

Intern& Intern::operator=(const Intern& other) {
    (void)other;
    std::cout << "Intern assigned" << std::endl;
    return *this;
}

AForm* createShrubberyForm(const std::string& target) {
    return new ShrubberyCreationForm(target);
}

AForm* createRobotomyForm(const std::string& target) {
    return new RobotomyRequestForm(target);
}

AForm* createPresidentialPardonForm(const std::string& target) {
    return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(const std::string& formName, const std::string& target){
    const std::string formNames[] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };

    AForm* (*formCreators[])(const std::string&) = {
        createShrubberyForm,
        createRobotomyForm,
        createPresidentialPardonForm
    };
    
    for (int i= 0; i < 3; ++i) {
        if (formNames[i] == formName) {
            std::cout << "Intern creates " << formName << std::endl;
            return formCreators[i](target);
        }
    }
    std::cout << "Error: Form " << formName << " does not exist." << std::endl;
    return NULL;
}