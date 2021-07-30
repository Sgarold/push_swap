SRC =	push_swap.c\
		swap.c\
		push.c\
		rot.c\
		rev.c\
		compare_markup.c\
		move_utils.c\
		moving.c\
		sorting_5.c\
		sorting.c\
		stack_utils.c

OBJ = $(SRC:.c=.o)

NAME = push_swap

all:
	gcc $(SRC) -o $(NAME)