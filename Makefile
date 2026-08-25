NAME = push_swap

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
	errors.c \
	compute_disorder.c \
	common_moves.c \
	insertion.c \
	insertion_target.c \
	insertion_cost.c \
	find_cheapest.c \
	insertion_move.c \
	medium_sort.c \
	radix_sort.c \
	adaptive_sort.c \
	indexes.c \
	parser_flags.c \
	parser_numbers.c \
	utils_parser_num.c \
	ft_atol.c \
	split.c \

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
