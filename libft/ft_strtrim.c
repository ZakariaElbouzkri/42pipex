/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-bouz <zel-bouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 21:22:22 by zel-bouz          #+#    #+#             */
/*   Updated: 2023/02/21 01:42:58 by zel-bouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	check_forward(char c, char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	check_backward(char c, char *set)
{
	int	len;

	len = (int)ft_strlen(set);
	len = len -1;
	while (len >= 0)
	{
		if (set[len] == c)
			return (1);
		len--;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	j = ft_strlen(s1);
	while (check_forward(s1[i], (char *)set))
		i++;
	j--;
	while (check_backward(s1[j], (char *)set))
		j--;
	return (ft_substr(s1, i, j - i + 1));
}
