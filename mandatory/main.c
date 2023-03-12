/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-bouz <zel-bouz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 15:13:51 by zel-bouz          #+#    #+#             */
/*   Updated: 2023/03/12 10:03:06 by zel-bouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	leaks(){
	system("leaks pipex");
}

int	main(int ac, char **av, char **env)
{
	t_vrs	vrs;

	atexit(leaks);
	if (ac == 5)
	{
		ft_bzero(&vrs, sizeof(t_vrs));
		vrs.av = av;
		vrs.env = env;
		vrs.inp = open(vrs.av[1], O_RDONLY);
		if (vrs.inp == -1)
			clear_vars(&vrs, 1);
		vrs.out = open(vrs.av[4], O_RDWR | O_TRUNC | O_CREAT, 0777);
		if (vrs.out == -1)
		{
			close(vrs.inp);
			clear_vars(&vrs, 1);
		}
		parse_env(&vrs);
		pipex(&vrs);
	}
	else
	{
		ft_putstr("argmunets number invalide");
		exit(1);
	}
}
