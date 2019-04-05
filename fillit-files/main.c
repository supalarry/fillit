/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: lskrauci <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/06 19:52:38 by lskrauci      #+#    #+#                 */
/*   Updated: 2019/02/06 19:52:40 by lskrauci      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fill_it_header.h"

static void	exit_error(int type)
{
	if (type == 1)
		ft_putstr("Usage : ./fillit tetrimino_sample_file\n");
	else if (type == 0)
		ft_putstr("error\n");
	exit(0);
}

int			main(int argc, char **argv)
{
	int			fd_input;
	char		**tetriminos_buf;
	char		**grid;
	int			grid_size;

	if (argc != 2)
		exit_error(1);
	fd_input = open(argv[1], O_RDONLY);
	if (fd_input == -1)
		exit_error(0);
	if (!ft_validate_input(fd_input, &tetriminos_buf))
		exit_error(0);
	ft_cut_tetriminos(tetriminos_buf);
	ft_alphabet(tetriminos_buf);
	grid_size = ft_min_size_grid(tetriminos_buf);
	grid = ft_create_grid(grid_size);
	while (ft_tetriminos_solver(tetriminos_buf, grid, 0) == 0)
	{
		ft_resize_grid(&grid, grid_size, grid_size + 1);
		grid_size++;
	}
	ft_print_grid(grid);
	return (0);
}
