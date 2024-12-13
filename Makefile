# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: idkahram <idkahram@student.42kocaeli.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/12 22:13:28 by idkahram          #+#    #+#              #
#    Updated: 2024/12/13 05:51:50 by idkahram         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk

SERVER = server

CLIENT = client

CC = cc

AR = ar rcs

CFLAGS = -Wall -Wextra -Werror

$(NAME):$(SERVER) $(CLIENT)

$(SERVER): server.c
		$(CC) $(CFLAGS) -o server server.c
		
$(CLIENT): client.c
		$(CC) $(CFLAGS) -o client client.c

all : $(NAME)

clean :
	@rm -f $(SERVER) $(CLIENT)

fclean : clean

re : fclean all

.PHONY: all clean fclean re