
NAME = push_swap
CFLAGS = -Wall -Wextra -Werror
CC = cc
SRC = push_swap.c ops.c
OBJ = $(SRC:.c=.o)
#BONUS_SRC = pipex_utils_1_bonus.c pipex_utils_2_bonus.c pipex_bonus.c
#BONUS_OBJ = pipex_utils_1_bonus.o pipex_utils_2_bonus.o pipex_bonus.o
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

bonus : $(NAME) $(BONUS_SRC)
	make WITH_BONUS=1 $(NAME)