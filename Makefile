NAME        = push_swap

CC          = cc
CFLAGS      = -Wall -Wextra -Werror

SRCS        = main.c \
              split.c \
              node_utils.c \
              parse.c \
              parse_args.c \
              swap.c \
              push.c \
              rotate.c \
              reverse_rotate.c \
              sort_utils.c \
              sort_small.c \
              sort_simple.c \
              sort_large.c \
              sort_complex.c \
              print_bench.c

OBJS        = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re