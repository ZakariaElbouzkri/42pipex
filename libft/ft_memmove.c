/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-bouz <zel-bouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 14:06:54 by zel-bouz          #+#    #+#             */
/*   Updated: 2023/02/21 01:41:36 by zel-bouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*d;
	char	*s;
	char	*last_d;
	char	*last_s;

	d = (char *)dst;
	s = (char *)src;
	last_d = d + (len - 1);
	last_s = s + (len - 1);
	if (!src && !dst)
		return (NULL);
	if (src == dst)
		return (dst);
	else if (d > s)
	{
		while (len--)
			*last_d-- = *last_s--;
	}
	else
	{
		while (len--)
			*d++ = *s++;
	}
	return (dst);
}
