#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				nb;
	int				index;
	struct s_stack	*next;
}			t_stack;

void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);
t_stack	*new_elem(int nb);
void	push_front(int nb, t_stack **a);
t_stack	*last_elem(t_stack **stack);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rra(t_stack **a);
t_stack	**stack_init(t_stack **stack);
void	free_stacks(t_stack **a, t_stack **b);

#endif