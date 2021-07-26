#include "push_swap.h"

void	ft_push(t_stack **src, t_stack **dst)
{
	t_stack	*first_src;

	first_src = *src;
	*src = first_src->next;
	first_src->next = *dst;
	*dst = first_src;
}

void	pa(t_stack **a, t_stack **b)
{
	if (*b)
		ft_push(b, a);
	write(1, "pa\n", 3);
}

void	pb(t_stack **a, t_stack **b)
{
	if (*a)
		ft_push(a, b);
	write(1, "pb\n", 3);
}
