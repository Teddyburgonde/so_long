# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/24 10:00:04 by tebandam          #+#    #+#              #
#    Updated: 2023/12/24 10:00:07 by tebandam         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = so_long

SRCS = character_move.c \
collectible_capture.c \
display.c \
error_unclose_map.c \
find_player.c \
key_press.c \
main.c \
map_management.c \
parsing.c \
free.c

OBJS=$(SRCS:.c=.o)

RM=rm -f

CC= clang

CFLAGS= -Wall -Wextra -Werror -I./MLX42/include -I./libft/includes -g

MLXFLAGS= -ldl -lX11 -lglfw -lm -lz -lbsd -lXext 
all: $(NAME)

$(NAME) : $(OBJS)
	make --directory ./libft 
	make --directory ./MLX42/build
	$(CC) $(CFLAGS) $(OBJS) $(MLXFLAGS) ./libft/libft.a ./MLX42/build/libmlx42.a -o $@
	@if [ $$? -eq 0 ]; then \
		echo "\033[32;1mCompilation successful!\033[0m"; \
	fi

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ 

clean: 
	$(RM) $(OBJS)
fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re

