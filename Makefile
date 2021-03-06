# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msantos- <msantos-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/17 16:49:30 by msantos-          #+#    #+#              #
#    Updated: 2021/07/02 21:31:50 by msantos-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#PROGRAMS
SERVER = server
CLIENT = client

#LIBS
LIBFT = libft_42/libft.a
PRINTF = ft_printf_42/libftprintf.a
LIBS = $(LIBFT) $(PRINTF)

INCLUDES = -I ./includes

#PATHS
OBJ_PATH = ./objs
SRC_PATH = ./srcs

#SRCS
SERVER_SRCS = server.c utils.c
CLIENT_SRCS = client.c utils.c
SERVER_OBJS = $(SERVER_SRCS:.c=.o)
CLIENT_OBJS = $(CLIENT_SRCS:.c=.o)

#OBJS
SERVER_OBJ = $(addprefix $(OBJ_PATH)/,$(SERVER_SRCS:.c=.o))
CLIENT_OBJ = $(addprefix $(OBJ_PATH)/,$(CLIENT_SRCS:.c=.o))

#FLAGS
CC = gcc
CFLAGS = -Wall -Werror -Wextra

#INSTRUCTIONS
all: submodule ft_printf libft server client

#EVERY TIME A .O IS CALLED AS AN INSTRUCTION THIS WILL BE CREATED IN OBJ_PATH
$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir -p $(OBJ_PATH) 2> /dev/null || true
	@$(CC) $(INCLUDES) -o $@ -c $^

submodule:
	@git submodule init
	@git submodule update --remote

#CHECKS THE EXISTANCE OF AN COMPILING FTPRINTF LIBRARY 
ft_printf:
	@make -C ft_printf_42  > /dev/null
libft:
	@make -C libft_42 > /dev/null

server: $(SERVER_OBJ)
	$(CC) $(SERVER_OBJ) $(LIBFT) $(PRINTF) -o $(SERVER)

client: $(CLIENT_OBJ)
	@$(CC) $(CLIENT_OBJ) $(LIBFT) $(PRINTF) -o $(CLIENT)

clean:
	@rm -rf $(OBJ_PATH)

fclean: clean
	@rm -rf $(SERVER) $(CLIENT)
	@make fclean -C ft_printf_42 > /dev/null
	@make fclean -C libft_42 > /dev/null

re: fclean all
