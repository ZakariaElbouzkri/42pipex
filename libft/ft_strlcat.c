/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-bouz <zel-bouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 02:28:51 by zel-bouz          #+#    #+#             */
/*   Updated: 2023/02/21 01:42:36 by zel-bouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	dst_len;
	size_t	src_len;

	if (!size)
		return (ft_strlen(src));
	dst_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	i = 0;
	if (size <= dst_len)
		return (src_len + size);
	while (src[i] && i + dst_len < size - 1)
	{
		dest[i + dst_len] = src[i];
		i++;
	}
	dest[i + dst_len] = '\0';
	return (dst_len + src_len);
}
