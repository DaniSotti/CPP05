#include "Bureaucrat.hpp"
#include <iostream>

int main() {
    // Teste 1: Criação de um Bureaucrat válido
    try {
        Bureaucrat b1("Alice", 75);
        std::cout << "Teste 1 - Bureaucrat válido: " << b1 << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Erro no Teste 1: " << e.what() << std::endl;
    }

    // Teste 2: Incremento de nota dentro do limite
    try {
        Bureaucrat b2("Bob", 2);
        std::cout << "Teste 2 - Antes do incremento: " << b2 << std::endl;
        b2.incrementGrade();
        std::cout << "Teste 2 - Depois do incremento: " << b2 << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Erro no Teste 2: " << e.what() << std::endl;
    }

    // Teste 3: Decremento de nota dentro do limite
    try {
        Bureaucrat b3("Charlie", 149);
        std::cout << "Teste 3 - Antes do decremento: " << b3 << std::endl;
        b3.decrementGrade();
        std::cout << "Teste 3 - Depois do decremento: " << b3 << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Erro no Teste 3: " << e.what() << std::endl;
    }

    // Teste 4: Exceção ao incrementar acima do limite
    try {
        Bureaucrat b4("David", 1);
        std::cout << "Teste 4 - Antes do incremento: " << b4 << std::endl;
        b4.incrementGrade();  // Deve lançar GradeTooHighException
    } catch (const std::exception& e) {
        std::cerr << "Erro no Teste 4: " << e.what() << std::endl;
    }

    // Teste 5: Exceção ao decrementar abaixo do limite
    try {
        Bureaucrat b5("Eve", 150);
        std::cout << "Teste 5 - Antes do decremento: " << b5 << std::endl;
        b5.decrementGrade();  // Deve lançar GradeTooLowException
    } catch (const std::exception& e) {
        std::cerr << "Erro no Teste 5: " << e.what() << std::endl;
    }

    // Teste 6: Exceção ao criar Bureaucrat com nota alta demais
    try {
        Bureaucrat b6("Frank", 0);  // Deve lançar GradeTooHighException
    } catch (const std::exception& e) {
        std::cerr << "Erro no Teste 6: " << e.what() << std::endl;
    }

    // Teste 7: Exceção ao criar Bureaucrat com nota baixa demais
    try {
        Bureaucrat b7("Grace", 151);  // Deve lançar GradeTooLowException
    } catch (const std::exception& e) {
        std::cerr << "Erro no Teste 7: " << e.what() << std::endl;
    }

    return 0;
}
