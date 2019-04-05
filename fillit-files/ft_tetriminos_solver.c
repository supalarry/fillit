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

/*
** @desc Finds a position that has the least sum of indexes
** @param int *row_ptr - address of integer that will store row
** @param int *col_ptr - address of integer that will store col
** @param char **grid - grid where tetrimino is placed
** @param int grid_size - size of side of grid
** @return 1 if valid coordinate was found
** @return 0 if no valid coordinate was found
*/

static int	ft_find_position(int *row_ptr, int *col_ptr, char *t, char **g)
{
	int i;
	int j;
	int found;

	i = 0;
	j = 0;
	found = 0;
	while (i < ft_g_size(g) && found != 1)
	{
		while (j < ft_g_size(g) && found != 1)
		{
			if (ft_validate_position(i, j, t, g))
			{
				*row_ptr = i;
				*col_ptr = j;
				found = 1;
			}
			j++;
		}
		j = 0;
		i++;
	}
	if (found)
		return (1);
	return (0);
}

/*
** @desc Finds a position that has the least sum of indexes
** @param int *row_ptr - address of integer that will store row
** @param int *col_ptr - address of integer that will store col
** @param char **grid - grid where tetrimino is placed
** @param int grid_size - size of side of grid
** @return 1 if valid coordinate was found
** @return 0 if no valid coordinate was found
*/

static int	ft_find_next(int *row_ptr, int *col_ptr, char *t, char **g)
{
	int i;
	int j;
	int found;

	i = *row_ptr;
	j = *col_ptr + 1;
	found = 0;
	while (i < ft_g_size(g) && found != 1)
	{
		while (j < ft_g_size(g) && found != 1)
		{
			if (ft_validate_position(i, j, t, g))
			{
				*row_ptr = i;
				*col_ptr = j;
				found = 1;
			}
			j++;
		}
		j = 0;
		i++;
	}
	if (found)
		return (1);
	return (0);
}

/*
** @desc Places tetrimino at specific coordinates
** @param int row - row of the grid to place tetrimino
** @param int col - col of the specific row
** @param char *tetrimino - tetrimino to be placed
** @param char **grid - grid where tetrimino is placed
** @return void
*/

static void	ft_place_tetrimino(int row, int col, char *tetrimino, char **grid)
{
	int i;
	int col_copy;

	i = 0;
	col_copy = col;
	while (tetrimino[i] != '\0')
	{
		if (tetrimino[i] == '\n')
		{
			row++;
			col = col_copy;
		}
		else if (grid[row][col] >= 'A' && grid[row][col] <= 'Z')
			col++;
		else
		{
			grid[row][col] = tetrimino[i];
			col++;
		}
		i++;
	}
}

/*
** @desc Launches fuctions to loop through whole board
** @desc and check if tetrimino fits in most upper left place.
** @desc If so, place the tetrimino there. If ft_find_position
** @desc can't find place, resize grid.
** @param char **tetriminos_buf - array of tetriminos
** @param char **grid - board where tetriminos are placed
** @param int grid_size - size of side of grid
** @return void
*/

static void	ft_remove_tetrimino(char **grid, int x)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	j = 0;
	c = x + 'A';
	while (grid[i] != NULL)
	{
		while (grid[i][j] != '\0')
		{
			if (grid[i][j] == c)
				grid[i][j] = '.';
			j++;
		}
		j = 0;
		i++;
	}
}

int			ft_tetriminos_solver(char **tetriminos_buf, char **grid, int x)
{
	static int	i;
	int			row;
	int			col;

	i = x;
	if (tetriminos_buf[i] == NULL)
		return (1);
	if (!ft_find_position(&row, &col, tetriminos_buf[i], grid))
		return (0);
	ft_place_tetrimino(row, col, tetriminos_buf[i], grid);
	i++;
	while (ft_tetriminos_solver(tetriminos_buf, grid, i) != 1)
	{
		ft_remove_tetrimino(grid, i - 1);
		if (ft_find_next(&row, &col, tetriminos_buf[i - 1], grid))
			ft_place_tetrimino(row, col, tetriminos_buf[i - 1], grid);
		else if (i - 1 == 0)
			return (0);
		else
		{
			--i;
			return (0);
		}
	}
	return (1);
}
