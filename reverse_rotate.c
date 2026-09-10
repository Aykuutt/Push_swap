#include <push_swap.h>

static void	reverse_rotate(t_node **stack)
{
	t_node	*last;

	if(!stack || !*stack || !(*stack)->next)
		return ;
	last = *stack;
	while(last->next)
		last = last->next;

	last->prev->next = NULL;

	last->next = *stack;
	last->prev = NULL;
	(*stack)->prev = last;

	*stack = last;
}

void	rra(t_data *data, int print)
{
	reverse_rotate(&(data->a));
	if (print)
		write(1, "rra\n", 4);
	data->count++;
}

void	rrb(t_data *data, int print)
{
	reverse_rotate(&(data->b));
	if (print)
		write(1, "rrb\n", 4);
	data->count++;
}

void	rrr(t_data *data, int print)
{
	reverse_rotate(&(data->a));
	reverse_rotate(&(data->b));
	if (print)
		write(1, "rrr\n", 4);
	data->count++;
}