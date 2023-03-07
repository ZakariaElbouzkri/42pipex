/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-bouz <zel-bouz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 16:21:23 by zel-bouz          #+#    #+#             */
/*   Updated: 2023/03/07 05:20:13 by zel-bouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char	*get_binary_path(char *cmd, char **path)
{
	char	*bin;
	int		i;

	i = 0;
	bin = NULL;
	while (path[i])
	{
		bin = ft_strjoin_std(path[i], cmd);
		if (!access(bin, X_OK))
			return (bin);
		else if (!access(cmd, X_OK))
			return (cmd);
		else
		{
			free(bin);
			bin = NULL;
		}
		i++;
	}
	free(bin);
	return (bin);
}

char	**parse_cmd(char	*cmd, t_vrs *vars)
{
	char	**args;
	int		args_num;

	args = NULL;
	args_num = count_words(cmd, ' ');
	if (args_num >= 2)
		args = ft_split(cmd, ' ');
	else if (args_num == 1)
	{
		args = malloc(sizeof(char *) * 3);
		args[0] = ft_strdup(cmd);
		args[1] = NULL;
		args[2] = NULL;
	}
	if (!args)
		return (NULL);
	args[0] = get_binary_path(args[0], vars->path);
	if (!args[0])
		ft_puterror("ERROR\n");
	return (args);
}
