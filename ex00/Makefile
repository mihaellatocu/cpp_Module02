NAME = fixed
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

src = main.cpp Fixed.cpp
#OBJ_F = ./obj
obj = $(src:.cpp=.o)

all: $(NAME)

$(NAME): $(obj)
	$(CC) $(CFLAGS) $(obj) -o $(NAME)

%.o:%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(obj)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.Phony: all clean fclean re

