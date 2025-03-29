/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehabes <ehabes@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 20:23:15 by ehabes            #+#    #+#             */
/*   Updated: 2025/03/29 20:23:18 by ehabes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

# include "../libs/libft/libft.h"                   // libft library
# include "../libs/ft_printf/libftprintf.h"          // ft_printf library
# include "../libs/get_next_line/get_next_line.h"    // get_next_line library
# include "../libs/minilibx/mlx.h"                   // MiniLibX library

# define TILE_SIZE 32   // Size of one tile in pixels

# define KEY_ESC 0xff1b
# define KEY_W 0x77
# define KEY_A 0x61
# define KEY_S 0x73
# define KEY_D 0x64

// Structure for map data
typedef struct s_map
{
	char	**map;	// 2D array holding the map layout
	int		width;	// Map width (in tiles)
	int		height;	// Map height (in tiles)
	int		collectibles;	// Number of collectibles ('C')
	int		exit_count;	// Number of exits ('E') (should be 1)
	int		player_count;	// Number of players ('P') (should be 1)
	char	*path;	// Path to the map file
}	t_map;

// Structure for image data
typedef struct s_img
{
	void	*img;	// Pointer to the image instance (from mlx)
	char	*addr;	// Pointer to the image pixel data
	int		bits_per_pixel;	// Color depth
	int		line_length;	// Size of one line in bytes
	int		endian;	// Endianness (byte order)
	int		width;	// Image width in pixels
	int		height;	// Image height in pixels
}	t_img;

// Main game structure
typedef struct s_game
{
	void	*mlx;	// MLX connection pointer
	void	*win;	// Window pointer
	t_map	map;	// Map data structure
	t_img	player;	// Player image
	t_img	wall;	// Wall image
	t_img	floor;	// Floor image
	t_img	collectible;	// Collectible image
	t_img	exit;	// Exit image
	int		exit_x;	// Exit X coordinate (tile-based)
	int		exit_y;	// Exit Y coordinate (tile-based)
	int		player_x;	// Player's X coordinate (tile-based)
	int		player_y;	// Player's Y coordinate (tile-based)
	int		moves;	// Number of player moves
}	t_game;

// map_validate.c
int		map_check(t_map *map, char *map_path); // Check map file and contents.
int		is_valid_char(char c);	// Check if char is valid for map.
int		process_line(t_map *map, char *line);	// Process a single map line.

// map_read.c
int		read_map(int fd, t_map *map);	// Read map from fd into struct.

// map_validate_structure.c
int		check_map_walls(t_map *map);	// Check if map is enclosed.
int		check_valid_path(t_map *map);	// Check P, E, C counts validity.
void	free_map(t_map *map);	// Free allocated map memory.

// output.c (or messaging / error)
void	error_handler(char *message);	// Print error message.
void	end_game_text(t_game *game);	// Print game completion message.

// game_manager.c (or gameplay)
int		key_hook(int keycode, t_game *game);	// Handle keyboard events.
int		is_valid_move(t_map *map, int x, int y);	// Check if move is valid.
void	find_player_start(t_game *game);	// Find player start position.

// graphics.c
int		draw_map(t_game *game);	// Draw map and elements.
int		render_frame(t_game *game);	// Handle window redraw events.
int		exit_game(t_game *game);	// Clean up and exit game.

// setup.c
void	init_game_struct(t_game *game);	// Initialize t_game members.
int		init_graphics(t_game *game);	// Initialize MLX and window.
int		load_images(t_game *game);	// Load all XPM images.
int		open_and_check_map(t_map *m, char *p, int *fd);	// Open map, init t_map.

#endif
