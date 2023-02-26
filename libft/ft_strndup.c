/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-bouz <zel-bouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 19:38:43 by zel-bouz          #+#    #+#             */
/*   Updated: 2023/02/21 01:42:50 by zel-bouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strndup(const char *s1, size_t len)
{
	char	*ptr;
	size_t	i;

	i = 0;
	if (len >= ft_strlen(s1))
		return (ft_strdup(s1));
	ptr = (char *)malloc((len + 1) * sizeof(char *));
	if (!ptr)
		return (NULL);
	while (s1[i] && len--)
	{
		ptr[i] = s1[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
