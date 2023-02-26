/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-bouz <zel-bouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 00:10:51 by zel-bouz          #+#    #+#             */
/*   Updated: 2023/02/21 01:41:24 by zel-bouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	nbr_len(int a)
{
	int	count;

	count = 0;
	if (a < 0)
		count++;
	while (a)
	{
		count++;
		a = a / 10;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char	*nbr;
	int		len;
	long	a;

	a = n;
	len = nbr_len(n);
	if (n == 0)
		return (ft_strdup("0"));
	nbr = (char *)malloc((len + 1) * sizeof(char));
	if (!nbr)
		return (NULL);
	if (a < 0)
	{
		nbr[0] = '-';
		a *= -1;
	}
	nbr[len--] = '\0';
	while (a)
	{
		nbr[len] = (a % 10) + '0';
		len--;
		a = a / 10;
	}
	return (nbr);
}
