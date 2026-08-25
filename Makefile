NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = \
	push_swap.c \
	nodes.c \
	nodes_utils.c \
	little_numbers.c \
	medium_alg.c \
	indexes.c \
	parser_flags.c \
	parser_numbers.c \
	ft_atol.c \
	utils_parser_num.c \
	split.c \
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
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re