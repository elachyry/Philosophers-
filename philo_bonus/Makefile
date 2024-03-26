# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: melachyr <melachyr@student.1337.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/22 04:10:00 by melachyr          #+#    #+#              #
#    Updated: 2024/03/26 03:47:20 by melachyr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo_bonus
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = 	srcs/tools/ft_atoi.c srcs/tools/ft_isdigit.c srcs/tools/ft_strcmp.c srcs/tools/ft_strlen.c\
		srcs/tools/ft_trim.c srcs/tools/ft_putstr_fd.c\
		srcs/utils/time_utils_bonus.c srcs/utils/philo_printing_utils_bonus.c srcs/utils/philo_utils_bonus.c\
		srcs/utils/observation_utils_bonus.c\
		philo_bonus.c srcs/parsing_bonus.c srcs/init_variables_bonus.c srcs/start_program_bonus.c\
		srcs/free_data_bonus.c
OBJS = $(SRCS:.c=.o)

all:$(NAME)

$(NAME): $(OBJS) #-fsanitize=address -g3
	$(CC) -fsanitize=address -g3 $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re
.SECONDARY: $(OBJS)