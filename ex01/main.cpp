// #include "Bureaucrat.hpp"
// #include "Form.hpp"

// int main() {
//     try {
//         Bureaucrat john("John", 3);
//         Form formA("FormA", 5, 10);
//         Form formB("FormB", 2, 10);

//         john.signForm(formA);  // Deve assinar com sucesso
//         john.signForm(formB);  // Deve falhar pois o grade de John é baixo para formB

//     } catch (const std::exception &e) {
//         std::cerr << "Error: " << e.what() << std::endl;
//     }
//     return 0;
// }

#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main(void)
{
	{
		try
		{
			Bureaucrat	Marvin("Marvin", 5);
			std::cout << Marvin;
			Form	x("28A", 151, 100);
			std::cout << x;
			Marvin.signForm(x);
			std::cout << x;
		}
		catch(Form::GradeTooLowException& e)
		{
			std::cerr << "Form construction failed because " << e.what() << '\n';
		}
		catch(Form::GradeTooHighException& e)
		{
			std::cerr << "Form construction failed because " << e.what() << '\n';
		}
		catch(Bureaucrat::GradeTooLowException &e)
		{
			std::cerr << "Bureaucrat construction failed because " << e.what() << ".\n";
		}
		catch(Bureaucrat::GradeTooHighException &e)
		{
			std::cerr << "Bureaucrat construction failed because " << e.what() << ".\n";
		}
	}
	{
		try
		{
			//LOG("");
			Bureaucrat	Marvin("Marvin", 5);
			std::cout << Marvin;
			Form	x("28B", -2, 100);
			std::cout << x;
			Marvin.signForm(x);
			std::cout << x;
		}
		catch(Form::GradeTooLowException& e)
		{
			std::cerr << "Form construction failed because " << e.what() << '\n';
		}
		catch(Form::GradeTooHighException& e)
		{
			std::cerr << "Form construction failed because " << e.what() << '\n';
		}
		catch(Bureaucrat::GradeTooLowException &e)
		{
			std::cerr << "Bureaucrat construction failed because " << e.what() << ".\n";
		}
		catch(Bureaucrat::GradeTooHighException &e)
		{
			std::cerr << "Bureaucrat construction failed because " << e.what() << ".\n";
		}
	}
	{
		try
		{
			//LOG("");
			Bureaucrat	Marvin("Marvin", 5);
			std::cout << Marvin;
			Form	x("28C", 4, 100);
			Form	y("28D", 10, 100);
			//LOG("");
			std::cout << x;
			Marvin.signForm(x);
			std::cout << x;
			//LOG("");
			std::cout << y;
			Marvin.signForm(y);
			std::cout << y;
		}
		catch(Form::GradeTooLowException& e)
		{
			std::cerr << "Form construction failed because " << e.what() << '\n';
		}
		catch(Form::GradeTooHighException& e)
		{
			std::cerr << "Form construction failed because " << e.what() << '\n';
		}
		catch(Bureaucrat::GradeTooLowException &e)
		{
			std::cerr << "Bureaucrat construction failed because " << e.what() << ".\n";
		}
		catch(Bureaucrat::GradeTooHighException &e)
		{
			std::cerr << "Bureaucrat construction failed because " << e.what() << ".\n";
		}
	}
}
