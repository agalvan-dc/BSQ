/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelescu <stelescu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 10:17:50 by agalvan-          #+#    #+#             */
/*   Updated: 2026/02/18 16:34:18 by stelescu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "library.h"

void	ft_print(char **m, T_DIM dim)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < dim.dimi)
	{
		while (j < dim.dimj)
		{
			write(1, &m[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		j = 0;
		i++;
	}
	return ;
}

/* Fill the largest free square starting at (f_free.posi, f_free.posj) */
void	ft_sol(char **m, T_POS f_free, T_DIM tam)
{
	int	row;
	int	col;

	row = 0;
	while (row < f_free.tam)
	{
		col = 0;
		while (col < f_free.tam)
		{
			m[f_free.posi + row][f_free.posj + col] = 'x';
			col++;
		}
		row++;
	}
	ft_print(m, tam);
	return ;
}

/* Check that a tam x tam square starting at (ini, inj) is all '.' */
int	ft_validate(char **m, int ini, int inj, T_POS f_free)
{
	int	aui;
	int	auj;

	aui = ini;
	while (aui < ini + f_free.tam)
	{
		auj = inj;
		while (auj < inj + f_free.tam)
		{
			if (m[aui][auj] != '.')
				return (0);
			auj++;
		}
		aui++;
	}
	return (1);
}

/* Count consecutive '.' starting at (ini, inj) and test squares of that size */
void	ft_num_space(char **m, int ini, int inj, T_POS *f_free, T_DIM tam)
{
	int		cont;
	int		col;
	T_POS	candidate;

	cont = 0;
	col = inj;
	while (inj < tam.dimj && m[ini][inj] == '.')
	{
		cont++;
		inj++;
	}
	/* Try the largest possible square fitting in the remaining rows too */
	candidate.tam = cont;
	candidate.posi = ini;
	candidate.posj = col;
	/* Shrink candidate until it fits vertically and is all '.' */
	while (candidate.tam > f_free->tam)
	{
		if (ini + candidate.tam <= tam.dimi
			&& ft_validate(m, ini, col, candidate) == 1)
		{
			*f_free = candidate;
			break ;
		}
		candidate.tam--;
	}
}

void	ft_start(char **m, T_DIM dim)
{
	T_POS	f_free;
	int		i;
	int		j;

	i = 0;
	j = 0;
	f_free.tam = 0;
	f_free.posi = 0;
	f_free.posj = 0;
	while (i < dim.dimi)
	{
		j = 0;
		while (j < dim.dimj)
		{
			if (m[i][j] == '.')
				ft_num_space(m, i, j, &f_free, dim);
			j++;
		}
		i++;
	}
	ft_sol(m, f_free, dim);
}
