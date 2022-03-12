# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jihong <jihong@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/10 18:36:03 by jihong            #+#    #+#              #
#    Updated: 2022/03/12 20:15:05 by jihong           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:=	libftprintf.a
SRC			:=	ft_printf.c\
OBJ			:=	$(SRC:.c=.o)
CFLAGS		:=	-Wall -Wextra -Werror

OBJECTS = $(OBJ)


.PHONY:		all bonus clean fclean re

all:		$(NAME)

$(NAME):	$(OBJECTS)
	ar -rc $@ $^

bonus:
	@make WITH_BONUS=1 all

*.o:		*.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ) $(BOBJ)

fclean:		clean
	@rm -f $(NAME)

re:			fclean all
