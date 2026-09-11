#include "push_swap.h"

static int	get_min_pos(t_node *stack)
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

void	sort_three(t_data *data)
{
	int	a;
	int	b;
	int	c;

	a = data->a->index;
	b = data->a->next->index;
	c = data->a->next->next->index;
	if (a > b && b < c && a < c)
		sa(data, 1);
	else if (a > b && b > c)
	{
		sa(data, 1);
		rra(data, 1);
	}
	else if (a > b && b < c && a > c)
		ra(data, 1);
	else if (a < b && b > c && a < c)
	{
		sa(data, 1);
		ra(data, 1);
	}
	else if (a < b && b > c && a > c)
		rra(data, 1);
}

static void	push_min_to_b(t_data *data)
{
	int	pos;

	pos = get_min_pos(data->a);
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
	pb(data, 1);
}

void	sort_small(t_data *data)
{
	if (data->size_a == 2)
	{
		if (data->a->index > data->a->next->index)
			sa(data, 1);
	}
	else if (data->size_a == 3)
		sort_three(data);
	else if (data->size_a <= 5)
	{
		while (data->size_a > 3)
			push_min_to_b(data);
		sort_three(data);
		while (data->size_b > 0)
			pa(data, 1);
	}
}