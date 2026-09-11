#include "push_swap.h"

static int	is_duplicate(t_node *stack, int num)
{
	while (stack)
	{
		if (stack->value == num)
			return (1);
		stack = stack->next;
	}
	return (0);
}

static int	is_valid_number(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

static int	get_number(char *str, int *error)
{
	int		i;
	long	sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i])
	{
		result = result * 10 + (str[i] - '0');
		if ((result * sign) > 2147483647 || (result * sign) < -2147483648)
		{
			*error = 1;
			return (0);
		}
		i++;
	}
	return ((int)(result * sign));
}

int	parse_and_add(t_data *data, char *str)
{
	int		num;
	int		error;
	t_node	*new_node;

	error = 0;
	if (!is_valid_number(str))
		return (0);
	num = get_number(str, &error);
	if (error || is_duplicate(data->a, num))
		return (0);
	new_node = node_new(num);
	if (!new_node)
		return (0);
	node_add_back(&(data->a), new_node);
	data->size_a++;
	return (1);
}