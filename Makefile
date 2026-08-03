NAME = test

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = \
	push_swap.c \
	nodes.c \
	nodes_utils.c \
	little_numbers.c \
	swap.c \
	push.c \
	rotate.c \
	reverse_rotate.c \
	utils.c \
	libft_utils.c \
	errors.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re