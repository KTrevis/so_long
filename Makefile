NAME = so_long

C_FILES = main.c input.c parse_map.c
SRCS = $(addprefix srcs/,$(C_FILES))

CFLAGS = -Wall -Wextra -Werror

LIBS = ft_printf/libftprintf.a libft/libft.a
DEPS = $(addprefix libs/,$(LIBS))

all: $(NAME)

$(NAME):
	make -C libs/mlx
	make -C libs/ft_printf
	cc $(CFLAGS) $(SRCS) -I includes/ -L libs/mlx -l mlx -I mlx -lXext -lX11 -lm -lz -o $(NAME) $(DEPS)

fclean:
	rm -f $(NAME)

re: fclean all
