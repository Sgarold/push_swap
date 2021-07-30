#include "push_swap.h"

void	greater_than_mode(t_stack *a, t_markups *mode)
{
	int		head;
	t_stack	*temp;
	int		count;
	int		prev_index;

	head = count_of_list(a);
	while (head--)
	{
		temp = a;
		while (temp->index != head)
			temp = temp->next;
		count = 0;
		prev_index = head;
		temp = next_elem(temp, a);
		while (temp->index != head)
		{
			if (temp->index > prev_index)
			{
				count++;
				prev_index = temp->index;
			}
			temp = next_elem(temp, a);
		}
		search_max_count(count, mode, head);
	}
}

void	next_index_mode(t_stack *a, t_markups *mode)
{
	int		head;
	t_stack	*temp;
	int		count;
	int		prev_index;

	head = count_of_list(a);
	while (head--)
	{
		temp = a;
		while (temp->index != head)
			temp = temp->next;
		count = 0;
		prev_index = head;
		temp = next_elem(temp, a);
		while (temp->index != head)
		{
			if (temp->index == prev_index + 1)
			{
				count++;
				prev_index = temp->index;
			}
			temp = next_elem(temp, a);
		}
		search_max_count(count, mode, head);
	}
}

void	filling_gt(t_stack **a, t_markups *mode)
{
	t_stack	*temp;
	int		prev_index;

	temp = *a;
	while (temp->index != mode->markup_head)
		temp = temp->next;
	temp->stay_in = 1;
	prev_index = temp->index;
	temp = next_elem(temp, *a);
	while (temp->index != mode->markup_head)
	{
		if (temp->index > prev_index)
		{
			temp->stay_in = 1;
			prev_index = temp->index;
		}
		else
			temp->stay_in = 0;
		temp = next_elem(temp, *a);
	}
}

void	filling_ni(t_stack **a, t_markups *mode)
{
	t_stack	*temp;
	int		prev_index;

	temp = *a;
	while (temp->index != mode->markup_head)
		temp = temp->next;
	temp->stay_in = 1;
	prev_index = temp->index;
	temp = next_elem(temp, *a);
	while (temp->index != mode->markup_head)
	{
		if (temp->index == prev_index + 1)
		{
			prev_index = temp->index;
			temp->stay_in = 1;
		}
		else
			temp->stay_in = 0;
		temp = next_elem(temp, *a);
	}
}

void	compare_markup(t_stack **a, t_stack **b)
{
	t_markups	*gt_mode;
	t_markups	*ni_mode;

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
