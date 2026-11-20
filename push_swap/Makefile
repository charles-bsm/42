NAME	= push_swap

CC		= cc
CFLAGS	= -Wall -Wextra -Werror

SRCS	= main.c ft_parser.c \
			ft_normalize.c \
			ft_strcmp.c \
			ft_disorder.c \
			utils.c \
			stats.c \
			bench.c \
			strategy.c \
			simple_sort.c \
			medium_sort.c \
			complex_sort.c \
			swap.c \
			push.c \
			rotate.c \
			reverse_rotate.c \

OBJS	= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re