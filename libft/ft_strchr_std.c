/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr_std.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-bouz <zel-bouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 02:29:53 by zel-bouz          #+#    #+#             */
/*   Updated: 2023/02/21 01:42:15 by zel-bouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strchr_std(const char *s, int c)
{
	char	*str;

	str = (char *)s;
	while (*str && *str != (char)c)
		str++;
	if (*str == (char)c)
		return (str);
	return (NULL);
}
