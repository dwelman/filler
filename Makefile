# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daviwel <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/06/03 10:00:16 by daviwel           #+#    #+#              #
#    Updated: 2016/06/06 10:46:09 by ddu-toit         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = filler

SRC = main.c input.c ft_puttrace.c rough_check.c init.c refine_check.c\
	  mops.c

OBJ = $(SRC:.c=.o)

CFLAG = -Wall -Werror -Wextra

all: $(NAME)

$(NAME):
	make -C libft/ fclean
	make -C libft
	gcc -I libft/ -c $(SRC)
	gcc -o $(NAME) $(OBJ) -L libft/ -lft

clean:
	/bin/rm -f $(OBJ)
	make -C libft/ clean

fclean: clean
	/bin/rm -f $(NAME)
	make -C libft/ fclean

re: fclean all

norme:
	norminette $(SRC)

q:
	gcc -I libft/ -c $(SRC)
	gcc -o $(NAME) $(OBJ) -L libft/ -lft

run:
	rm trace.txt
	touch trace.txt
	./filler_vm -p1 ./filler -p2 ./filler -v -f w2.flr

qr: q run
