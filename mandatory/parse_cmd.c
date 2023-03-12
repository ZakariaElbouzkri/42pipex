/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-bouz <zel-bouz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 16:21:23 by zel-bouz          #+#    #+#             */
/*   Updated: 2023/03/12 10:29:21 by zel-bouz         ###   ########.fr       */
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
		bin = ft_strjoin(ft_strdup(path[i]), cmd);
		if (!access(bin, X_OK))
			return (free(cmd), cmd = NULL, bin);
		else if (!access(cmd, X_OK))
			return (free(bin), bin = NULL, cmd);
		free(bin);
		bin = NULL;
		i++;
	}
	free(bin);
	free(cmd);
	return (bin = NULL, cmd = NULL, NULL);
}

char	**parse_cmd(char	*cmd, t_vrs *vars)
{
	char	**args;
	int		args_num;

	args = NULL;
	args_num = count_words(cmd, ' ');
	args = ft_split(cmd, ' ');
	if (!args)
		return (NULL);
	args[0] = get_binary_path(args[0], vars->path);
	if (!args[0])
		clear_vars(vars, 2);
	return (args);
}
