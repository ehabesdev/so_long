/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehabes <ehabes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 18:20:54 by ehabes            #+#    #+#             */
/*   Updated: 2024/10/27 18:25:23 by ehabes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_size_itoa(int n)
{
	int		len;
	long	nbr;

	nbr = n;
	len = 0;
	if (nbr < 0)
	{
		len++;
		nbr = -nbr;
	}
	else if (nbr == 0)
		len++;
	while (nbr > 0)
	{
		len++;
		nbr = nbr / 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	long	nbr;

	nbr = n;
	len = ft_size_itoa(n);
	str = malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	str[len--] = '\0';
	if (n < 0)
	{
		str[0] = '-';
		nbr = nbr * -1;
	}
	if (n == 0)
		str[0] = '0';
	while (nbr > 0)
	{
		str[len--] = nbr % 10 + 48;
		nbr = nbr / 10;
	}
	return (str);
}
