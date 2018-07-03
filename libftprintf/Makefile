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

NAME = libftprintf.a

SRCS = 	ft_strlen_uni.c \
		ft_printf.c \
		ft_itoa_base.c \
		ft_pointer.c \
		ft_string.c \
		ft_char.c \
		ft_number.c \
		flags.c \
		join.c \

OBJ = $(SRCS:%.c=%.o)

HEADERS = libftprintf.h ../libft/libft.h

FLAGS = -Wall -Wextra -Werror

CC = gcc

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

$(OBJ): $(SRCS) $(HEADERS)
	@make -C ../libft
	@$(CC) $(FLAGS) -c -I $(HEADERS) $(SRCS)

clean:
	@rm -f $(OBJ)
	@rm -f libftprintf.h.gch
	@make clean -C ../libft

fclean: clean
	@rm -f $(NAME)
	@make fclean -C ../libft

re: fclean all