# Variables
CC = gcc
CFLAGS = -Wall -Wextra -Werror
MLX_DIR = ./minilibx-linux
MLX_LIB = $(MLX_DIR)/libmlx.a
MLX_FLAGS = -L$(MLX_DIR) -lmlx -lm -lX11 -lXext
INCLUDES = -I ./includes
SRC_DIR = ./srcs
SRCS = $(SRC_DIR)/main.c $(SRC_DIR)/mlx_manager.c $(SRC_DIR)/fractal_calculations.c $(SRC_DIR)/check_params.c
OBJS = $(SRCS:.c=.o)
NAME = fractol

# Rules
all: $(MLX_LIB) $(NAME)

$(MLX_LIB):
	@$(MAKE) -C $(MLX_DIR)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(MLX_FLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS)
	@$(MAKE) -C $(MLX_DIR) clean

fclean: clean
	rm -f $(NAME)
	@$(MAKE) -C $(MLX_DIR) clean

re: fclean all

.PHONY: all clean fclean re
