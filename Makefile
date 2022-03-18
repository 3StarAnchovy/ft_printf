# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jihong <jihong@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/10 18:36:03 by jihong            #+#    #+#              #
#    Updated: 2022/03/18 20:52:30 by jihong           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = gcc
CFLAG = -Wall -Werror -Wextra
CFILES = ft_printf.c ft_printf_arg.c ft_printf_arg2.c
OBJ = $(CFILES:.c=.o)

all: $(NAME)

$(NAME) : $(OBJ)
	ar rcs $(NAME) $(OBJ)

$(OBJ) : $(CFILES)
	$(CC) $(CFLAGS) -c $(CFILES)

clean :
	rm -rf *.o

fclean : clean
	rm -rf $(NAME)

re : fclean all
