/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehabes <ehabes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 13:43:48 by ehabes            #+#    #+#             */
/*   Updated: 2024/10/21 23:00:43 by ehabes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*ref;
	unsigned char	*dst;

	if (src == NULL || dest == NULL)
		return (NULL);
	ref = (unsigned char *)src;
	dst = (unsigned char *)dest;
	i = 0;
	while (i < n)
	{
		dst[i] = ref[i];
		i++;
	}
	return (dst);
}
