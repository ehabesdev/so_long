/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehabes <ehabes@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 20:24:11 by ehabes            #+#    #+#             */
/*   Updated: 2025/03/29 20:24:13 by ehabes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	draw_map(t_game *game)
{
	int	y;
	int	x;

	y = -1;
	while (++y < game->map.height)
	{
		x = -1;
		while (++x < game->map.width)
		{
			mlx_put_image_to_window(game->mlx, game->win, \
					game->floor.img, x * TILE_SIZE, y * TILE_SIZE);
			if (game->map.map[y][x] == '1')
				mlx_put_image_to_window(game->mlx, game->win, \
						game->wall.img, x * TILE_SIZE, y * TILE_SIZE);
			else if (game->map.map[y][x] == 'C')
				mlx_put_image_to_window(game->mlx, game->win, \
						game->collectible.img, x * TILE_SIZE, y * TILE_SIZE);
			else if (game->map.map[y][x] == 'E')
				mlx_put_image_to_window(game->mlx, game->win, \
						game->exit.img, x * TILE_SIZE, y * TILE_SIZE);
		}
	}
	mlx_put_image_to_window(game->mlx, game->win, game->player.img, \
		game->player_x * TILE_SIZE, game->player_y * TILE_SIZE);
	return (1);
}

int	render_frame(t_game *game)
{
	draw_map(game);
	return (0);
}

int	exit_game(t_game *game)
{
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->wall.img)
		mlx_destroy_image(game->mlx, game->wall.img);
	if (game->floor.img)
		mlx_destroy_image(game->mlx, game->floor.img);
	if (game->player.img)
		mlx_destroy_image(game->mlx, game->player.img);
	if (game->collectible.img)
		mlx_destroy_image(game->mlx, game->collectible.img);
	if (game->exit.img)
		mlx_destroy_image(game->mlx, game->exit.img);
	free_map(&game->map);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	exit(0);
}
