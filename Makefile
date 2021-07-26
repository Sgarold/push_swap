SRC = main.c ps_utils.c swap.c push.c rot.c rev.c compare_markup.c

OBJ = $(SRC:.c=.o)

NAME = push_swap

all:
	gcc $(SRC) -o push_swap