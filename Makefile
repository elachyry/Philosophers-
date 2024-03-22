# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: melachyr <melachyr@student.1337.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/13 21:54:07 by melachyr          #+#    #+#              #
#    Updated: 2024/03/22 04:07:08 by melachyr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = 	srcs/tools/ft_atoi.c srcs/tools/ft_isdigit.c srcs/tools/ft_strcmp.c srcs/tools/ft_strlen.c\
		srcs/tools/ft_trim.c srcs/tools/ft_putstr_fd.c\
		srcs/utils/mutex_utils.c srcs/utils/time_utils.c srcs/utils/philo_utils.c srcs/utils/philo_printing_utils.c\
		srcs/utils/observation_utils.c srcs/utils/threads_utils.c\
		philo.c srcs/parsing.c srcs/init_variables.c srcs/start_program.c srcs/free_data.c
OBJS = $(SRCS:.c=.o)

all:$(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re
.SECONDARY: $(OBJS)