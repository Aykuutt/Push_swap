#include "push_swap.h"

static int	find_max_pos(t_node *stack)
{
	int	max_val;
	int	max_pos;
	int	pos;

	max_val = stack->index;
	max_pos = 0;
	pos = 0;
	while (stack)
	{
		if (stack->index > max_val)
		{
			max_val = stack->index;
			max_pos = pos;
		}
		stack = stack->next;
		pos++;
	}
	return (max_pos);
}

static void	push_back_to_a(t_data *data)
{
	int	max_pos;

	while (data->size_b > 0)
	{
		max_pos = find_max_pos(data->b);
		if (max_pos <= data->size_b / 2)
		{
			while (max_pos > 0)
			{
				rb(data, 1);
				max_pos--;
			}
		}
		else
		{
			while (max_pos < data->size_b)
			{
				rrb(data, 1);
				max_pos++;
			}
		}
		pa(data, 1);
	}
}

static int	get_chunk_size(int size)
{
	if (size <= 100)
		return (15);
	return (30);
}

void	sort_large(t_data *data)
{
	int	i;
	int	chunk;

	i = 0;
	chunk = get_chunk_size(data->size_a);
	while (data->a)
	{
		if (data->a->index <= i)
		{
			pb(data, 1);
			rb(data, 1);
			i++;
		}
		else if (data->a->index <= i + chunk)
		{
			pb(data, 1);
			i++;
		}
		else
			ra(data, 1);
	}
	push_back_to_a(data);
}