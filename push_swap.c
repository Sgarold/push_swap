#include "push_swap.h"
#include "libft/libft.h"

int	find_max(t_stack *a, long last_max)
{
	int	max;

	max = -2147483648;
	while (a)
	{
		if (a->nb >= max && a->nb < last_max)
			max = a->nb;
		a = a->next;
	}
	return (max);
}

int	count_of_list(t_stack *a)
{
	int		count;
	t_stack	*temp;

	temp = a;
	count = 0;
	while (temp)
	{
		temp = temp->next;
		count++;
	}
	return (count);
}

void	markup_index(t_stack **a)
{
	t_stack	*temp;
	int		i;
	int		max;

	i = count_of_list(*a);
	max = find_max(*a, 2147483648);
	while (i > 0)
	{
		i--;
		temp = (*a);
		while (temp->nb != max)
			temp = temp->next;
		temp->index = i;
		max = find_max(*a, max);
	}
}

void	fill_stay_in(t_stack **a)
{
	t_stack	*temp;

	temp = *a;
	while (temp)
	{
		temp->stay_in = 0;
		temp = temp->next;
	}
}

int	main(int argc, char **argv)
{
	t_stack	**a;
	t_stack	**b;
	int		err_flag;

	a = NULL;
	b = NULL;
	a = stack_init(a);
	b = stack_init(b);
	if (argc == 1)
		err_flag = 1;
	while (argc > 1)
	{
		argc--;
		arg_parser(argv[argc], &err_flag, a);
	}
	check_error(a, err_flag);
	markup_index(a);
	fill_stay_in(a);
	compare_markup(a, b);
	free_stacks(a, b);
}
