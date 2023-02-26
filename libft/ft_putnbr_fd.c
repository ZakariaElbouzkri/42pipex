/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-bouz <zel-bouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 01:49:51 by zel-bouz          #+#    #+#             */
/*   Updated: 2023/02/21 01:41:56 by zel-bouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	a;

	a = n;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		a *= -1;
	}
	if (a < 10)
		ft_putchar_fd(a + '0', fd);
	else
	{
		ft_putnbr_fd((a / 10), fd);
		ft_putnbr_fd((a % 10), fd);
	}
}
