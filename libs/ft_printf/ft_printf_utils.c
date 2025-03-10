/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehabes <ehabes@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 09:22:56 by ehabes            #+#    #+#             */
/*   Updated: 2024/12/04 14:58:14 by ehabes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdint.h>

int	ft_putptr(void *ptr)
{
	uintptr_t	address;
	char		*hex_digit;
	int			len;

	len = 0;
	hex_digit = "0123456789abcdef";
	address = (uintptr_t)ptr;
	if (address >= 16)
		len += ft_putptr((void *)(address / 16));
	return (len + ft_putchr(hex_digit[address % 16]));
}

int	ft_print_format(va_list args, char format)
{
	if (format == 'c')
		return (ft_putchr(va_arg(args, int)));
	else if (format == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (format == 'd' || format == 'i')
		return (ft_putnbr(va_arg(args, int)));
	else if (format == 'u')
		return (ft_putunbr(va_arg(args, unsigned int)));
	else if (format == 'x')
		return (ft_puthex(va_arg(args, unsigned int), format));
	else if (format == 'X')
		return (ft_puthex(va_arg(args, unsigned int), format));
	else if (format == 'p')
		return (write(1, "0x", 2) + ft_putptr(va_arg(args, void *)));
	else if (format == '%')
		return (ft_putchr('%'));
	return (0);
}

int	ft_puthex(unsigned int n, unsigned char x)
{
	char	*hex_digits;
	char	buffer[11];
	int		i;
	int		count;

	if (x == 'x')
		hex_digits = "0123456789abcdef";
	else
		hex_digits = "0123456789ABCDEF";
	if (n == 0)
	{
		ft_putchr('0');
		return (1);
	}
	i = 0;
	count = 0;
	while (n > 0)
	{
		buffer[i++] = hex_digits[n % 16];
		n /= 16;
	}
	while (--i >= 0)
		count += ft_putchr(buffer[i]);
	return (count);
}

int	ft_putunbr(unsigned int n)
{
	int	count;

	count = 0;
	if (n >= 10)
		count += ft_putunbr(n / 10);
	count += ft_putchr((n % 10) + '0');
	return (count);
}

int	ft_putnbr(int n)
{
	long		num;
	int			count;

	count = 0;
	num = n;
	if (n < 0)
	{
		count += ft_putchr('-');
		num = -num;
	}
	if (num > 9)
	{
		count += ft_putnbr(num / 10);
	}
	else
		count += ft_putchr((num % 10) + '0');
	return (count);
}
