/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehabes <ehabes@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 20:24:43 by ehabes            #+#    #+#             */
/*   Updated: 2025/04/20 22:38:03 by ehabes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	init_game_struct(t_game *game)
{
	game->mlx = NULL;
	game->win = NULL;
	game->moves = 0;
	game->map.map = NULL;
	game->map.width = 0;
	game->map.height = 0;
	game->map.collectibles = 0;
	game->map.exit_count = 0;
	game->map.player_count = 0;
	game->map.path = NULL;
	game->wall.img = NULL;
	game->floor.img = NULL;
	game->player.img = NULL;
	game->collectible.img = NULL;
	game->exit.img = NULL;
	game->player_x = -1;
	game->player_y = -1;
	game->exit_x = -1;
}

int	init_mlx(t_game *game)
{
	int	window_width;
	int	window_height;

	game->mlx = mlx_init();
	if (game->mlx == NULL)
	{
		error_handler("==Error==\nFailed to initialize MiniLibX.");
		return (0);
	}
	window_width = game->map.width * TILE_SIZE;
	window_height = game->map.height * TILE_SIZE;
	game->win = mlx_new_window(game->mlx, window_width, window_height,
			"So Long");
	if (game->win == NULL)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		error_handler("==Error==\nFailed to create window.");
		return (0);
	}
	return (1);
}

static int	load_single_image(t_game *game, t_img *img, char *path)
{
	img->img = mlx_xpm_file_to_image(game->mlx, path, &img->width,
			&img->height);
	if (!img->img)
	{
		ft_printf("==Error==\nFailed to load image: %s\n", path);
		return (0);
	}
	return (1);
}

int	load_images(t_game *game)
{
	if (!load_single_image(game, &game->wall, "assets/wall.xpm"))
		return (0);
	if (!load_single_image(game, &game->floor, "assets/floor.xpm"))
		return (0);
	if (!load_single_image(game, &game->player, "assets/player.xpm"))
		return (0);
	if (!load_single_image(game, &game->collectible, "assets/collectible.xpm"))
		return (0);
	if (!load_single_image(game, &game->exit, "assets/exit.xpm"))
		return (0);
	return (1);
}

int	open_and_check_map(t_map *map, char *map_path, int *fd)
{
	map->path = map_path;
	validate_map_file(map_path);
	*fd = open(map_path, O_RDONLY);
	if (*fd == -1)
	{
		error_handler("==Error==\nFile cannot be opened");
		return (0);
	}
	return (1);
}
