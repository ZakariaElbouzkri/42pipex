/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-bouz <zel-bouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 09:53:21 by zel-bouz          #+#    #+#             */
/*   Updated: 2023/02/21 01:43:14 by zel-bouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static size_t	ft_strlen2(const char *s)
{
	size_t	len;

	len = 0;
	if (!s)
		return (0);
	while (s[len] != '\0')
		len++;
	return (len);
}

static char	*ft_get_line(char *saved)
{
	int		i;
	char	*line;

	i = 0;
	if (!saved[i])
		return (NULL);
	while (saved[i] && saved[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (saved[i] && saved[i] != '\n')
	{
		line[i] = saved[i];
		i++;
	}
	if (saved[i] == '\n')
	{
		line[i] = saved[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

static char	*ft_get_left_str(char *saved)
{
	int		i;
	int		j;
	char	*left_str;

	i = 0;
	while (saved[i] && saved[i] != '\n')
		i++;
	if (!saved[i])
	{
		free(saved);
		saved = NULL;
		return (NULL);
	}
	left_str = (char *)malloc(sizeof(char) * (ft_strlen2(saved) - i + 1));
	if (!left_str)
		return (NULL);
	i++;
	j = 0;
	while (saved[i])
		left_str[j++] = saved[i++];
	left_str[j] = '\0';
	return (free(saved), saved = NULL, left_str);
}

static char	*ft_read_from_file(int fd, char *saved)
{
	char	*buff;
	int		read_bytes;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	read_bytes = 1;
	while (!ft_strchr(saved, '\n') && read_bytes != 0)
	{
		read_bytes = read(fd, buff, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			if (saved)
			{
				free(saved);
				saved = NULL;
			}
			return (free(buff), buff = NULL, NULL);
		}
		buff[read_bytes] = '\0';
		saved = ft_strjoin(saved, buff);
	}
	free(buff);
	buff = NULL;
	return (saved);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*saved[OPEN_MAX];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	saved[fd] = ft_read_from_file(fd, saved[fd]);
	if (!saved[fd])
		return (NULL);
	line = ft_get_line(saved[fd]);
	saved[fd] = ft_get_left_str(saved[fd]);
	return (line);
}
