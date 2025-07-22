# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ibettenc <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/26 19:36:14 by ibettenc          #+#    #+#              #
#    Updated: 2025/04/30 13:18:11 by ibettenc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

###################################################
## ARGUMENTS

NAME = libftprintf.a

CFLAGS = -Wall -Werror -Wextra

CC = gcc

###################################################
## SOURCES

SRC =	ft_printf.c ft_print_utils.c

OBJ = $(SRC:.c=.o)

###################################################
## RULES

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

##################################################
## CLEAN

clean:
	rm -f $(OBJ) $(OBJB)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re

