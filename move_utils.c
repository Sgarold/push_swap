#include "push_swap.h"

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
	if (!mvs)
		exit(7);
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
