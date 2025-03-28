NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = src/main.c src/game_manager.c src/map_validate.c \
	src/map_validate_structure.c src/output.c src/graphics.c \
	src/setup.c src/map_read.c

OBJS = $(SRCS:.c=.o)
INCLUDES = include/so_long.h
LIBFT = libs/libft/libft.a
FTPRINTF = libs/ft_printf/libftprintf.a
GETNEXTLINE_DIR = libs/get_next_line
GETNEXTLINE_SRCS = $(GETNEXTLINE_DIR)/get_next_line.c $(GETNEXTLINE_DIR)/get_next_line_utils.c
GETNEXTLINE_OBJS = $(GETNEXTLINE_SRCS:.c=.o)
MLX = libs/minilibx/libmlx.a
MLX_EXT = -Llibs/minilibx -lmlx -lXext -lX11 -lm

%.o: %.c $(INCLUDES)
	$(CC) $(CFLAGS) -c $< -o $@ -Iinclude

$(GETNEXTLINE_DIR)/%.o: $(GETNEXTLINE_DIR)/%.c $(INCLUDES)
	$(CC) $(CFLAGS) -c $< -o $@ -I$(GETNEXTLINE_DIR)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(FTPRINTF) $(GETNEXTLINE_OBJS) $(MLX)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(FTPRINTF) $(GETNEXTLINE_OBJS) $(MLX_EXT) -o $(NAME)

$(LIBFT):
	make -C libs/libft

$(FTPRINTF):
	make -C libs/ft_printf

$(MLX):
	make -C libs/minilibx

clean:
	rm -f $(OBJS)
	make clean -C libs/libft
	make clean -C libs/ft_printf
	rm -f $(GETNEXTLINE_OBJS)
	make clean -C libs/minilibx

fclean: clean
	rm -f $(NAME)
	make fclean -C libs/libft
	make fclean -C libs/ft_printf

re: fclean all

.PHONY: all clean fclean re