# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jjory-ca <jjory-ca@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/27 19:35:46 by jjory-ca          #+#    #+#              #
#    Updated: 2019/09/11 14:59:54 by jjory-ca         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem_in
LIBF = libft/
GNL = gnl/get_next_line.c
SRCS = src/
CC = -Wall -Wextra -Werror -lncurses -ltermcap -L $(LIBF) -lft

all: $(NAME)

$(NAME):
		@make -C $(LIBF) re
		@gcc $(CC) $(SRCS)*.c $(GNL) -o $(NAME)

clean:
		@make -C $(LIBF) clean

fclean:
		@make -C $(LIBF) fclean
		@/bin/rm -rf $(NAME)

re: fclean all
