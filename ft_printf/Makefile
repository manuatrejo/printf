# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: manguita <manguita@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/20 22:41:09 by manguita          #+#    #+#              #
#    Updated: 2024/10/21 00:54:07 by manguita         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a

SRCS	= ft_printf.c ft_utils.c ft_numbers.c

OBJS	= $(SRCS:.c=.o)

RM		= rm -f

CC		= gcc

CFLAGS	= -Wall -Wextra -Werror

all:	$(NAME)

$(NAME):	$(OBJS)
					ar rcs $(NAME) $(OBJS)

clean:
					$(RM) $(OBJS)

fclean:		clean
					$(RM) $(NAME)

re:					fclean all

.PHONY:		all clean fclean re				