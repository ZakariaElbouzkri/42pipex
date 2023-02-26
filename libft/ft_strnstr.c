/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-bouz <zel-bouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 21:15:19 by zel-bouz          #+#    #+#             */
/*   Updated: 2023/02/21 01:42:53 by zel-bouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	c;
	size_t	n_len;
	char	*str;

	if (!haystack && !len)
		return (NULL);
	i = 0;
	str = (char *)haystack;
	n_len = ft_strlen(needle);
	if (!n_len || haystack == needle)
		return (str);
	while (str[i] && i < len)
	{
		c = 0;
		while (str[i + c] && needle[c]
			&& str[i + c] == needle[c] && i + c < len)
			c++;
		if (c == n_len)
			return (str + i);
		i++;
	}
	return (0);
}
