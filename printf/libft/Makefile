# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seongjki <seongjk@student.42seoul.kr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/02 12:28:54 by seongjki          #+#    #+#              #
#    Updated: 2021/12/06 11:43:39 by seongjki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -c -Wall -Wextra -Werror
NAME = libft.a 
SOURCES = ft_memset.c ft_bzero.c ft_memcpy.c \
			ft_strlen.c ft_isalpha.c ft_isdigit.c \
			ft_isalnum.c ft_isascii.c ft_isprint.c \
			ft_toupper.c ft_tolower.c ft_atoi.c \
			ft_strlcat.c ft_strlcpy.c ft_strncmp.c \
			ft_strdup.c ft_strchr.c ft_strrchr.c \
			ft_strnstr.c ft_memccpy.c ft_memmove.c \
			ft_memchr.c ft_memcmp.c ft_calloc.c \
			ft_substr.c ft_strjoin.c ft_strtrim.c \
			ft_split.c ft_itoa.c ft_strmapi.c \
			ft_utoa.c ft_upper_xtoa.c \
			ft_long_xtoa.c \
			ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
			ft_putnbr_fd.c
B_SOURCES = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c \
			ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c \
			ft_lstclear.c ft_lstiter.c ft_lstmap.c
OBJECTS = $(SOURCES:.c=.o)
B_OBJECTS = $(B_SOURCES:.c=.o)

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $< -o $@ 

$(NAME): $(OBJECTS)
	ar cr $(NAME) $(OBJECTS)

bonus: $(OBJECTS) $(B_OBJECTS)
	ar cr $(NAME) $(OBJECTES) $(B_OBJECTS)

clean:
	rm -f $(OBJECTS) $(B_OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all
