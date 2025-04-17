/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehabes <ehabes@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 00:29:12 by ehabes            #+#    #+#             */
/*   Updated: 2025/04/18 00:32:07 by ehabes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	perform_map_validation(t_game *game, char *map_path)
{
	if (!map_check(&game->map, map_path))
		return (0);
	find_player_start(game);
	if (!validate_map_path(game))
	{
		error_handler("==Error==\nMap has no valid path \
			(all collectibles and/or exit are unreachable)");
		return (0);
	}
	return (1);
}

void	setup_mlx_hooks(t_game *game)
{
	mlx_key_hook(game->win, key_hook, game);
	mlx_hook(game->win, 17, (1L << 17), exit_game, game);
	mlx_expose_hook(game->win, render_frame, game);
}
