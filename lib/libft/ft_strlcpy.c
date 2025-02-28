/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehabes <ehabes@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 19:44:24 by ehabes            #+#    #+#             */
/*   Updated: 2024/10/20 20:28:38 by ehabes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	s_len;

	s_len = ft_strlen(src);
	if (size == 0)
		return (s_len);
	while (size > 1 && *src)
	{
		*dst++ = *src++;
		size--;
	}
	*dst = '\0';
	return (s_len);
}
