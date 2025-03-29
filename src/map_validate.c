/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehabes <ehabes@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 20:24:34 by ehabes            #+#    #+#             */
/*   Updated: 2025/03/29 20:37:04 by ehabes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static int	check_map_elements(t_map *map)
{
	if (map->player_count != 1)
	{
		error_handler("==Error==\nMap must contain exactly one player (P).");
		return (0);
	}
	if (map->exit_count != 1)
	{
		error_handler("==Error==\nMap must contain exactly one exit (E).");
		return (0);
	}
	if (map->collectibles < 1)
	{
		error_handler("==Error==\nMap must contain at \
			least one collectible (C).");
		return (0);
	}
	return (1);
}

static int	perform_map_checks(t_map *map, int fd)
{
	close(fd);
	if (!check_map_walls(map))
	{
		error_handler("==Error==\nMap is not surrounded by walls!");
		free_map(map);
		return (0);
	}
	if (!check_map_elements(map))
	{
		free_map(map);
		return (0);
	}
	return (1);
}

int	map_check(t_map *map, char *map_path)
{
	int	fd;

	if (!open_and_check_map(map, map_path, &fd))
		return (0);
	if (!read_map(fd, map))
	{
		close(fd);
		return (0);
	}
	if (!perform_map_checks(map, fd))
		return (0);
	return (1);
}

int	is_valid_char(char c)
{
	if (!(c == '0' || c == '1' || c == 'C' || c == 'E' || c == 'P'))
	{
		error_handler("==Error==\nInvalid char in map.");
		return (0);
	}
	return (1);
}

int	process_line(t_map *map, char *line)
{
	int	col;

	col = 0;
	if ((int)ft_strlen(line) != map->width)
	{
		error_handler("==Error==\nInvalid map: Line lengths \
				are not consistent.");
		return (0);
	}
	while (line[col] != '\0')
	{
		if (!is_valid_char(line[col]))
			return (0);
		if (line[col] == 'C')
			map->collectibles++;
		else if (line[col] == 'E')
			map->exit_count++;
		else if (line[col] == 'P')
			map->player_count++;
		col++;
	}
	return (1);
}
