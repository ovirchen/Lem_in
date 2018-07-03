# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ovirchen <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/25 12:45:37 by ovirchen          #+#    #+#              #
#    Updated: 2017/10/25 12:45:38 by ovirchen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

SRCS = 	src/main.c \
		src/parser.c \
		src/check_add_rooms.c \
		src/find_way.c \
		src/print_way.c \
		src/free.c \

CC = gcc

OBJ = $(SRCS:src/%.c=%.o)

HEADERS = includes/lem_in.h \
		libft/libft.h \
		libftprintf/libftprintf.h \

LIBS = libft/libft.a libftprintf/libftprintf.a

FLAGS = -g -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) -o $(NAME) $(OBJ) $(LIBS) $(FLAGS)

$(OBJ): $(SRCS) $(HEADERS)
	@make -C libftprintf
	@$(CC) -c $(SRCS) -I $(HEADERS)
	@echo "\033[31mlem-in \033[33mMAKED\033[0m"

clean:
	@rm -f $(OBJ)
	@make clean -C libftprintf
	@echo "\033[33mCLEANED\033[0m"

fclean: clean
	@rm -f $(NAME)
	@make fclean -C libftprintf
	@echo "\033[33mCLEANED ALL\033[0m"

re: fclean all

.PHONY: all clean fclean re