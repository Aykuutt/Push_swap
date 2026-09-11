#include "push_swap.h"

static int	get_max_bits(t_data *data)
{
	int	max_idx;
	int	max_bits;

	max_idx = data->size_a - 1;
	max_bits = 0;
	while ((max_idx >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

void	sort_complex(t_data *data)
{
	int	i;
	int	j;
	int	size;
	int	max_bits;

	i = 0;
	size = data->size_a;
	max_bits = get_max_bits(data);
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			if (((data->a->index >> i) & 1) == 1)
				ra(data, 1);
			else
				pb(data, 1);
			j++;
		}
		while (data->size_b > 0)
			pa(data, 1);
		i++;
	}
}