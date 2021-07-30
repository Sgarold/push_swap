#include "push_swap.h"

t_stack	*next_elem(t_stack *temp, t_stack *a)
{
	if (temp->next)
		temp = temp->next;
	else
		temp = a;
	return (temp);
}

void	search_max_count(int count, t_markups *mode, int head)
{
	if (count >= mode->size)
	{
		mode->size = count;
		mode->markup_head = head;
	}
}

void	init_modes(t_markups **gt_mode, t_markups **ni_mode)
{
	*gt_mode = malloc(sizeof(t_markups));
	*ni_mode = malloc(sizeof(t_markups));
	if (!gt_mode || !ni_mode)
		exit(7);
	(*gt_mode)->size = 0;
	(*ni_mode)->size = 0;
}

void	pushing(t_stack **a, t_stack **b)
{
	t_stack	*temp;
	int		i;

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

void	sorting(t_stack **a, t_stack **b)
{
	int	i;

	pushing(a, b);
	i = count_of_list(*b);
	while (i--)
		one_sort_iter(a, b);
	spin(a);
}
