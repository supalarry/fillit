/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_tetriminos_solver.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: lskrauci <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/10 18:37:19 by lskrauci      #+#    #+#                 */
/*   Updated: 2019/02/10 18:37:21 by lskrauci      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fill_it_header.h"

int		ft_g_size(char **grid)
{
	int	length;

	length = 0;
	while (grid[0][length] != '\0')
		length++;
	return (length);
}

int		ft_validate_position(int row, int col, char *t, char **g)
{
	int	i;
	int	col_copy;

	i = 0;
	col_copy = col;
	while (t[i] != '\0' && row < ft_g_size(g) && col <= ft_g_size(g))
	{
		if ((g[row][col] == '.' && ft_isalpha(t[i])) ||
		(t[i] == '.' && ft_isalpha(g[row][col])) ||
		(g[row][col] == '.' && t[i] == '.'))
			col++;
		else if (t[i] == '\n')
		{
			col = col_copy;
			row++;
		}
		else
			break ;
		i++;
	}
	if (t[i] == '\0')
		return (1);
	return (0);
}
