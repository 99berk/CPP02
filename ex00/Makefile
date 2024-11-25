CC = c++
NAME = Fixed
CXXFLAG = -Wall -Wextra -Werror -std=c++98

SRC = 	main.cpp\
		Fixed.cpp\

OBJ = $(SRC:.cpp=.o)

RM = rm -rf

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CXXFLAG) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re