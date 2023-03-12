/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-bouz <zel-bouz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 16:20:32 by zel-bouz          #+#    #+#             */
/*   Updated: 2023/03/12 09:59:24 by zel-bouz         ###   ########.fr       */
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

void	clear_vars(t_vrs *vrs, int	er)
{
	char	*err[5];

	err[0] = "Error : invalid input file\n";
	err[1] = "Error : command not found\n";
	err[2] = "Error : path not found \n";
	err[3] = "Error : pip or fork error \n";
	err[4] = "Error : execve faild \n";

	if (vrs->path)
		free_dup(vrs->path);
	if (vrs->cmd_args1)
		free_dup(vrs->cmd_args1);
	if (vrs->cmd_args2)
		free_dup(vrs->cmd_args2);
	if (er)
		ft_puterror(err[er - 1]);
	else if (er == -1)
		exit(0);
}
