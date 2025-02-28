CFLAGS		= -Wall -Wextra -Werror -I. -I$(MLX_DIR) -I$(GNL_DIR) -I./includes
SRC_DIR		= src
GNL_DIR		= lib/get_next_line
MLX_DIR		= minilibx-linux
LIBFT_DIR   = lib/libft
FTPRINTF_DIR = lib/ft_printf

SRC_FILES = $(SRC_DIR)/so_long.c \
			$(SRC_DIR)/map_parser.c \
			$(SRC_DIR)/game.c \
			$(GNL_DIR)/get_next_line.c \
			$(GNL_DIR)/get_next_line_utils.c

OBJ_FILES = $(SRC_FILES:.c=.o)

NAME = so_long

LIBFT_FLAGS = -L$(LIBFT_DIR) -lft -L$(FTPRINTF_DIR) -lftprintf

all: $(NAME)

$(NAME): $(OBJ_FILES)
	$(CC) $(CFLAGS) $(OBJ_FILES) -L$(MLX_DIR) -lmlx -lX11 -lXext $(LIBFT_FLAGS) -o $(NAME)

$(GNL_DIR)/get_next_line.o: $(GNL_DIR)/get_next_line.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ_FILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re