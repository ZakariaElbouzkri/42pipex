/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-bouz <zel-bouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 01:49:51 by zel-bouz          #+#    #+#             */
/*   Updated: 2023/02/21 01:41:58 by zel-bouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_putnbr(int n)
{
	unsigned int	a;
	int				len;

	len = 0;
	a = n;
	if (n < 0)
	{
		len += ft_putchar('-');
		a *= -1;
	}
	if (a < 10)
		len += ft_putchar(a + '0');
	else
	{
		len += ft_putnbr(a / 10);
		len += ft_putnbr(a % 10);
	}
	return (len);
}
