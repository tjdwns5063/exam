# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seongjki <seongjk@student.42seoul.kr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/02 12:28:36 by seongjki          #+#    #+#              #
#    Updated: 2021/12/06 11:52:13 by seongjki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC_DIR = ./src/
SRC_NAME = ft_printf.c
SRC = $(addprefix $(SRC_DIR),$(SRC_NAME))

OBJ_NAME = $(SRC:.c=.o)
OBJ = $(OBJ_NAME)

LIB_DIR = ./libft/
LIB_NAME = ft
LIB = $(LIB_DIR)lib$(LIB_NAME).a

CC = gcc
CFLAGS = -Wall -Wextra -Werror
INCLUDE = -I./include -I./libft

AR = ar
AR_FLAGS = rc

all: $(NAME)

$(NAME): $(LIB) $(OBJ)
	cp $(LIB) ./$(NAME)
	$(AR) $(AR_FLAGS) $(NAME) $(OBJ)

$(LIB):
	make -C $(LIB_DIR) all

%.o: %.c
	$(CC) $(CLFAGS) $(INCLUDE) -c $< -o $@

clean:
	rm -f $(OBJ)
	make -C $(LIB_DIR) fclean

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
