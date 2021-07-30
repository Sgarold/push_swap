#include "push_swap.h"

int	find_nearest_index(t_stack **a, int index)
{
	t_stack *temp;
	int min_index;
	int next_index;

	temp = *a;
	min_index = 2147483647;
	next_index = 2147483647;
	while (temp)
	{
		if (temp->index < next_index && temp->index > index)
			next_index = temp->index;
		if (temp->index < min_index)
			min_index = temp->index;
		temp = temp->next;
	}
	if (next_index == 2147483647)
		return (min_index);
	return (next_index);
}

void	equal_moves(t_stack **a, t_stack **b, t_stack **a_t, t_stack **b_t)
{
	if ((*a_t)->lift_step == (*b_t)->lift_step)
	{
		if ((*a_t)->lift_step == 1)
		{
			while ((*a_t)->moves && (*b_t)->moves)
			{
				rr(a, b);
				(*a_t)->moves--;
				(*b_t)->moves--;
			}
		}
		else
		{
			while ((*a_t)->moves && (*b_t)->moves)
			{
				rrr(a, b);
				(*a_t)->moves--;
				(*b_t)->moves--;
			}
		}
	}
}

void	not_equal_moves(t_stack **a, t_stack **b, t_stack *a_t, t_stack *b_t)
{
	while (a_t->moves--)
	{
		if (a_t->lift_step == 1)
			ra(a);
		else
			rra(a);
	}
	while (b_t->moves--)
	{
		if (b_t->lift_step == 1)
			rb(b);
		else
			rrb(b);
	}
}

void	moving(t_stack **a, t_stack **b, int min_mvs)
{
	t_stack *a_t;
	t_stack *b_t;
	int next_index;

	a_t = *a;
	b_t = *b;
	while (b_t->sum_moves != min_mvs)
		b_t = b_t->next;
	next_index = find_nearest_index(a, b_t->index);
	while (a_t->index != next_index)
		a_t = a_t->next;
	equal_moves(a, b, &a_t, &b_t);
	not_equal_moves(a, b, a_t, b_t);
}

void spin(t_stack **a)
{
	t_stack *temp;
	int moves;
	int step;

	filling_moves(a);
	temp = *a;
	while (temp->index)
		temp = temp->next;
	moves = temp->moves;
	step = temp->lift_step;
	while (moves--)
	{
		if (step > 0)
			ra(a);
		else
			rra(a);
	}
}
