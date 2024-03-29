# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nlowe <nlowe@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/17 21:11:30 by nlowe             #+#    #+#              #
#    Updated: 2017/04/05 18:49:42 by nlowe            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC_PATH = src
SRC_NAME = arguments.c \
			buffer.c \
			controller.c \
			format.c \
			ft_printf.c \
			conversions.c \
			numbers.c \
			string.c \
			wide.c \
			flags.c

LIBFT = libft.a
LIBFT_PATH = libft

OBJ_PATH = obj
IFLAGS = -Iincludes -I$(addprefix $(LIBFT_PATH)/,includes)
LDFLAGS = -Llibft
LDLIBS = -lft
CC = gcc
CFLAGS  = -Werror -Wall -Wextra
OBJ_NAME = $(SRC_NAME:.c=.o)
SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	@echo "\033[93m----------------------\n| ft_printf compiled |\n|       @nlowe       |\n----------------------\033[0m"
	@libtool -static -o $@ $(OBJ) $(addprefix $(LIBFT_PATH)/,$(LIBFT))
	@ranlib $(NAME)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(CFLAGS) $(IFLAGS) -o $@ -c $^

$(LIBFT):
	@make -C$(LIBFT_PATH)

clean:
	@rm -d -rf $(OBJ_PATH)
	@make clean -C$(LIBFT_PATH)

fclean: clean
	@rm -f $(NAME)
	@make fclean -C$(LIBFT_PATH)

re: fclean all

withmain: $(NAME)
	@echo "\033[94m----------------------\n| main test compiled |\n|       @nlowe       |\n----------------------\033[0m"
	@touch test.txt
	@$(CC) $(IFLAGS) -L. -lftprintf -o test.out testing/main.c

.PHONYL: all, clean, fclean, re, withmain
