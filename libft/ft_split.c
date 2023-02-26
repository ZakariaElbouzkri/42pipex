/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-bouz <zel-bouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 19:02:14 by zel-bouz          #+#    #+#             */
/*   Updated: 2023/02/25 16:26:38 by zel-bouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	count_words(char const *s, char c)
{
	int	i;
	int	trigger;

	trigger = -1;
	i = 0;
	while (*s)
	{
		if (*s != c && trigger < 0)
		{
			i++;
			trigger = 1;
		}
		else if (*s == c && trigger > 0)
			trigger = -1;
		s++;
	}
	return (i);
}

static int	word_len(char const *s, char c)
{
	int	len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	return (len);
}

static char	**ft_free(char **ptr, int size)
{
	int	i;

	i = 0;
	while (i < size)
		free(ptr[i++]);
	free(ptr);
	ptr = NULL;
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**p;
	int		size;
	int		i;
	int		j;

	if (!s)
		return (NULL);
	size = count_words(s, c);
	p = (char **) malloc(sizeof(char *) * (size + 1));
	if (!p)
		return (NULL);
	i = 0;
	while (i < size)
	{
		while (*s && *s == c)
			s++;
		p[i] = (char *)malloc(sizeof(char) * (word_len(s, c) + 1));
		if (!p[i])
			return (ft_free(p, i));
		j = 0;
		while (*s && *s != c)
			p[i][j++] = *s++;
		p[i++][j] = '\0';
	}
	return (p[i] = NULL, p);
}
