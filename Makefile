# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: lskrauci <marvin@codam.nl>                   +#+                      #
#                                                    +#+                       #
#    Created: 2019/02/15 12:11:34 by lskrauci      #+#    #+#                  #
#    Updated: 2019/02/15 12:11:37 by lskrauci      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = fillit
SRCS = ./fillit-files/main.c ./fillit-files/ft_validate_input.c \
./fillit-files/ft_load.c ./fillit-files/ft_cut_tetriminos.c \
./fillit-files/ft_grid.c ./fillit-files/ft_alphabet.c \
./fillit-files/ft_tetriminos_solver.c ./fillit-files/ft_helpers.c
HEADER = ./fillit-files/

all: $(NAME)

$(NAME): 
	make -C ./libft
	gcc -o $(NAME) $(SRCS) -I $(HEADER) -L ./libft/ -lft -Wall -Wextra -Werror
clean:
	make -C ./libft/ clean

fclean: clean
	rm -f $(NAME)
	make -C ./libft/ fclean

re: fclean all
