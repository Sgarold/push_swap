#include "push_swap.h"

void	greater_than_mode(t_stack *a, t_markups *mode) // more than 25 lines
{
	int head;
	t_stack *temp;
	int count;
	int prev_index;


	head = count_of_list(a);
	while (head--)
	{
		temp = a;
		while (temp->index != head)
			temp = temp->next;
		count = 0;
		prev_index = head;
		if (temp->next)
			temp = temp->next;
		else
			temp = a;
		while (temp->index != head)
		{
			if (temp->index > prev_index)
			{
				count++;
				prev_index = temp->index;
			}
			if (temp->next)
				temp = temp->next;
			else
				temp = a;
		}
		if (count >= mode->size)
		{
			mode->size = count;
			mode->markup_head = head;
		}
	}
}

void	next_index_mode(t_stack *a, t_markups *mode) // more than 25 lines
{
	int head;
	t_stack *temp;
	int count;
	int prev_index;

	head = count_of_list(a);
	while (head--)
	{
		temp = a;
		while (temp->index != head)
			temp = temp->next;
		count = 0;
		prev_index = head;
		if (temp->next)
			temp = temp->next;
		else
			temp = a;
		while (temp->index != head)
		{
			if (temp->index == prev_index + 1)
			{
				count++;
				prev_index = temp->index;
			}
			if (temp->next)
				temp = temp->next;
			else
				temp = a;
		}
		if (count >= mode->size)
		{
			mode->size = count;
			mode->markup_head = head;
		}
	}
}

void	init_modes(t_markups **gt_mode, t_markups **ni_mode)
{
	*gt_mode = malloc(sizeof(t_markups));
	*ni_mode = malloc(sizeof(t_markups));
	(*gt_mode)->size = 0;
	(*ni_mode)->size = 0;
}

void	filling_gt(t_stack **a, t_markups *mode) // more than 25 lines
{
	t_stack *temp;
	int prev_index;

	temp = *a;
	while (temp->index != mode->markup_head)
		temp = temp->next;
	temp->stay_in = 1;
	prev_index = temp->index;
	if (temp->next)
		temp = temp->next;
	else
		temp = *a;
	while(temp->index != mode->markup_head)
	{
		if (temp->index > prev_index)
		{
			temp->stay_in = 1;
			prev_index = temp->index;
		}
		else
			temp->stay_in = 0;
		if (temp->next)
			temp = temp->next;
		else
			temp = *a;
	}
}

void	pushing(t_stack **a, t_stack **b)
{
	t_stack *temp;
	int i;

	temp = *a;
	i = count_of_list(*a);
	while (i--)
	{
		if (temp->stay_in == 1)
			ra(a);
		else
			pb(a, b);
		temp = *a;
	}
}

void	filling_moves(t_stack **stack)
{
	t_stack *temp;
	int moves_up;
	int moves_down;
	int half_count_list;

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

void	moves_of_nearest(t_stack **a, int index, t_moves **mvs)
{
	t_stack	*temp;
	t_moves	*moves;
	int		nearest_index;

	moves = *mvs;
	temp = *a;
	nearest_index = find_nearest_index(a, index);
	while (temp->index != nearest_index)
		temp = temp->next;
	moves->lift_step = temp->lift_step;
	moves->moves = temp->moves;
}

int	eq_mvs(int mvs_a, int mvs_b)
{
	int i;

	i = 0;
	while (mvs_a-- && mvs_b--)
		i++;
	return (i);
}

int	sum_moves(t_stack **a, t_stack **b)
{
	t_stack *temp;
	t_moves *mvs;
	int min_mvs;

	temp = *b;
	mvs = malloc(sizeof(t_moves));
	min_mvs = 2147483647;
	while (temp)
	{
		moves_of_nearest(a, temp->index, &mvs);
		if (mvs->lift_step == temp->lift_step)
			temp->sum_moves = temp->moves + mvs->moves - eq_mvs(mvs->moves, temp->moves);
		else
			temp->sum_moves = temp->moves + mvs->moves;
		if (temp->sum_moves < min_mvs)
			min_mvs = temp->sum_moves;
		temp = temp->next;
	}
	free(mvs);
	return(min_mvs);
}

void	moving(t_stack **a, t_stack **b, int min_mvs) // more than 25 lines
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
	if (a_t->lift_step == b_t->lift_step)
	{
		if (a_t->lift_step == 1)
		{
			while (a_t->moves && b_t->moves)
			{
				rr(a, b);
				a_t->moves--;
				b_t->moves--;
			}
		}
		else
		{
			while (a_t->moves && b_t->moves)
			{
				rrr(a, b);
				a_t->moves--;
				b_t->moves--;
			}
		}
	}
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

void	sorting(t_stack **a, t_stack **b)
{
	int i;

	pushing(a, b);
	i = count_of_list(*b);
	while (i--)
		one_sort_iter(a, b);
	spin(a);
}

void	filling_ni(t_stack **a, t_markups *mode) // more than 25
{
	t_stack *temp;
	int		prev_index;

	temp = *a;
	while (temp->index != mode->markup_head)
		temp = temp->next;
	temp->stay_in = 1;
	prev_index = temp->index;
	if (temp->next)
		temp = temp->next;
	else
		temp = *a;
	while (temp->index != mode->markup_head)
	{
		if (temp->index == prev_index + 1)
		{
			prev_index = temp->index;
			temp->stay_in = 1;
		}
		else
			temp->stay_in = 0;
		if (temp->next)
			temp = temp->next;
		else
			temp = *a;
	}
}

void	compare_markup(t_stack **a, t_stack **b)
{
	t_markups *gt_mode;
	t_markups *ni_mode;

	init_modes(&gt_mode, &ni_mode);
	greater_than_mode(*a, gt_mode);
	next_index_mode(*a, ni_mode);
	if (ni_mode->size == count_of_list(*a) - 1)
		spin(a);
	else
	{
		if (count_of_list(*a) <= 5)
			sorting_5(a, b);
		else
		{
			if (ni_mode->size <= gt_mode->size)
				filling_gt(a, gt_mode);
			else
				filling_ni(a, ni_mode);
			sorting(a, b);
		}
	}
	free(gt_mode);
	free(ni_mode);
}