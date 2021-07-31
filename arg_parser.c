#include "push_swap.h"
#include "libft/libft.h"

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

int	ps_atoi(const char *s, int *err)
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

int	space_check(char *s)
{
	while (*(s++))
	{
		if (*s == ' ')
			return (1);
	}
	return (0);
}

void	arg_parser(char *arg, int *err_flag, t_stack **a)
{
	char	**arr;
	int		i;

	i = 0;
	if (space_check(arg))
	{
		arr = ft_split(arg, ' ');
		while (arr[i] != NULL)
			i++;
		while (--i > -1)
			push_front(ps_atoi(arr[i], err_flag), a);
		free(arr);
	}
	else
		push_front(ps_atoi(arg, err_flag), a);
}
