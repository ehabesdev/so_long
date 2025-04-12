/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehabes <ehabes@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 12:45:55 by ehabes            #+#    #+#             */
/*   Updated: 2025/04/12 13:24:06 by ehabes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	validate_map_file(char *argv)
{
	int		len;
	char	*filename;

	filename = ft_strrchr((const char *)argv, '/');
	if (filename)
		filename++;
	else
		filename = argv;
	len = ft_strlen(filename);
	if (len <= 4 || ft_strncmp(filename + len - 4, ".ber", 4) != 0 \
		|| ft_strncmp(filename, ".ber", 4) == 0)
	{
		error_handler("==Error==\nInvalid map file name");
		exit(0);
	}
}
