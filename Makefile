##
## EPITECH PROJECT, 2018
## makefile
## File description:
## makefile
##


NAME = mysh

SRC = 	src/main.c				\
		src/do_minishell.c		\
		src/utils.c				\
		src/exec.c				\
		src/cd.c				\
		src/simple_cd.c			\
		src/cd_home.c			\
		src/unsetenv.c			\
		src/my_realloc.c		\
		src/print_env.c			\
		src/utils2.c

CFLAGS = -W -Wall -Wextra -I ./include

OBJ = $(SRC:%.c=%.o)

LIB = -L ./lib/my -lmy

CC = gcc

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C ./lib/my/
	$(CC) -o $(NAME) $(OBJ) $(LIB)

clean:
	rm -f $(OBJ)
	$(MAKE) clean -C ./lib/my

fclean:	clean
	rm -f $(NAME)
	$(MAKE) fclean -C ./lib/my

re:	fclean all
