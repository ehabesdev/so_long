/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehabes <ehabes@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 13:19:23 by ehabes            #+#    #+#             */
/*   Updated: 2025/04/12 13:12:21 by ehabes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*p;
	int		i;
	int		last;

	p = (char *)s;
	i = 0;
	last = -1;
	if ((unsigned char)c == 0)
		return (p + ft_strlen(p));
	while (s[i] != '\0')
	{
		if (s[i] == (unsigned char)c)
		{
			last = i;
		}
		i++;
	}
	if (last != -1)
		return (p + last);
	else
		return (0);
}
