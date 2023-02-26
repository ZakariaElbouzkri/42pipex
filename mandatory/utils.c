/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-bouz <zel-bouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 16:20:32 by zel-bouz          #+#    #+#             */
/*   Updated: 2023/02/26 17:45:15 by zel-bouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	add_slash(char	**path)
{
	int	i;

	i = 0;
	while (path[i])
	{
		if (path[i][ft_strlen(path[i]) - 1] != '/')
			path[i] = ft_strjoin(path[i], "/");
		i++;
	}
}

void	free_dup(char **dup)
{
	int	i;

	i = 0;
	while (dup[i])
	{
		free(dup[i]);
		dup[i++] = NULL;
	}
	free(dup);
}

void	clear_vars(t_vrs *vrs)
{
	if (vrs->path)
		free_dup(vrs->path);
	if (vrs->cmd_args1)
		free_dup(vrs->cmd_args1);
	if (vrs->cmd_args2)
		free_dup(vrs->cmd_args2);
}
