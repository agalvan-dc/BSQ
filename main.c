/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelescu <stelescu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 18:22:02 by agalvan-          #+#    #+#             */
/*   Updated: 2026/02/18 16:31:27 by stelescu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "library.h"

int	main(int argc, char **argv)
{
	T_DIM	tab;
	char	**m;
	int		file;

	if (argc != 2 || argv[1][0] == '\0')
	{
		write(1, "map error\n", 10);
		return (1);
	}
	file = open(argv[1], O_RDONLY);
	if (file == -1)
	{
		write(1, "map error\n", 10);
		return (1);
	}
	tab = ft_flen(file);
	close(file);
	if (tab.dimi == 0 || tab.dimj == 0)
	{
		write(1, "map error\n", 10);
		return (1);
	}
	file = open(argv[1], O_RDONLY);
	if (file == -1)
	{
		write(1, "map error\n", 10);
		return (1);
	}
	if (ft_create(&m, tab) == -1)
	{
		close(file);
		return (1);
	}
	ft_fill(file, m);
	close(file);
	ft_start(m, tab);
	ft_free(m);
	return (0);
}
