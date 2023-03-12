/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-bouz <zel-bouz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 15:21:23 by zel-bouz          #+#    #+#             */
/*   Updated: 2023/03/12 09:51:51 by zel-bouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char	**get_path(char **env)
{
	int		i;
	char	*env_path;
	char	**path;

	i = 0;
	env_path = NULL;
	while (env[i])
	{
		if (ft_strnstr(env[i], "PATH=", 5))
		{
			env_path = &env[i][5];
			break ;
		}
		i++;
	}
	if (!env_path)
		return (NULL);
	path = ft_split(env_path, ':');
	if (!path)
		return (NULL);
	return (path);
}

void	parse_env(t_vrs *vrs)
{
	if (!ft_strcmp(vrs->av[2], "") || !ft_strcmp(vrs->av[3], ""))
		clear_vars(vrs, 2);
	vrs->path = get_path(vrs->env);
	if (!vrs->path)
		clear_vars(vrs, 3);
	add_slash(vrs->path);
	vrs->cmd_args1 = parse_cmd(vrs->av[2], vrs);
	vrs->cmd_args2 = parse_cmd(vrs->av[3], vrs);
	free_dup(vrs->path);
	vrs->path = NULL;
}
