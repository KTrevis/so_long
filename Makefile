NAME = so_long

C_FILES = main.c input.c parse_map.c check_map.c check_walls.c render.c pathfinding.c \
					pathfinding_parsing.c collision.c check_components.c enemies.c \

SRCS = $(addprefix srcs/,$(C_FILES))

CFLAGS = -Wall -Wextra -Werror

LIBS = ft_printf/libftprintf.a libft/libft.a
DEPS = $(addprefix libs/,$(LIBS))

all: $(NAME)

$(NAME):
	make -C libs/mlx
	make -C libs/ft_printf
	make -C libs/libft
ifdef bonus
	cc $(CFLAGS) $(SRCS) -D BONUS=1 -g3 -I includes/ -L libs/mlx -l mlx -I mlx -lXext -lX11 -lm -lz -o $(NAME) $(DEPS)
else
	cc $(CFLAGS) $(SRCS) -g3 -I includes/ -L libs/mlx -l mlx -I mlx -lXext -lX11 -lm -lz -o $(NAME) $(DEPS)
endif

bonus:
	make bonus=1

clean:
	make -C libs/mlx clean
	make -C libs/ft_printf clean
	make -C libs/libft clean

fclean: clean
	make -C libs/libft fclean
	make -C libs/ft_printf fclean
	rm -f $(NAME)

re: fclean all
