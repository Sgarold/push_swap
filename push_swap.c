#include "push_swap.h"

int	ft_atoi(const char *s, int *err)
{
	int		sign;
	long	nb;

	nb = 0;
	sign = 1;
	while ((*s == 32) || (*s > 8 && *s < 14))
		s++;
	if (*s == 45 || *s == 43)
	{
		if (*s == 45)
			sign = -1;
		s++;
	}
	while (*s >= 48 && *s <= 57)
	{
		nb = nb * 10 + *s - 48;
		s++;
		if ((nb > 2147483648 && sign == -1) || (nb > 2147483647 && sign == 1))
			*err = 1;
	}
	if (*s && (*s < '0' || *s > '9'))
		*err = 1;
	return (sign * nb);
}

void	check_error(t_stack **a, int err)
{
	t_stack	*now;
	t_stack	*any;

	now = *a;
	while (now)
	{
		any = now->next;
		while (any)
		{
			if (now->nb == any->nb)
				err = 1;
			any = any->next;
		}
		now = now->next;
	}
	if (err)
	{
		write(1, "Error\n", 7);
		exit(2);
	}
}

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
	int		check;
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

// void print_stacks(t_stack **a, t_stack **b)
// {
// 	t_stack *temp;

// 	temp = *a;
// 	printf("STACK A:\n");
// 	while(temp)
// 	{
// 		printf("ind = %d, num = %d\n", temp->index, temp->nb);
// 		temp = temp->next;
// 	}
// 	temp = *b;
// 	printf("STACK B:\n");
// 	while (temp)
// 	{
// 		printf("ind = %d, num = %d\n", temp->index, temp->nb);
// 		temp = temp->next;
// 	}
// }

int	main(int argc, char **argv)
{
	t_stack	**a;
	t_stack	**b;
	int		err_flag;

	a = stack_init(a);
	b = stack_init(b);
	if (argc == 1)
		err_flag = 1;
	while (argc > 1)
	{
		argc--;
		push_front(ft_atoi(argv[argc], &err_flag), a);
	}
	check_error(a, err_flag);
	markup_index(a);
	fill_stay_in(a);
	compare_markup(a, b);
	// print_stacks(a, b);
	free_stacks(a, b);
}
