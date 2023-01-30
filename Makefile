# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bbolat <bbolat@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/12 05:52:26 by bbolat            #+#    #+#              #
#    Updated: 2022/08/12 05:52:27 by bbolat           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER = server
CLIENT = client
SRC_client = client.c
SRC_server = server.c
CC = gcc
CFLAGS = -Wall -Werror -Wextra
all: $(SERVER) $(CLIENT) $(NAME)
$(CLIENT):
	$(CC) $(CFLAGS) $(SRC_client) -o $(CLIENT)
$(SERVER):
	$(CC) $(CFLAGS) $(SRC_server) -o $(SERVER)
clean:
	@rm -rf $(SERVER) $(CLIENT)
	@echo "\033[92mclean completed\033[0m"
fclean: clean
	@rm -rf $(SERVER) $(CLIENT) $(NAME)
	@echo "\033[92mf\033[0m"
	@echo "\033[30mu\033[40m"
re: clean all
.PHONY: all clean fclean re