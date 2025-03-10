/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehabes <ehabes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 12:48:33 by ehabes            #+#    #+#             */
/*   Updated: 2024/10/28 21:43:05 by ehabes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(char *s, int c)
{
	char	*p;
	int		find;

	find = 0;
	p = (char *)s;
	if (*p == (unsigned char)c)
		find = 1;
	else
	{
		while (*p != (unsigned char)c && *p != '\0')
		{
			p++;
			if (*p == (unsigned char)c)
				find = 1;
		}
	}
	if (find == 1)
		return (p);
	else
		return (0);
}
