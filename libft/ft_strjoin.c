/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-bouz <zel-bouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 18:02:03 by zel-bouz          #+#    #+#             */
/*   Updated: 2023/02/21 01:42:34 by zel-bouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	size_t	len;
	char	*joined;

	if (!s1)
		s1 = ft_strdup("");
	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	joined = malloc((len + 1) * sizeof(char));
	if (!joined)
		return (free(s1), s1 = NULL, NULL);
	i = -1;
	j = 0;
	while (s1[++i])
		joined[i] = s1[i];
	while (s2[j])
		joined[i++] = s2[j++];
	joined[len] = '\0';
	free(s1);
	s1 = NULL;
	return (joined);
}
