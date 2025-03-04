/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehabes <ehabes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 15:42:40 by ehabes            #+#    #+#             */
/*   Updated: 2024/10/28 22:03:52 by ehabes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	unsigned char	*p;
	size_t			i;

	p = (unsigned char *)str;
	i = 0;
	while (n > i)
	{
		p[i] = (unsigned char)c;
		i++;
	}
	return (str);
}
