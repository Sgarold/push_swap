#include "push_swap.h"

void	ft_swap(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*temp;

	first = *stack;
	second = first->next;
	temp = second->next;
	first->next = temp;
	second->next = first;
	*stack = second;
}

void	sa(t_stack **a)
{
	if (*a && (*a)->next)
		ft_swap(a);
	write(1, "sa\n", 3);
}

void	sb(t_stack **b)
{
	if (*b && (*b)->next)
		ft_swap(b);
	write(1, "sb\n", 3);
}

void	ss(t_stack **a, t_stack **b)
{
	if (*a && (*a)->next)
		ft_swap(a);
	if (*b && (*b)->next)
		ft_swap(b);
	write(1, "ss\n", 3);
}
