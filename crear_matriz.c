/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   crear_matriz.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelescu <stelescu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 17:03:56 by agalvan-          #+#    #+#             */
/*   Updated: 2026/02/18 16:57:51 by stelescu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "library.h"

int	ft_create(char ***m, T_DIM tab)
{
	int	i;

	i = 0;
	*m = malloc(sizeof(char *) * (tab.dimi + 1));
	if (*m == NULL)
	{
		write(1, "Error de asignacion de memoria", 30);
		return (-1);
	}
	while (i < tab.dimi)
	{
		(*m)[i] = malloc(sizeof(char) * (tab.dimj + 1));
		if ((*m)[i] == NULL)
		{
			write(1, "Error de asignacion de memoria", 30);
			return (-1);
		}
		(*m)[i][tab.dimj] = '\0';
		i++;
	}
	(*m)[i] = NULL;
	return (0);
}

/* Skip the header line, then count columns from the first data line,
   then count remaining newlines for row count. */
T_DIM	ft_flen(int file)
{
	char	letter;
	T_DIM	tab;

	tab.dimi = 0;
	tab.dimj = 0;
	/* Skip header line */
	while (read(file, &letter, 1) > 0 && letter != '\n')
		;
	/* Count columns from first data line */
	while (read(file, &letter, 1) > 0 && letter != '\n')
		tab.dimj++;
	if (tab.dimj == 0)
		return (tab);
	tab.dimi = 1;
	/* Count remaining rows */
	while (read(file, &letter, 1) > 0)
	{
		if (letter == '\n')
			tab.dimi++;
	}
	return (tab);
}

/* Re-open is done in main; here we skip header then fill row by row. */
void	ft_fill(int file, char **m)
{
	char	l;
	int		i;
	int		j;

	i = 0;
	j = 0;
	/* Skip header line */
	while (read(file, &l, 1) > 0 && l != '\n')
		;
	while (read(file, &l, 1) > 0)
	{
		if (l == '\n')
		{
			m[i][j] = '\0';
			j = 0;
			i++;
		}
		else
		{
			m[i][j] = l;
			j++;
		}
	}
	if (j > 0)
		m[i][j] = '\0';
}

void	ft_free(char **m)
{
	int	i;

	i = 0;
	while (m[i])
	{
		free(m[i]);
		i++;
	}
	free(m);
	return ;
}
