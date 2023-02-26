/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-bouz <zel-bouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 16:54:35 by zel-bouz          #+#    #+#             */
/*   Updated: 2023/02/21 01:41:53 by zel-bouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_puthexa(unsigned long n, char c)
{
	char	*str;
	int		len;

	len = 0;
	if (c == 'x')
		str = "0123456789abcdef";
	else
		str = "0123456789ABCDEF";
	if (n < 16)
		len += ft_putchar(str[n]);
	else
	{
		len += ft_puthexa(n / 16, c);
		len += ft_puthexa(n % 16, c);
	}
	return (len);
}
