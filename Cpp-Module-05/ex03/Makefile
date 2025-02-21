CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

# Executable name
NAME = ex03

# Source files
SRCS = AForm.cpp Bureaucrat.cpp main.cpp  PresidentialPardonForm.cpp ShrubberyCreationForm.cpp RobotomyRequestForm.cpp Intern.cpp

# Object files
OBJS = $(SRCS:.cpp=.o)

# Targets
all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

# Compile source files to object files
%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
