NAME = GNL.a
CC = cc
CFLAGS = -Wall -Wextra -Werror # -g -fsanitize=address
SRC = get_next_line.c get_next_line_utils.c

OBJ = $(SRC:.c=.o)

$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re