/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehabes <ehabes@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 20:24:01 by ehabes            #+#    #+#             */
/*   Updated: 2025/03/29 20:24:03 by ehabes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	handle_destination_tile(t_game *game, char destination_char)
{
	if (destination_char == 'C')
	{
		game->map.collectibles--;
		game->map.map[game->player_y][game->player_x] = 'P';
	}
	else if (destination_char == 'E')
	{
		if (game->map.collectibles == 0)
		{
			end_game_text(game);
			exit_game(game);
		}
	}
	else
		game->map.map[game->player_y][game->player_x] = 'P';
}

static int	handle_movement(t_game *game, int new_x, int new_y)
{
	char	destination_char;
	int		old_x;
	int		old_y;

	old_x = game->player_x;
	old_y = game->player_y;
	if (!is_valid_move(&game->map, new_x, new_y))
		return (0);
	destination_char = game->map.map[new_y][new_x];
	if (!(game->map.map[old_y][old_x] == 'E' && game->map.collectibles > 0))
		game->map.map[old_y][old_x] = '0';
	game->player_x = new_x;
	game->player_y = new_y;
	game->moves += 1;
	ft_printf("\rMoves: %u", game->moves);
	handle_destination_tile(game, destination_char);
	draw_map(game);
	return (1);
}

int	key_hook(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		exit_game(game);
	else if (keycode == KEY_W)
		handle_movement(game, game->player_x, game->player_y - 1);
	else if (keycode == KEY_A)
		handle_movement(game, game->player_x - 1, game->player_y);
	else if (keycode == KEY_S)
		handle_movement(game, game->player_x, game->player_y + 1);
	else if (keycode == KEY_D)
		handle_movement(game, game->player_x + 1, game->player_y);
	return (0);
}

int	is_valid_move(t_map *map, int new_x, int new_y)
{
	if (new_x < 0 || new_x >= map->width || new_y < 0 || new_y >= map->height)
		return (0);
	if (map->map[new_y][new_x] == '1')
		return (0);
	return (1);
}

void	find_player_start(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < game->map.height)
	{
		x = 0;
		while (x < game->map.width)
		{
			if (game->map.map[y][x] == 'P')
			{
				game->player_x = x;
				game->player_y = y;
				return ;
			}
			x++;
		}
		y++;
	}
}
