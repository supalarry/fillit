/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_put_letters.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: lskrauci <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/08 19:42:39 by lskrauci      #+#    #+#                 */
/*   Updated: 2019/02/08 19:42:41 by lskrauci      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fill_it_header.h"

/*
** @desc Replace tetrimino's #'s with corresponding letter
** @param char *tetrimino - tetrimino string
** @param char letter - letter to replace #'s with
** @return void
*/

static void		ft_change_symbols(char *tetrimino, char letter)
{
	int		i;

	i = 0;
	while (tetrimino[i] != '\0')
	{
		if (tetrimino[i] == '#')
			tetrimino[i] = letter;
		i++;
	}
}

/*
** @desc Replace each tetrimino's #'s with corresponding letter
** @param char **tetrimino - array containing individual tetriminos
** @return void
*/

void			ft_alphabet(char **tetriminos)
{
	int		i;
	char	letter;

	letter = 'A';
	i = 0;
	while (tetriminos[i] != '\0')
	{
		ft_change_symbols(tetriminos[i], letter + i);
		i++;
	}
}
