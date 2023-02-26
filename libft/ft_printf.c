/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-bouz <zel-bouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 02:21:55 by zel-bouz          #+#    #+#             */
/*   Updated: 2023/02/21 01:41:41 by zel-bouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	ft_is_format(char c)
{
	if ((c == 'd') || (c == 's') || (c == 'i') || (c == 'p') || (c == '%'))
		return (1);
	else if ((c == 'x') || (c == 'X') || (c == 'u') || (c == 'c'))
		return (1);
	return (0);
}

static int	ft_check(va_list args, char c)
{
	int	len;

	len = 0;
	if (c == 'c')
		len += ft_putchar(va_arg(args, int));
	else if (c == 'd' || (c == 'i'))
		len += ft_putnbr(va_arg(args, int));
	else if (c == 's')
		len += ft_putstr(va_arg(args, char *));
	else if ((c == 'x') || (c == 'X'))
		len += ft_puthexa(va_arg(args, unsigned int), c);
	else if (c == 'p')
		len += ft_putptr(va_arg(args, unsigned long));
	else if (c == 'u')
		len += ft_putunbr(va_arg(args, unsigned int));
	else if (c == '%')
		len += ft_putchar('%');
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		len;
	int		i;

	len = 0;
	i = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			if (ft_is_format(format[i + 1]))
				len += ft_check(args, format[i + 1]);
			else
				len += ft_putchar(format[i + 1]);
			i++;
		}
		else
			len += ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (len);
}
