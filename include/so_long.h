/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehabes <ehabes@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 20:23:15 by ehabes            #+#    #+#             */
/*   Updated: 2025/04/18 01:15:42 by ehabes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

# include "../libs/libft/libft.h"
# include "../libs/ft_printf/libftprintf.h"
# include "../libs/get_next_line/get_next_line.h"
# include "../libs/minilibx/mlx.h"

# define TILE_SIZE 32
# define INT_MAX 2147483647

# define KEY_ESC 0xff1b
# define KEY_W 0x77
# define KEY_A 0x61
# define KEY_S 0x73
# define KEY_D 0x64

typedef struct s_map
{
	char	**map;
	int		width;
	int		height;
	int		collectibles;
	int		exit_count;
	int		player_count;
	char	*path;
}	t_map;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}	t_img;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	t_map	map;
	t_img	player;
	t_img	wall;
	t_img	floor;
	t_img	collectible;
	t_img	exit;
	int		exit_x;
	int		player_x;
	int		player_y;
	int		moves;
}	t_game;

typedef struct s_point
{
	int	w;
	int	h;
}	t_point;

int		map_check(t_map *map, char *map_path);
int		is_valid_char(char c);
int		process_line(t_map *map, char *line);

int		read_map(int fd, t_map *map);

int		check_map_walls(t_map *map);
void	free_map(t_map *map);

void	error_handler(char *message);
void	end_game_text(t_game *game);

int		key_hook(int keycode, t_game *game);
int		is_valid_move(t_map *map, int x, int y);
void	find_player_start(t_game *game);

int		draw_map(t_game *game);
int		render_frame(t_game *game);
int		exit_game(t_game *game);

void	init_game_struct(t_game *game);
int		init_mlx(t_game *game);
int		load_images(t_game *game);
int		open_and_check_map(t_map *m, char *p, int *fd);

void	validate_map_file(char *argv);

int		validate_map_path(t_game *game);

int		perform_map_validation(t_game *game, char *map_path);
void	setup_mlx_hooks(t_game *game);

#endif
