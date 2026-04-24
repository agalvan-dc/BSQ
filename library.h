/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   library.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelescu <stelescu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 17:11:53 by agalvan-          #+#    #+#             */
/*   Updated: 2026/02/18 16:31:34 by stelescu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef library
#define library

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

typedef struct
{
	int	tam;
	int	posi;
	int	posj;
} T_POS;

typedef struct 
{
	int dimi;
	int dimj;
} T_DIM ;

int	ft_create(char ***m, T_DIM tab);

T_DIM	ft_flen(int file);

int	ft_validate(char **m, int ini, int inj, T_POS f_free);

void	ft_fill(int file, char **m);

void	ft_start(char **m, T_DIM tab);

void	ft_num_space(char **m, int ini, int inj, T_POS *f_free, T_DIM tab);

void	ft_sol(char **m, T_POS f_free, T_DIM tab);

void	ft_print(char **m, T_DIM tab);

void	ft_free(char **m);

#endif
