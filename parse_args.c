#include "push_swap.h"

static void	free_split(char **args)
{
	int	i;

	if (!args)
		return ;
	i = 0;
	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free(args);
}

static int	parse_split_args(t_data *data, char **split_args)
{
	int	j;

	j = 0;
	if (!split_args[0])
		return (0);
	while (split_args[j])
	{
		if (!parse_and_add(data, split_args[j]))
			return (0);
		j++;
	}
	return (1);
}

int	process_args(t_data *data, int argc, char **argv)
{
	int		i;
	char	**split_args;

	i = 1;
	while (i < argc)
	{
		split_args = ft_split(argv[i], ' ');
		if (!split_args)
			return (0);
		if (!parse_split_args(data, split_args))
		{
			free_split(split_args);
			return (0);
		}
		free_split(split_args);
		i++;
	}
	return (1);
}