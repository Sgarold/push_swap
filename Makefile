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
		stack_utils.c\
		arg_parser.c

OBJ = $(SRC:.c=.o)
LIB = libft/libft.a
FLAGS =	-Wall -Wextra -Werror
NAME = push_swap

all: lib $(NAME)

$(NAME): $(OBJ)
	gcc $(FLAGS) $(SRC) $(LIB) -o $(NAME)

%.o: %.c
	gcc $(FLAGS) -o $@ -c $<

lib:
	@make -C libft/

clean:
	@make -C libft/ clean
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)
	@make -C libft/ fclean

re: fclean all

.PHONY: all clean fclean re lib