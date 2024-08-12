NAME = main
SOURCES = 	sources/main.cpp \
			sources/Bureaucrat.cpp \
			sources/Form.cpp \
			sources/ShrubberyCreationForm.cpp \
			sources/RobotomyRequestForm.cpp \
			sources/PresidentialPardonForm.cpp \
			sources/Intern.cpp \

OBJECTS = $(SOURCES:.cpp=.o)

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

all: ${NAME}

${NAME}: ${OBJECTS}
	@$(CXX) $(CXXFLAGS) -g3 -o ${NAME} ${OBJECTS}

%.o: %.cpp
	@$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@rm -f ${OBJECTS} _shrubbery
	
fclean: clean
	@rm -f ${NAME} _shrubbery

re: fclean all

.PHONY: all clean fclean re