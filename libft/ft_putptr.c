/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-bouz <zel-bouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 17:28:23 by zel-bouz          #+#    #+#             */
/*   Updated: 2023/02/21 01:42:00 by zel-bouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_putptr(unsigned long n)
{
	int	len;

	len = 0;
	len += ft_putstr("0x");
	len += ft_puthexa(n, 'x');
	return (len);
}
