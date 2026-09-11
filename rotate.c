#include "push_swap.h"

static void	rotate(t_node **stack)
{
	t_node	*first;
	t_node	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	*stack = first->next;
	(*stack)->prev = NULL;
	last = *stack;
	while (last->next)
		last = last->next;
	last->next = first;
	first->prev = last;
	first->next = NULL;
}

void	ra(t_data *data, int print)
{
	rotate(&(data->a));
	if (print)
		write(1, "ra\n", 3);
	data->ops[OP_RA]++;
	data->total_ops++;
}

void	rb(t_data *data, int print)
{
	rotate(&(data->b));
	if (print)
		write(1, "rb\n", 3);
	data->ops[OP_RB]++;
	data->total_ops++;
}

void	rr(t_data *data, int print)
{
	rotate(&(data->a));
	rotate(&(data->b));
	if (print)
		write(1, "rr\n", 3);
	data->ops[OP_RR]++;
	data->total_ops++;
}