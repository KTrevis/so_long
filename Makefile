NAME = so_long

C_FILES = main.c
SRCS = $(addprefix srcs/,$(C_FILES))
OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	cc $(CFLAGS) $(OBJS) -Lmlx -lmlx -Imlx -lXext -lX11 -lm -lz -o $(NAME) ft_printf/libftprintf.a

$(OBJS): $(SRCS)
	make -C mlx
	make -C ft_printf
	cc $(CFLAGS) -I includes -O3 -c $(SRCS) -o $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
