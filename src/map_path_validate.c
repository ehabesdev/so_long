/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_path_validate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehabes <ehabes@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 23:11:52 by ehabes            #+#    #+#             */
/*   Updated: 2025/04/18 00:53:00 by ehabes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	free_map_copy(char **map_copy, int height)
{
	int	i;

	if (!map_copy)
		return ;
	i = 0;
	while (i < height)
	{
		if (map_copy[i])
			free(map_copy[i]);
		i++;
	}
	free(map_copy);
}

char	**duplicate_map(t_map *map_info)
{
	char	**map_copy;
	int		i;
	int		height;
	int		width;

	height = map_info->height;
	width = map_info->width;
	map_copy = (char **)malloc(sizeof(char *) * height);
	if (!map_copy)
		return (NULL);
	i = 0;
	while (i < height)
	{
		map_copy[i] = (char *)malloc(sizeof(char) * (width + 1));
		if (!map_copy[i])
		{
			free_map_copy(map_copy, i);
			return (NULL);
		}
		ft_memcpy(map_copy[i], map_info->map[i], width);
		map_copy[i][width] = '\0';
		i++;
	}
	return (map_copy);
}

static void	flood_fill(char **map_copy, t_point map, int x, int y)
{
	if (y < 0 || y >= map.h || x < 0 || x >= map.w \
		|| map_copy[y][x] == '1' || map_copy[y][x] == 'F')
		return ;
	map_copy[y][x] = 'F';
	flood_fill(map_copy, map, x + 1, y);
	flood_fill(map_copy, map, x - 1, y);
	flood_fill(map_copy, map, x, y + 1);
	flood_fill(map_copy, map, x, y - 1);
}

static int	check_reachability(t_game *game, char **map_copy)
{
	int	x;
	int	y;
	int	reachable_c;
	int	exit_reach;

	reachable_c = 0;
	exit_reach = 0;
	y = -1;
	while (++y < game->map.height)
	{
		x = -1;
		while (++x < game->map.width)
		{
			if (game->map.map[y][x] == 'C' && map_copy[y][x] == 'F')
				reachable_c++;
			else if (game->map.map[y][x] == 'E' && map_copy[y][x] == 'F')
				exit_reach = 1;
		}
	}
	return (exit_reach == 1 && reachable_c == game->map.collectibles);
}

int	validate_map_path(t_game *game)
{
	char	**map_copy;
	int		is_valid;
	t_point	map;

	is_valid = 0;
	map_copy = duplicate_map(&game->map);
	if (!map_copy)
	{
		error_handler("==Error==\nMap has no valid path \
			(not all collectibles and/or exit are reachable)");
		return (0);
	}
	map.w = game->map.width;
	map.h = game->map.height;
	flood_fill(map_copy, map, game->player_x,
		game->player_y);
	is_valid = check_reachability(game, map_copy);
	free_map_copy(map_copy, game->map.height);
	return (is_valid);
}
