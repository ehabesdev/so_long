/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehabes <ehabes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 18:18:58 by ehabes            #+#    #+#             */
/*   Updated: 2024/10/28 21:25:36 by ehabes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(const char *str, char delimiter)
{
	int	i;
	int	word_count;

	i = 0;
	word_count = 0;
	while (str[i])
	{
		while (str[i] && str[i] == delimiter)
			i++;
		if (str[i])
			word_count++;
		while (str[i] && str[i] != delimiter)
			i++;
	}
	return (word_count);
}

static int	ft_word_length(const char *str, char delimiter)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != delimiter)
	{
		i++;
	}
	return (i);
}

static char	*ft_extract_word(const char *str, char delimiter)
{
	size_t	len;
	char	*word;

	len = ft_word_length(str, delimiter);
	word = (char *)malloc((len + 1) * sizeof(char));
	ft_strlcpy(word, str, len + 1);
	return (word);
}

static char	**fd_memory_allocation_words(char **word_array, const char *s,
		int word_count, char delimiter)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < word_count && s[i])
	{
		while (s[i] && s[i] == delimiter)
			i++;
		if (s[i])
		{
			word_array[j] = ft_extract_word((s + i), delimiter);
			j++;
		}
		while (s[i] && s[i] != delimiter)
		{
			i++;
		}
	}
	word_array[j] = 0;
	return (word_array);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	int		count;

	if (!s)
		return (NULL);
	count = ft_count_words(s, c);
	array = (char **)malloc((count + 1) * sizeof(char *));
	if (!array)
		return (NULL);
	array = fd_memory_allocation_words(array, s, count, c);
	return (array);
}
