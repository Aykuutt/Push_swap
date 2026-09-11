#include "push_swap.h"

int	is_sorted(t_node *stack)
{
	if (!stack)
		return (1);
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	set_i(t_node *stack)
{
	t_node	*current;
	t_node	*runner;
	int		index;

	current = stack;
	while (current)
	{
		index = 0;
		runner = stack;
		while (runner)
		{
			if (runner->value < current->value)
				index++;
			runner = runner->next;
		}
		current->index = index;
		current = current->next;
	}
}

double	compute_disorder(t_node *stack, int size)
{
	t_node	*curr;
	t_node	*runner;
	long	mistakes;
	long	total_pairs;

	if (!stack || size <= 1)
		return (0.0);
	mistakes = 0;
	total_pairs = ((long)size * (size - 1)) / 2;
	curr = stack;
	while (curr)
	{
		runner = curr->next;
		while (runner)
		{
			if (curr->value > runner->value)
				mistakes++;
			runner = runner->next;
		}
		curr = curr->next;
	}
	return ((double)mistakes / (double)total_pairs);
}