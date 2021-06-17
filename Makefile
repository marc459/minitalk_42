# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msantos- <msantos-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/17 16:49:30 by msantos-          #+#    #+#              #
#    Updated: 2021/06/17 19:44:14 by msantos-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER = server
CLIENT = client

SERVER_SRCS = server.c
CLIENT_SRCS = client.c
SERVER_OBJS = $(SERVER_SRCS:.c = .o)
CLIENT_OBJS = $(CLIENT_SRCS:.c = .o)

CC = gcc
CFLAGS = -Wall -Werror -Wextra

%.o: %.c
	$(CC) $@ -c $^

all: server client
	git submodule update

server: $(SERVER_OBJS)
	$(CC) $(SERVER_OBJS) -o $(SERVER)

client: $(CLIENT_OBJS)
	$(CC) $(CLIENT_OBJS) -o $(CLIENT)

clean:
	rm -rf $(SERVER_OBJS) $(CLIENT_OBJS)

fclean: clean
	rm -rf $(SERVER) $(CLIENT)

re: fclean all

