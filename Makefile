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

LIB = 	libft/libft.a
FLAGS =	-Wall -Wextra -Werror
NAME = push_swap

all: $(NAME)

$(NAME): lib $(SRC)
	gcc $(FLAGS) -o $(NAME) $(SRC) $(LIB)

lib:
	@make -C libft/

clean:
	@make -C libft/ clean

fclean: clean
	rm -rf $(NAME)
	@make -C libft/ fclean

re: fclean all

.PHONY: all clean fclean re lib