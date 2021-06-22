#include "push_swap.h"

void	reverse(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;
	t_stack	*prev_last;
	t_stack	*temp;

	if (*stack)
	{
		first = *stack;
		prev_last = *stack;
		while (prev_last->next)
		{
			prev_last = prev_last->next;
			if (prev_last->next)
			{
				temp = prev_last;
			}
			else
				last = prev_last;
		}
		prev_last = temp;
		*stack = last;
		last->next = first;
		prev_last->next = NULL;
	}
}

void	rra(t_stack **a)
{
	reverse(a);
	write(1, "rra\n", 4);
}

void	rrb(t_stack **b)
{
	reverse(b);
	write(1, "rrb\n", 4);
}

void	rrr(t_stack **a, t_stack **b)
{
	reverse(a);
	reverse(b);
	write(1, "rrr\n", 4);
}
