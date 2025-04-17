NAME = so_long

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRC_DIR = src
OBJ_DIR = obj
GETNEXTLINE_DIR = libs/get_next_line

SRCS = $(SRC_DIR)/main.c $(SRC_DIR)/game_manager.c $(SRC_DIR)/map_validate.c \
    $(SRC_DIR)/map_validate_structure.c $(SRC_DIR)/output.c $(SRC_DIR)/graphics.c \
    $(SRC_DIR)/setup.c $(SRC_DIR)/map_read.c $(SRC_DIR)/validate_utils.c $(SRC_DIR)/map_path_validate.c \
	$(SRC_DIR)/game_init.c

GETNEXTLINE_SRCS = $(GETNEXTLINE_DIR)/get_next_line.c $(GETNEXTLINE_DIR)/get_next_line_utils.c

OBJS = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))
GETNEXTLINE_OBJS = $(patsubst $(GETNEXTLINE_DIR)/%.c,$(OBJ_DIR)/%.o,$(GETNEXTLINE_SRCS))

INCLUDES = -Iinclude -I$(GETNEXTLINE_DIR)

LIBFT = libs/libft/libft.a
FTPRINTF = libs/ft_printf/libftprintf.a
MLX = libs/minilibx/libmlx.a
MLX_EXT = -Llibs/minilibx -lmlx -lXext -lX11 -lm

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

$(OBJ_DIR)/%.o: $(GETNEXTLINE_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

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
	rm -rf $(OBJS) $(GETNEXTLINE_OBJS)
	make clean -C libs/libft
	make clean -C libs/ft_printf
	make clean -C libs/minilibx

fclean: clean
	rm -rf $(NAME) $(OBJ_DIR)
	make fclean -C libs/libft
	make fclean -C libs/ft_printf

re: fclean all

.PHONY: all clean fclean re