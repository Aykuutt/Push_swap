#include "push_swap.h"

static void	push(t_node **dest, t_node **src)
{
	t_node	*top;

	if (!src || !*src)
		return ;
	top = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	top->next = *dest;
	top->prev = NULL;
	if (*dest)
		(*dest)->prev = top;
	*dest = top;
}

void	pa(t_data *data, int print)
{
	if (!data->b)
		return ;
	push(&(data->a), &(data->b));
	data->size_a++;
	data->size_b--;
	if (print)
		write(1, "pa\n", 3);
	data->count++;
}

void	pb(t_data *data, int print)
{
	if (!data->a)
		return ;
	push(&(data->b), &(data->a));
	data->size_b++;
	data->size_a--;
	if (print)
		write(1, "pb\n", 3);
	data->count++;
}