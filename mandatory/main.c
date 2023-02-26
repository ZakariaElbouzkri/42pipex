/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-bouz <zel-bouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 15:13:51 by zel-bouz          #+#    #+#             */
/*   Updated: 2023/02/25 23:14:29 by zel-bouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	init_vars(t_vrs *vars, char	**env, char	**av)
{
	vars->av = av;
	vars->env = env;

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
		parse_env(&vrs);
		pipex(&vrs);
	}
	else
		exit(1);
}
