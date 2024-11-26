#include "Intern.hpp"

int main() {
    Intern intern;
    AForm* form;

    form = intern.makeForm("robotomy request", "Bender");
    if (form) {
        std::cout << *form << std::endl;
        delete form;
    }

    form = intern.makeForm("shrubbery creation", "Home");
    if (form) {
        std::cout << *form << std::endl;
        delete form;
    }

    form = intern.makeForm("invalid form", "Unknown");
    if (form) {
        delete form;
    }

    return 0;
}
