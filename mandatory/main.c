/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-bouz <zel-bouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 15:13:51 by zel-bouz          #+#    #+#             */
/*   Updated: 2023/02/26 18:13:55 by zel-bouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	init_vars(t_vrs *vars, char	**env, char	**av)
{
	vars->av = av;
	vars->env = env;
	vars->cmd_args1 = NULL;
	vars->cmd_args2 = NULL;
	vars->inp = -1;
	vars->out = -1;
	vars->path = NULL;
}

int	main(int ac, char **av, char **env)
{
	t_vrs	vrs;

	if (ac == 5)
	{
		init_vars(&vrs, env, av);
		vrs.inp = open(vrs.av[1], O_RDONLY);
		if (vrs.inp == -1)
			ft_puterror("ERROR: invalid file\n");
		vrs.out = open(vrs.av[4], O_RDWR | O_TRUNC | O_CREAT, 0777);
		if (vrs.out == -1)
		{
			close(vrs.inp);
			ft_puterror("ERROR: unable to create output file\n");
		}
		parse_env(&vrs);
		pipex(&vrs);
	}
	else
		exit(1);
}
