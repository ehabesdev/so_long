/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehabes <ehabes@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 20:24:17 by ehabes            #+#    #+#             */
/*   Updated: 2025/04/18 00:37:42 by ehabes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
	{
		error_handler("==error==\nUsage: ./so_long <map_file.ber>");
		return (1);
	}
	init_game_struct(&game);
	if (!perform_map_validation(&game, argv[1]))
	{
		free_map(&game.map);
		return (1);
	}
	if (!init_mlx(&game))
	{
		free_map(&game.map);
		return (1);
	}
	if (!load_images(&game))
		exit_game(&game);
	draw_map(&game);
	setup_mlx_hooks(&game);
	mlx_loop(game.mlx);
	return (0);
}
