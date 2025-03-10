/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehabes <ehabes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 21:17:24 by ehabes            #+#    #+#             */
/*   Updated: 2024/10/28 21:47:54 by ehabes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*nova;

	if (!s1 || !s2)
		return (NULL);
	nova = malloc(ft_strlen(s1) + ft_strlen(s2) * sizeof(char) + 1);
	if (!nova)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		nova[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		nova[i] = s2[j];
		j++;
		i++;
	}
	nova[i] = '\0';
	return (nova);
}
