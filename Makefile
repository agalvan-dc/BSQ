# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: stelescu <stelescu@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/17 20:45:57 by agalvan-          #+#    #+#              #
#    Updated: 2026/02/18 15:10:10 by stelescu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Werror -Wextra -g

RMFLAGS = rm -f

NAME = BSQ

SOURCES =  main.c crear_matriz.c start.c

OBJECTS = $(SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS) 
	$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	$(RMFLAGS) $(OBJECTS)

fclean: clean
	$(RMFLAGS) $(NAME)

re: fclean all

.PHONY: all clean fclean re
