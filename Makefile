# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marcos <marcos@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/17 16:49:30 by msantos-          #+#    #+#              #
#    Updated: 2021/06/18 14:32:50 by marcos           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#PROGRAMS
SERVER = server
CLIENT = client

#LIBS
LIBFT = libft_42/libft.a
PRINTF = ft_printf_42/libftprintf.a
LIBS = $(LIBFT) $(PRINTF)


#PATHS
OBJ_PATH = ./objs
SRC_PATH = ./srcs

#SRCS
SERVER_SRCS = server.c
CLIENT_SRCS = client.c
SERVER_OBJS = $(SERVER_SRCS:.c=.o)
CLIENT_OBJS = $(CLIENT_SRCS:.c=.o)

#OBJS
SERVER_OBJ = $(addprefix $(OBJ_PATH)/,$(SERVER_SRCS:.c=.o))
CLIENT_OBJ = $(addprefix $(OBJ_PATH)/,$(CLIENT_SRCS:.c=.o))

#FLAGS
CC = gcc
CFLAGS = -Wall -Werror -Wextra

#INSTRUCTIONS
all: server client ft_printf
	@git submodule init
	@git submodule update

#EVERY TIME A .O IS CALLED AS AN INSTRUCCTION THIS WILL BE CREATED IN OBJ_PATH
$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	mkdir -p $(OBJ_PATH) 2> /dev/null || true
	$(CC) -o $@ -c $^

#CHECKS THE EXISTANCE OF AN COMPILING LIBRARY 
ft_printf:
	@if make -C ft_printf_42 2> /dev/null; then \
		echo ; \
	else \
		echo Error, no existe la libreria ft_printf; \
	fi

server: $(SERVER_OBJ)
	$(CC) $(SERVER_OBJ) $(LIBS) -o $(SERVER)

client: $(CLIENT_OBJ)
	$(CC) $(CLIENT_OBJ) $(LIBS) -o $(CLIENT)

clean:
	rm -rf $(OBJ_PATH)

fclean: clean
	rm -rf $(SERVER) $(CLIENT)
	@make fclean -C ft_printf_42
	@make fclean -C libft_42

re: fclean all
