# Derleyici ve bayraklar
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Proje adları ve yolları
NAME = so_long
SRC_DIR = src
LIB_DIR_G = lib/get_next_line
LIB_DIR_P = lib/ft_printf
LIB_DIR_L = lib/libft
MLX_DIR = minilibx-linux

# Kaynak dosyalar
SRC_FILES = $(SRC_DIR)/so_long.c \
            $(SRC_DIR)/game.c \
            $(SRC_DIR)/map_parser.c \
            $(SRC_DIR)/graphics.c \
            $(LIB_DIR_G)/get_next_line.c \
            $(LIB_DIR_G)/get_next_line_utils.c \

# Nesne dosyaları
OBJ_FILES = $(SRC_FILES:.c=.o)

# Minilibx kütüphanesi
MLX_LIB = $(MLX_DIR)/libmlx.a

# Hedefler
all: $(NAME)

$(NAME): $(OBJ_FILES) $(MLX_LIB) $(LIB_DIR_L)/libft.a $(LIB_DIR_P)/libftprintf.a
	$(CC) $(CFLAGS) $(OBJ_FILES) -L$(MLX_DIR) -lmlx -lX11 -lXext -L$(LIB_DIR_L) -lft -L$(LIB_DIR_P) -lftprintf -o $(NAME)

$(MLX_LIB):
	$(MAKE) -C $(MLX_DIR)

$(LIB_DIR_L)/libft.a:
	$(MAKE) -C $(LIB_DIR_L)

$(LIB_DIR_P)/libftprintf.a:
	$(MAKE) -C $(LIB_DIR_P)

# Temizleme
clean:
	rm -f $(OBJ_FILES)
	$(MAKE) clean -C $(MLX_DIR)
	$(MAKE) clean -C $(LIB_DIR_L)
	$(MAKE) clean -C $(LIB_DIR_P)

fclean: clean
	rm -f $(NAME)

re: fclean all

# Sahte hedefler
.PHONY: all clean fclean re