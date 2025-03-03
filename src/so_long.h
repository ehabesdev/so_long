#ifndef SO_LONG_H
#define SO_LONG_H

#include "../minilibx-linux/mlx.h"
#include "../lib/ft_printf/libftprintf.h"
#include "../lib/get_next_line/get_next_line.h"
#include "../lib/libft/libft.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define EMPTY '0'
#define WALL '1'
#define PLAYER 'P'
#define COLLECTIBLE 'C'
#define EXIT 'E'

typedef struct s_map {
    char **tiles;
    int width;
    int height;
    int player_x;
    int player_y;
    int collectible_count;
    int move_count;
    int exit_count;
    int player_count;
    void *mlx_ptr;
    void *win_ptr;
    void *wall_img;
    void *player_img;
    void *collectible_img;
    void *exit_img;
    void *empty_img;
} t_map;

t_map *parse_map(char *filename);
int read_map_lines(int fd, t_map *map, int width, int height);
int process_map_line(t_map *map, char *line, int y);
t_map *check_map_validity(t_map *map);
t_map *check_map_walls(t_map *map);

void init_map(t_map *map);
void load_xpm_images(t_map *map);
void render_map(t_map *map);
int handle_input(int keycode, t_map *map);
int get_map_dimensions(int fd, int *width, int *height);
void update_player_position(t_map *map, int new_x, int new_y);

void free_map(t_map *map);
#endif