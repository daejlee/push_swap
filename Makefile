# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daejlee <daejlee@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/09 15:07:02 by daejlee           #+#    #+#              #
#    Updated: 2022/09/09 15:07:02 by daejlee          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CFLAGS = -Wall -Wextra -Werror
CC = cc
SRC = push_swap.c ps_ops1.c ps_ops2.c ps_ops3.c ps_utils1.c ps_utils2.c ps_utils3.c ps_utils4.c ps_low_args.c
OBJ = $(SRC:.c=.o)
LIBFT = ./libft_garage/libft.a
LIBFT_DIR = ./libft_garage

ifdef WITH_BONUS
	OBJ_FILES = $(BONUS_OBJ)
	SRC_FILES = $(BONUS_SRC)
else
	OBJ_FILES = $(OBJ)
	SRC_FILES = $(SRC)
endif

all : $(NAME)

$(NAME) : $(OBJ_FILES) $(LIBFT)
#	$(CC) $(CFLAGS) -o $(NAME) $(OBJ_FILES) -lft -L$(LIBFT_DIR)
	$(CC) -g $(CFLAGS) -o $(NAME) $(SRC) $(LIBFT_DIR)/libft/*.c $(LIBFT_DIR)/ft_printf/*.c 

$(OBJ_FILES) : $(SRC_FILES)
	$(CC) $(CFLAGS) -c $(SRC_FILES)

$(LIBFT) :
	cd $(LIBFT_DIR); $(MAKE)

clean :
	rm -f $(OBJ_FILES) $(BONUS_OBJ)
	make -C libft_garage/ clean

fclean :
	rm -f $(OBJ_FILES) $(BONUS_OBJ) $(NAME)
	make -C libft_garage/ fclean

re :
	$(MAKE) fclean
	$(MAKE) all
