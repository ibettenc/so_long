# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ibettenc <ibettenc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/26 19:36:14 by ibettenc          #+#    #+#              #
#    Updated: 2025/06/30 18:27:27 by ibettenc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

###################################################
## ARGUMENTS

NAME = a.out

CC = gcc

CFLAGS = -Wall -Werror -Wextra

MLX_FLAGS = -Lmlx -lmlx -lXext -lX11 -Imlx

LIBFT = libft/libft.a


###################################################
## SOURCES

SRC = load_map.c put_images.c main.c \
	ft_printf/ft_print_utils.c ft_printf/ft_printf.c \
	get_next_line/get_next_line_utils.c get_next_line/get_next_line.c \
	key_hook.c manage_window.c manage_animations.c floodfill.c player.c

OBJ = $(SRC:.c=.o)

###################################################
## RULES

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(MLX_FLAGS) $(LIBFT)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

##################################################
## CLEAN

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
