/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehabes <ehabes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 01:46:32 by ehabes            #+#    #+#             */
/*   Updated: 2024/10/21 02:06:55 by ehabes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t num, size_t size)
{
	size_t	t_size;
	void	*buff;

	t_size = num * size;
	buff = malloc(t_size);
	if (!buff)
		return (NULL);
	ft_memset(buff, '\0', t_size);
	return (buff);
}
