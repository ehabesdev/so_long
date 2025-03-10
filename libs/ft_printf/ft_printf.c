/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehabes <ehabes@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 22:46:52 by ehabes            #+#    #+#             */
/*   Updated: 2024/12/03 13:19:27 by ehabes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <unistd.h>

int	ft_putchr(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *str)
{
	int	count;

	if (!str)
	{
		ft_putstr("(null)");
		return (6);
	}
	count = 0;
	while (*str)
	{
		if (ft_putchr(*str++) == -1)
			return (-1);
		count++;
	}
	return (count);
}

int	ft_printf(const char *format, ...)
{
	int			count;
	va_list		args;

	va_start(args, format);
	count = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			count += ft_print_format(args, *format);
		}
		else
		{
			count += ft_putchr(*format);
		}
		format++;
	}
	va_end(args);
	return (count);
}
