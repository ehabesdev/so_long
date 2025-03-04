/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehabes <ehabes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 22:32:16 by ehabes            #+#    #+#             */
/*   Updated: 2024/10/21 22:59:00 by ehabes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*_src;
	unsigned char	*_dest;

	_src = (unsigned char *)src;
	_dest = (unsigned char *)dest;
	if (_src == _dest)
		return (_dest);
	if (_src < _dest && _dest < _src + n)
	{
		_src += n;
		_dest += n;
		while (n--)
			*--_dest = *--_src;
	}
	else
	{
		while (n--)
			*_dest++ = *_src++;
	}
	return (dest);
}
