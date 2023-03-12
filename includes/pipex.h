/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-bouz <zel-bouz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 15:14:30 by zel-bouz          #+#    #+#             */
/*   Updated: 2023/03/12 10:29:05 by zel-bouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft.h"
# include <sys/wait.h>

typedef struct s_vrs
{
	char	**path;
	char	**env;
	char	**av;
	char	**cmd_args1;
	char	**cmd_args2;
	int		inp;
	int		out;
	pid_t	pid;
	pid_t	pid2;
	int		fds[2];
}	t_vrs;

void	parse_env(t_vrs *vrs);
char	**parse_cmd(char	*cmd, t_vrs *vars);
void	pipex(t_vrs *vrs);

// utils functions :
void	add_slash(char	**path);
void	free_dup(char **dup);
void	clear_vars(t_vrs *vrs, int er);

#endif