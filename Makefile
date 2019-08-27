# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jjory-ca <jjory-ca@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/27 19:35:46 by jjory-ca          #+#    #+#              #
#    Updated: 2019/08/27 20:10:18 by jjory-ca         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
FLAGS = -Wall -Wextra -Werror
NAME = lem_in
INC = inc
SRC = srcs
L_DIR = libft
FILES = lem_in.c 

all : $(NAME) 

$(NAME) :
	@$(CC) -o $(NAME) $(FLAGS) $(NAME) -I $(INC) -L $(SRC) -lft

clean :
	@rm -f $(OBJ)
fclean : clean
	@rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re