NAME = so_long

C_FILES = main.c input.c parse_map.c check_map.c check_walls.c render.c pathfinding.c pathfinding_parsing.c
SRCS = $(addprefix srcs/,$(C_FILES))

CFLAGS = -Wall -Wextra -Werror

LIBS = ft_printf/libftprintf.a libft/libft.a
DEPS = $(addprefix libs/,$(LIBS))

all: $(NAME)

$(NAME):
	make -C libs/mlx
	make -C libs/ft_printf
	make -C libs/libft
	cc $(SRCS) -g3 -I includes/ -L libs/mlx -l mlx -I mlx -lXext -lX11 -lm -lz -o $(NAME) $(DEPS)

clean:
	make -C libs/ft_printf clean
	make -C libs/libft clean

fclean: clean
	rm -f $(NAME)

re: fclean all
