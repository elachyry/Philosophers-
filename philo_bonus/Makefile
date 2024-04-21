# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: melachyr <melachyr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/22 04:10:00 by melachyr          #+#    #+#              #
#    Updated: 2024/04/21 21:04:33 by melachyr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo_bonus
CC = cc
CFLAGS = -Wall -Wextra -Werror #-fsanitize=thread -g3
SRCS = 	srcs/tools/ft_atoi.c srcs/tools/ft_isdigit.c srcs/tools/ft_strcmp.c srcs/tools/ft_strlen.c\
		srcs/tools/ft_strlen_2.c srcs/tools/ft_trim.c srcs/tools/ft_putstr_fd.c\
		srcs/utils/time_utils_bonus.c srcs/utils/philo_printing_utils_bonus.c srcs/utils/philo_utils_bonus.c\
		srcs/utils/observation_utils_bonus.c\
		philo_bonus.c srcs/parsing_bonus.c srcs/init_variables_bonus.c srcs/start_program_bonus.c\
		srcs/free_data_bonus.c
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
