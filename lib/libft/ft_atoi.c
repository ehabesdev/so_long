/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehabes <ehabes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 00:47:52 by ehabes            #+#    #+#             */
/*   Updated: 2024/10/21 01:10:02 by ehabes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	head;
	int	res;

	res = 0;
	head = 1;
	while (*str == ' ' || (*str > 8 && *str < 14))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
		{
			head = -1;
		}
		str++;
	}
	while (ft_isdigit(*str))
	{
		res = res * 10 + (*str - 48);
		str++;
	}
	return (res * head);
}
