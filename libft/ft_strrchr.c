/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-bouz <zel-bouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 02:24:41 by zel-bouz          #+#    #+#             */
/*   Updated: 2023/02/21 01:42:56 by zel-bouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;

	i = ft_strlen(s);
	while ((i + 1) > 0)
	{
		if ((char)s[i] == (char)c)
			return ((char *) &s[i]);
		i--;
	}
	if (c == 0)
		return ((char *) &s[i]);
	return (NULL);
}
