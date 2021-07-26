#include "push_swap.h"

void	sorting_3(t_stack **a, t_stack **b)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*third;

	first = *a;
	second = first->next;
	third = second->next;
	if (first->index > second->index && first->index > third->index)
	{
		ra(a);
		if (second->index > third->index)
			sa(a);
	}
	else if (second->index > first->index && second->index > third->index)
	{
		rra(a);
		if (first->index < third->index)
			sa(a);
	}
	else
	{
		if (first->index > second->index)
			sa(a);
	}
}

void	one_sort_iter(t_stack **a, t_stack **b)
{
	sorting_3(a, b);
	filling_moves(a);
	filling_moves(b);
	moving(a, b, sum_moves(a, b));
	pa(a, b);
}

void	sorting_5(t_stack **a, t_stack **b)
{
	int	count;

	count = count_of_list(*a);
	if (count == 2 && (*a)->index)
		sa(a);
	else if (count == 3)
		sorting_3(a, b);
	else if (count == 4)
	{
		pb(a, b);
		sorting_3(a, b);
		one_sort_iter(a, b);
		spin(a);
	}
	else if (count == 5)
	{
		pb(a, b);
		pb(a, b);
		sorting_3(a, b);
		one_sort_iter(a, b);
		one_sort_iter(a, b);
		spin(a);
	}
}
