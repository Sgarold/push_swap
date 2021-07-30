#include "push_swap.h"

t_stack	*new_elem(int nb)
{
	t_stack	*new;

	new = NULL;
	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		exit(1);
	new->nb = nb;
	new->index = 0;
	new->next = NULL;
	return (new);
}

void	push_front(int nb, t_stack **a)
{
	t_stack	*new;

	if (*a)
	{
		new = new_elem(nb);
		new->next = *a;
		*a = new;
	}
	else
		*a = new_elem(nb);
}

t_stack	*last_elem(t_stack **stack)
{
	t_stack	*temp;

	temp = *stack;
	if (temp)
	{
		while (temp->next)
			temp = temp->next;
		return (temp);
	}
	return (NULL);
}

t_stack	**stack_init(t_stack **stack)
{
	stack = (t_stack **)malloc(sizeof(t_stack *));
	if (!stack)
		exit(1);
	*stack = NULL;
	return (stack);
}

void	free_stacks(t_stack **a, t_stack **b)
{
	t_stack	*tmp1;
	t_stack	*tmp2;

	free(b);
	tmp1 = *a;
	while (tmp1->next)
	{
		tmp2 = tmp1;
		tmp1 = tmp1->next;
		free(tmp2);
	}
	free(tmp1);
	free(a);
}
