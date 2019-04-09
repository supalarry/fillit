/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_load.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: lskrauci <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/08 11:29:03 by lskrauci      #+#    #+#                 */
/*   Updated: 2019/02/08 11:29:05 by lskrauci      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fill_it_header.h"

/* 
** @desc Load file of user's tetrimino as a string
** @param int fd_input - file descriptor of user's input
** @return NULL if read occured an error
** @return char *input_string containing input tetriminos
*/

char	*ft_load_input(int fd_input)
{
	char	input_buf[33];
	char	*input_string;
	char	*input_temp;
	int		read_ret;

	input_string = "";
	read_ret = read(fd_input, input_buf, 32);
	if (read_ret == -1)
		return (NULL);
	input_buf[read_ret] = '\0';
	input_string = ft_strjoin(input_string, input_buf);
	while (read_ret)
	{
		read_ret = read(fd_input, input_buf, 32);
		if (read_ret == -1)
			return (NULL);
		input_buf[read_ret] = '\0';
		input_temp = input_string;
		input_string = ft_strjoin(input_string, input_buf);
		free(input_temp);
	}
	return (input_string);
}
