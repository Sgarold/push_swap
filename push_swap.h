#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				nb;
	int				index;
	int				moves;
	int				sum_moves;
	int				lift_step;
	int				stay_in;
	int				nearest_index;
	struct s_stack	*next;
}			t_stack;

typedef struct s_markups
{
	int		markup_head;
	int		size;
}			t_markups;

typedef struct s_moves
{
	int		moves;
	int		lift_step;
}				t_moves;

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
void	rr(t_stack **a, t_stack **b);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);
t_stack	**stack_init(t_stack **stack);
void	free_stacks(t_stack **a, t_stack **b);
void	sorting3(t_stack **a, t_stack **b);
void	compare_markup(t_stack **a, t_stack **b);
int 	count_of_list(t_stack *a);
void fill_stay_in(t_stack **a);
void print_stacks(t_stack **a, t_stack **b);

#endif