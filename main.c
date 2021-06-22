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
		if ((nb > 2147483648 && sign == -1) || (nb > INT32_MAX && sign == 1))
			*err = 1;
	}
	if (*s && (*s < '0' || *s > '9'))
		*err = 1;
	return (sign * nb);
}

void	check_error(t_stack **a, int err)
{
	t_stack *now;
	t_stack *any;

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

void	index(t_stack **a)
{
	t_stack	*temp;
	int		i;
	int		check;
	int		max;

	i = 1;
	max = find_max(*a, 2147483647);
	temp = (*a);
	while (temp)
	{
		if () 
	}
}

int	main(int argc, char **argv)
{
	t_stack	**a;
	t_stack	**b;
	t_stack	*temp;
	int err_flag;

	err_flag = 0;
	a = stack_init(a);
	b = stack_init(b);
	while (argc > 1)
	{
		argc--;
		push_front(ft_atoi(argv[argc], &err_flag), a);/* dont forget to change atoi to ft_atoi!!!*/
	}
	check_error(a, err_flag);
	index(a);
	// sorting_3(a, b);
	free_stacks(a, b);
}

	// int i;
	// for (i = 0; i < 10; i++)
	// {
	// 	rra(a);
	// 	temp = *a;
	// 	temp = last_elem(a);
	// 	printf("last = %d\n", temp->nb);
	// }