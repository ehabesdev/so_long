/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehabes <ehabes@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 20:24:17 by ehabes            #+#    #+#             */
/*   Updated: 2025/03/29 20:24:18 by ehabes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	init_game_struct(&game);
	game.moves = 0;
	if (argc != 2)
	{
		error_handler("Usage: ./so_long <map_file.ber>");
		return (1);
	}
	if (!map_check(&game.map, argv[1]))
		return (1);
	find_player_start(&game);
	if (!init_graphics(&game))
	{
		free_map(&game.map);
		return (1);
	}
	if (!load_images(&game))
		exit_game(&game);
	draw_map(&game);
	mlx_key_hook(game.win, key_hook, &game);
	mlx_hook(game.win, 17, 0, exit_game, &game);
	mlx_expose_hook(game.win, render_frame, &game);
	mlx_loop(game.mlx);
	return (0);
}
