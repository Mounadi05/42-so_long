# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amounadi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/02 01:58:21 by amounadi          #+#    #+#              #
#    Updated: 2022/03/02 02:06:53 by amounadi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRCS	= so_long.c ft_utils.c get_next_line.c get_next_line_utils.c ft_read_map.c ft_move.c 

OBJS	= $(SRCS:.c=.o)

GCC		= gcc

FLGS	= -Wall -Wextra -Werror 
RM		= rm -f

all:		$(NAME)

$(NAME): $(OBJS) 
			@$(GCC) $(FLGS) -lmlx -framework OpenGL -framework AppKit $(OBJS) -o $(NAME)
			@echo "\033[1;32m so_long is ready"
.c.o:
			@$(GCC) $(FLGS) -c $<

clean:
			$(RM) $(OBJS) 

fclean:		clean
			$(RM) $(NAME) 

re:			fclean all

.PHONY:		all bonus clean fclean re
