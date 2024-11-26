#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    try {
        Bureaucrat john("John", 50);
        ShrubberyCreationForm shrubbery("home");
        RobotomyRequestForm robotomy("target");
        PresidentialPardonForm pardon("Alice");

        john.signForm(shrubbery);
        john.executeForm(shrubbery);

        john.signForm(robotomy);
        john.executeForm(robotomy);

        john.signForm(pardon);
        john.executeForm(pardon);
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
