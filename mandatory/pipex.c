/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-bouz <zel-bouz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 23:11:11 by zel-bouz          #+#    #+#             */
/*   Updated: 2023/03/07 05:42:41 by zel-bouz         ###   ########.fr       */
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
	ft_puterror("ERROR EXECVE\n");
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
	ft_puterror("ERROR EXECVE\n");
}

void	pipex(t_vrs *vrs)
{
	if ((pipe(vrs->fds) == -1))
	{
		clear_vars(vrs);
		ft_puterror("Pipe error\n");
	}
	vrs->pid = fork();
	if (vrs->pid == -1)
	{
		clear_vars(vrs);
		ft_puterror("Fork error\n");
	}
	if (!vrs->pid)
		exec_cmd1(vrs);
	else
	{
		if (fork() == 0)
			exec_cmd2(vrs);
		else
		{
			close_all_fds(vrs);
			wait(NULL);
		}
		wait(NULL);
	}
}
