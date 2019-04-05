/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_grid.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: lskrauci <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/08 19:42:32 by lskrauci      #+#    #+#                 */
/*   Updated: 2019/02/08 19:42:34 by lskrauci      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fill_it_header.h"

/*
** @desc Malloc 2d array according to size input
** @desc Fills it with '.' characters
** @desc Every line is terminated with '\0'
** @param int size - square's side's size
** @return char **grid - 2d array containing dots
*/

char	**ft_create_grid(int size)
{
	char	**grid;
	int		i;
	int		j;

	i = 0;
	if (size < 2)
		return (NULL);
	grid = (char **)malloc(sizeof(char *) * size + 1);
	while (i < size)
	{
		j = 0;
		grid[i] = malloc(sizeof(char) * size + 1);
		if (!grid[i])
			return (NULL);
		while (j < size)
		{
			grid[i][j] = '.';
			j++;
		}
		grid[i][j] = '\0';
		i++;
	}
	grid[i] = NULL;
	return (grid);
}

/*
** @desc Calculate minimum size of a grid
** @param char **tetriminos - array of tetriminos
** @return int ans - mininum size (square root of num_of_tetriminos * 4)
** @return 0 for invalid input
*/

int		ft_min_size_grid(char **tetriminos)
{
	int blocks;
	int ans;
	int	num_of_tetriminos;

	num_of_tetriminos = 0;
	while (tetriminos[num_of_tetriminos] != '\0')
		num_of_tetriminos++;
	blocks = num_of_tetriminos * 4;
	ans = 2;
	if (num_of_tetriminos < 1 || num_of_tetriminos > 26)
		return (0);
	while (ans < blocks)
	{
		if (ans * ans == blocks)
			break ;
		else if (ans * ans > blocks)
			break ;
		ans++;
	}
	return (ans);
}

/*
** @desc Print out a grid
** @param char **grid - grid to be printed
** @return void
*/

void	ft_print_grid(char **grid)
{
	int i;

	i = 0;
	while (grid[i])
	{
		ft_putendl(grid[i]);
		i++;
	}
}

void	ft_resize_grid(char ***grid, int size, int new_size)
{
	int		row;
	int		col;
	char	**new_grid;

	row = 0;
	col = 0;
	new_grid = ft_create_grid(new_size);
	while (row < size)
	{
		while (col < size)
		{
			new_grid[row][col] = (*grid)[row][col];
			col++;
		}
		col = 0;
		row++;
	}
	*grid = new_grid;
}
