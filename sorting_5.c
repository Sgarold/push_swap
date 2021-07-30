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

void	filling_moves(t_stack **stack)
{
	t_stack	*temp;
	int		moves_up;
	int		moves_down;
	int		half_count_list;

	temp = *stack;
	moves_up = 0;
	moves_down = count_of_list(*stack);
	half_count_list = moves_down / 2;
	while (moves_up <= half_count_list)
	{
		temp->moves = moves_up;
		temp->lift_step = 1;
		moves_up++;
		temp = temp->next;
	}
	moves_down -= moves_up;
	while (temp)
	{
		temp->moves = moves_down;
		temp->lift_step = -1;
		moves_down--;
		temp = temp->next;
	}
}

void	one_sort_iter(t_stack **a, t_stack **b)
{
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
