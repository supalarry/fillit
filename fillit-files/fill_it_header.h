/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fill_it_header.h                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: lskrauci <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/06 12:28:34 by lskrauci      #+#    #+#                 */
/*   Updated: 2019/02/06 12:28:36 by lskrauci      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILL_IT_HEADER_H
# define FILL_IT_HEADER_H
# include "../libft/libft.h"
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>

int					ft_validate_input(int fd_input, char ***tetriminos);
char				*ft_load_input(int fd_input);
void				ft_cut_tetriminos(char **tetriminos_buf);
void				ft_alphabet(char **tetriminos);
char				**ft_create_grid(int size);
int					ft_min_size_grid(char **tetriminos);
void				ft_print_grid(char **grid);
int					ft_tetriminos_solver(char **tetriminos_buf,
					char **grid, int x);
void				ft_resize_grid(char ***grid, int size, int new_size);
int					ft_validate_position(int row, int col, char *t, char **g);
int					ft_g_size(char **grid);

#endif
