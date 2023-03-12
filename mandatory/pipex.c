/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-bouz <zel-bouz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 23:11:11 by zel-bouz          #+#    #+#             */
/*   Updated: 2023/03/12 10:03:55 by zel-bouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	exec_cmd1(t_vrs *vrs)
{
	close(vrs->out);
	close(vrs->fds[0]);
	dup2(vrs->inp, 0);
	dup2(vrs->fds[1], 1);
	close(vrs->inp);
	close(vrs->fds[1]);
	execve(vrs->cmd_args1[0], vrs->cmd_args1, vrs->env);
	clear_vars(vrs, 4);
}

void	close_all_fds(t_vrs *vrs)
{
	close(vrs->fds[0]);
	close(vrs->fds[1]);
	close(vrs->inp);
	close(vrs->out);
	wait(NULL);
}

void	exec_cmd2(t_vrs *vrs)
{
	close(vrs->inp);
	close(vrs->fds[1]);
	dup2(vrs->out, 1);
	dup2(vrs->fds[0], 0);
	close(vrs->fds[0]);
	close(vrs->out);
	execve(vrs->cmd_args2[0], vrs->cmd_args2, vrs->env);
	clear_vars(vrs, 4);
}

void	pipex(t_vrs *vrs)
{
	if ((pipe(vrs->fds) == -1))
		clear_vars(vrs, 3);
	vrs->pid = fork();
	if (vrs->pid == -1)
	{
		clear_vars(vrs, 3);
	}
	if (!vrs->pid)
	{
		free_dup(vrs->cmd_args2);
		vrs->cmd_args2 = NULL;
		exec_cmd1(vrs);
	}
	else
	{
		free_dup(vrs->cmd_args1);
		vrs->cmd_args1 = NULL;
		if (fork() == 0)
			exec_cmd2(vrs);
		else
		{
			free_dup(vrs->cmd_args2);
			vrs->cmd_args2 = NULL;
			close_all_fds(vrs);
			wait(NULL);
		}
		wait(NULL);
	}
}
