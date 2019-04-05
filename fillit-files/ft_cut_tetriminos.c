/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_topleft.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lskrauci <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/08 13:36:29 by lskrauci      #+#    #+#                 */
/*   Updated: 2019/02/08 13:36:30 by lskrauci      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fill_it_header.h"

static void	ft_x_horizontal(char *tetrimino)
{
	int row_start;

	row_start = 0;
	while (row_start <= 15)
	{
		if (tetrimino[row_start] == '.' && tetrimino[row_start + 1] == '.'
		&& tetrimino[row_start + 2] == '.' && tetrimino[row_start + 3] == '.')
		{
			tetrimino[row_start] = 'x';
			tetrimino[row_start + 1] = 'x';
			tetrimino[row_start + 2] = 'x';
			tetrimino[row_start + 3] = 'x';
			tetrimino[row_start + 4] = 'x';
		}
		row_start = row_start + 5;
	}
}

static void	ft_x_vertical(char *tetrimino)
{
	int col_start;

	col_start = 0;
	while (col_start < 4)
	{
		if (tetrimino[col_start] != '#' && tetrimino[col_start + 5] != '#'
		&& tetrimino[col_start + 10] != '#' && tetrimino[col_start + 15] != '#')
		{
			tetrimino[col_start] = 'x';
			tetrimino[col_start + 5] = 'x';
			tetrimino[col_start + 10] = 'x';
			tetrimino[col_start + 15] = 'x';
		}
		col_start++;
	}
}

static char	*ft_cut(char *tetrimino)
{
	int		i;
	int		j;
	int		len;
	char	*tetrimino_cut;

	i = 0;
	j = 0;
	len = 0;
	tetrimino_cut = (char *)malloc(21);
	while (tetrimino[i] != '\0')
	{
		if (tetrimino[i] != 'x')
		{
			tetrimino_cut[j] = tetrimino[i];
			j++;
		}
		i++;
	}
	tetrimino_cut[j] = '\0';
	free(tetrimino);
	return (tetrimino_cut);
}

/*
** @desc Cuts out tetriminos within a box
** @param char **tetriminos_buf - array of tetriminos
** @return void
*/

void		ft_cut_tetriminos(char **tetriminos_buf)
{
	int i;

	i = 0;
	while (tetriminos_buf[i] != '\0')
	{
		ft_x_horizontal(tetriminos_buf[i]);
		ft_x_vertical(tetriminos_buf[i]);
		tetriminos_buf[i] = ft_cut(tetriminos_buf[i]);
		i++;
	}
}
