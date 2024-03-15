# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: melachyr <melachyr@student.1337.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/13 21:54:07 by melachyr          #+#    #+#              #
#    Updated: 2024/03/15 04:02:10 by melachyr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
CC = cc
# CFLAGS = -Wall -Wextra -Werror
SRCS = 	srcs/tools/ft_atoi.c srcs/tools/ft_isdigit.c srcs/tools/ft_strcmp.c srcs/tools/ft_strlen.c\
		srcs/tools/ft_trim.c\
		srcs/philo.c srcs/parsing.c
OBJS = $(SRCS:.c=.o)

all:$(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all