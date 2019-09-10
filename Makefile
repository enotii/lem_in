# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: caking <caking@student.21-school.ru>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/27 19:35:46 by jjory-ca          #+#    #+#              #
#    Updated: 2019/09/10 19:48:08 by caking           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in
LIBF = libft/
GNL = gnl/get_next_line.c
SRCS = src/
CCFL = -Wall -Wextra -Werror -lncurses -ltermcap -L $(LIBF) -lft

all: $(NAME)

$(NAME):
		@make -C $(LIBF) re
		@gcc $(CCFL) $(SRCS)*.c $(GNL) -o $(NAME)

clean:
		@make -C $(LIBF) clean

fclean:
		@make -C $(LIBF) fclean
		@/bin/rm -rf $(NAME)

re: fclean all
