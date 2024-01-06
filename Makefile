# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mel-ayou < mel-ayou@student.42.fr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/09 22:01:08 by mel-ayou          #+#    #+#              #
#    Updated: 2024/01/06 05:17:35 by mel-ayou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	=	libftprintf.a

CC		=	cc

CFLAGS	=	-Wall -Wextra -Werror

OBJ 	=	ft_printf.c				\
			ft_printf_putchr.c		\
			ft_printf_putnbr.c				\
			ft_printf_putstr.c				\
			ft_printf_putunbr.c		\
			ft_printf_hexa.c		\
			ft_printf_pntr.c		\

OBJS	=	$(OBJ:%.c=%.o)

all:		$(NAME)

$(NAME):	$(OBJS)
	ar rc $(NAME) $(OBJS)

clean:
	rm -fr $(OBJS)

fclean:		clean
	rm -fr $(NAME)

re:	clean all