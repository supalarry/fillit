/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_validate.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: lskrauci <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/07 10:51:21 by lskrauci      #+#    #+#                 */
/*   Updated: 2019/02/07 10:51:23 by lskrauci      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fill_it_header.h"

/*
** @desc Creates an array of tetriminos from input file
** @param char *input_buf - string of all tetriminos
** @return NULL if between tetriminos are multiple newlines
** @return char **delimited_tetriminos array with tetriminos
*/

static char	**ft_split_tetriminos(char *input_buf)
{
	int		i;
	char	**tetriminos_buf;
	int		newline_count;

	newline_count = 0;
	i = 0;
	while (input_buf[i] != '\0')
	{
		if (input_buf[i] == '\n')
			newline_count++;
		else
			newline_count = 0;
		if (newline_count > 2)
			return (NULL);
		if (input_buf[i] == '\n' && input_buf[i - 1] == '\n')
			input_buf[i] = 'v';
		i++;
	}
	tetriminos_buf = ft_strsplit(input_buf, 'v');
	return (tetriminos_buf);
}

/*
** @desc Check if input file starts and ends with allowed characters
** @param char *input_buf - string of all tetriminos
** @return 0 if start or end of input file is invalid
** @return 1 if start and end are valid
*/

static int	ft_validate_start_end(char *input_buf)
{
	int len;

	if (input_buf[0] != '#' && input_buf[0] != '.')
		return (0);
	len = ft_strlen(input_buf) - 1;
	if (input_buf[len] != '\n' ||
		(input_buf[len - 1] != '#' && input_buf[len - 1] != '.'))
		return (0);
	return (1);
}

/*
** @desc Checks string length, newline characters
** @desc at end of lines and hash and dot count
** @param char *tetrimino_buf - string of one tetrimino
** @return 0 for invalid tetrimino
** @return 1 for valid tetrimino
*/

static int	ft_check_symbols(char *tetrimino_buf)
{
	int	i;
	int	hash_count;
	int	dot_count;

	i = 0;
	hash_count = 0;
	dot_count = 0;
	if (ft_strlen(tetrimino_buf) != 20)
		return (0);
	if (tetrimino_buf[4] != '\n' || tetrimino_buf[9] != '\n'
	|| tetrimino_buf[14] != '\n' || tetrimino_buf[19] != '\n')
		return (0);
	while (tetrimino_buf[i] != '\0')
	{
		if (tetrimino_buf[i] == '#')
			hash_count++;
		else if (tetrimino_buf[i] == '.')
			dot_count++;
		i++;
	}
	if (hash_count != 4 || dot_count != 12)
		return (0);
	return (1);
}

static int	ft_connections(char *tetrimino)
{
	int	i;
	int	connections;

	i = 0;
	connections = 0;
	while (tetrimino[i] != '\0')
	{
		if (tetrimino[i] == '#')
		{
			if (i != 0 && tetrimino[i - 1] == '#')
				connections++;
			if (tetrimino[i + 1] == '#')
				connections++;
			if (i + 5 <= 21 && tetrimino[i + 5] == '#')
				connections++;
			if (i - 5 >= 0 && tetrimino[i - 5] == '#')
				connections++;
		}
		i++;
	}
	if (connections >= 6)
		return (1);
	return (0);
}

/*
** @desc Load input and valid files
** @desc Validate start and end of input file
** @desc Split tetraminos as seperate strings
** @desc Check validity of each tetramino
** @param int fd_input - file descriptor of user's input
** @param int fd_valid - file descriptor of valid tetriminos
** @return 0 for invalid file of tetriminos
** @return 1 for valid file of tetriminos
** @return and store 2d array in char ***tetriminos pointer
*/

int			ft_validate_input(int fd_input, char ***tetriminos)
{
	int		i;
	char	*input_buf;
	char	**tetriminos_buf;

	i = 0;
	input_buf = ft_load_input(fd_input);
	if (!ft_validate_start_end(input_buf))
		return (0);
	tetriminos_buf = ft_split_tetriminos(input_buf);
	free(input_buf);
	if (tetriminos_buf == NULL)
		return (0);
	while (tetriminos_buf[i] != '\0')
	{
		if (!ft_check_symbols(tetriminos_buf[i]))
			return (0);
		if (!ft_connections(tetriminos_buf[i]))
			return (0);
		i++;
	}
	if (i > 25 || i < 1)
		return (0);
	*tetriminos = tetriminos_buf;
	return (1);
}
