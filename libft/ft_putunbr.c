/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-bouz <zel-bouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 17:33:24 by zel-bouz          #+#    #+#             */
/*   Updated: 2023/02/21 01:42:09 by zel-bouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_putunbr(unsigned int n)
{
	int	len;

	len = 0;
	if (n < 10)
		len += ft_putchar(n + 48);
	else
	{
		len += ft_putunbr((n / 10));
		len += ft_putunbr((n % 10));
	}
	return (len);
}
