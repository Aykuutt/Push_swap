#include "push_swap.h"

static int	find_min_pos(t_node *stack)
{
	int	min_val;
	int	min_pos;
	int	pos;

	min_val = stack->index;
	min_pos = 0;
	pos = 0;
	while (stack)
	{
		if (stack->index < min_val)
		{
			min_val = stack->index;
			min_pos = pos;
		}
		stack = stack->next;
		pos++;
	}
	return (min_pos);
}

static void	bring_min_to_top(t_data *data)
{
	int	pos;

	pos = find_min_pos(data->a);
	if (pos <= data->size_a / 2)
	{
		while (pos > 0)
		{
			ra(data, 1);
			pos--;
		}
	}
	else
	{
		while (pos < data->size_a)
		{
			rra(data, 1);
			pos++;
		}
	}
}

void	sort_simple(t_data *data)
{
	while (data->size_a > 0)
	{
		bring_min_to_top(data);
		pb(data, 1);
	}
	while (data->size_b > 0)
		pa(data, 1);
}