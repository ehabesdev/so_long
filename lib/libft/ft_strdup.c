/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehabes <ehabes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 20:48:47 by ehabes            #+#    #+#             */
/*   Updated: 2024/10/24 14:54:37 by ehabes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*ref;
	size_t	t_size;

	if (!s)
		return (NULL);
	t_size = ft_strlen(s) + 1;
	ref = (char *)malloc(t_size);
	if (!ref)
		return (NULL);
	ft_memcpy(ref, s, t_size);
	return (ref);
}
