# Nome do projeto
NAME = Form

# Compilador e flags
CPP = c++
CPP_FLAGS = -Wall -Wextra -Werror -std=c++98

# Arquivos fonte
CPP_SOURCE = main.cpp \
			Bureaucrat.cpp \
			AForm.cpp \
			ShrubberyCreationForm.cpp \
			RobotomyRequestForm.cpp \
			PresidentialPardonForm.cpp \
			Intern.cpp

# Arquivos objeto
O_FILES = $(CPP_SOURCE:.cpp=.o)

# Regra principal
all: $(NAME)

# Compilação de arquivos .cpp em .o
%.o: %.cpp
	$(CPP) $(CPP_FLAGS) -c $< -o $@

# Ligação do projeto final
$(NAME): $(O_FILES)
	$(CPP) $(CPP_FLAGS) $(O_FILES) -o $(NAME)

# Limpeza dos arquivos objeto
clean:
	rm -f $(O_FILES)

# Limpeza completa, incluindo o executável
fclean: clean
	rm -f $(NAME)

# Recompila todo o projeto
re: fclean all

.PHONY: all clean fclean re
