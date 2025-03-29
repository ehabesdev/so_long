/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validate_structure.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehabes <ehabes@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 20:24:28 by ehabes            #+#    #+#             */
/*   Updated: 2025/03/29 20:24:29 by ehabes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static int	check_top_bottom_walls(t_map *map);
static int	check_left_right_walls(t_map *map);

int	check_map_walls(t_map *map)
{
	if (!check_top_bottom_walls(map))
		return (0);
	if (!check_left_right_walls(map))
		return (0);
	return (1);
}

static int	check_top_bottom_walls(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->width)
	{
		if (map->map[0][i] != '1')
		{
			error_handler("==Error==\nMissing top wall.");
			return (0);
		}
		if (map->map[map->height - 1][i] != '1')
		{
			error_handler("==Error==\nMissing bottom wall.");
			return (0);
		}
		i++;
	}
	return (1);
}

static int	check_left_right_walls(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->height)
	{
		if (map->map[i][0] != '1')
		{
			error_handler("==Error==\nMissing left wall.");
			return (0);
		}
		if (map->map[i][map->width - 1] != '1')
		{
			error_handler("==Error==\nMissing right wall.");
			return (0);
		}
		i++;
	}
	return (1);
}

int	check_valid_path(t_map *map)
{
	if (map->collectibles < 1)
	{
		error_handler("==Error==\nThere must be at least \
				one object on the map.");
		return (0);
	}
	if (map->exit_count != 1)
	{
		error_handler("==Error==\nThere must be one exit on the map.");
		return (0);
	}
	if (map->player_count != 1)
	{
		error_handler("==Error==\nThere must be one player on the map.");
		return (0);
	}
	return (1);
}

void	free_map(t_map *map)
{
	int	i;

	i = 0;
	if (map && map->map)
	{
		while (i < map->height)
		{
			if (map->map[i])
				free(map->map[i]);
			i++;
		}
		free(map->map);
		map->map = NULL;
	}
}
