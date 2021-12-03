NAME=fractol

SRC= src/fractol.c src/mandelbrot.c src/julia.c src/burning_ship.c \
	src/utils.c src/colors.c

all: $(NAME)

$(NAME):
	$(MAKE) -C minilibx-linux/
	gcc -Wall -Werror -Wextra $(SRC) minilibx-linux/libmlx.a -lXext -lX11 -lm -o fractol

clean:
	$(MAKE) clean -C minilibx-linux/

fclean: clean
	rm -rf $(NAME)

re: fclean all

bonus: all

.PHONY: all clean fclean re bonus