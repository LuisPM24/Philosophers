# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lpalomin <lpalomin@student.42malaga.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/29 14:28:38 by lpalomin          #+#    #+#              #
#    Updated: 2025/05/26 12:57:06 by lpalomin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
SRCS =	philo.c \
		init_utils.c \
		function_utils.c \
		free_utils.c \
		action_utils.c \
		philosopher_killer.c

OBJS = $(SRCS:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
