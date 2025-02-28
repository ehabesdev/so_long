/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehabes <ehabes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 21:36:06 by ehabes            #+#    #+#             */
/*   Updated: 2024/10/24 14:52:12 by ehabes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_start_index(const char *s1, const char *set)
{
	size_t	start;

	start = 0;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	return (start);
}

static size_t	get_end_index(const char *s1, const char *set)
{
	size_t	end;

	end = ft_strlen(s1) - 1;
	while (end >= 0 && ft_strchr(set, s1[end]))
		end--;
	return (end);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned char	*trimed;
	size_t			len;
	size_t			start;
	size_t			end;
	size_t			ref;

	if (!s1 || !set)
		return (NULL);
	start = get_start_index(s1, set);
	end = get_end_index(s1, set);
	if (start >= end)
		return (ft_strdup(""));
	len = end - start + 1;
	trimed = (unsigned char *)malloc(len + 1);
	if (!trimed)
		return (NULL);
	ref = 0;
	while (start <= end)
	{
		trimed[ref++] = s1[start++];
	}
	trimed[ref] = '\0';
	return ((char *)trimed);
}
