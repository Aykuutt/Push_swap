#include "push_swap.h"

static void	init_data(t_data *data)
{
	int	i;

	data->a = NULL;
	data->b = NULL;
	data->size_a = 0;
	data->size_b = 0;
	data->bench_mode = 0;
	data->strategy = STRAT_ADAPTIVE;
	data->total_ops = 0;
	data->disorder = 0.0;
	i = 0;
	while (i < 11)
		data->ops[i++] = 0;
}

static int	parse_flag(char *arg, t_data *data)
{
	int	len;

	len = 0;
	while (arg[len])
		len++;
	if (len == 7 && arg[0] == '-' && arg[1] == '-' && arg[2] == 'b')
		return (data->bench_mode = 1, 1);
	if (len == 8 && arg[0] == '-' && arg[1] == '-' && arg[2] == 's')
		return (data->strategy = STRAT_SIMPLE, 1);
	if (len == 8 && arg[0] == '-' && arg[1] == '-' && arg[2] == 'm')
		return (data->strategy = STRAT_MEDIUM, 1);
	if (len == 9 && arg[0] == '-' && arg[1] == '-' && arg[2] == 'c')
		return (data->strategy = STRAT_COMPLEX, 1);
	if (len == 10 && arg[0] == '-' && arg[1] == '-' && arg[2] == 'a')
		return (data->strategy = STRAT_ADAPTIVE, 1);
	return (0);
}

static int	resolve_strategy(t_data *data)
{
	if (data->strategy != STRAT_ADAPTIVE)
		return (data->strategy);
	if (data->disorder < 0.20)
		return (STRAT_SIMPLE);
	if (data->disorder < 0.50)
		return (STRAT_MEDIUM);
	return (STRAT_COMPLEX);
}

static void	run_sort(t_data *data, int strat)
{
	if (data->size_a <= 5 && data->strategy == STRAT_ADAPTIVE)
		sort_small(data);
	else if (strat == STRAT_SIMPLE)
		sort_simple(data);
	else if (strat == STRAT_MEDIUM)
		sort_large(data);
	else if (strat == STRAT_COMPLEX)
		sort_complex(data);
}

int	main(int argc, char **argv)
{
	t_data	data;
	int		i;
	int		strat;

	if (argc < 2)
		return (0);
	init_data(&data);
	i = 1;
	while (i < argc && parse_flag(argv[i], &data))
		i++;
	if (i >= argc)
		return (0);
	if (!process_args(&data, argc - i + 1, &argv[i - 1]))
		return (free_stack(&data.a), write(2, "Error\n", 6), 1);
	set_i(data.a);
	data.disorder = compute_disorder(data.a, data.size_a);
	strat = resolve_strategy(&data);
	if (!is_sorted(data.a))
		run_sort(&data, strat);
	if (data.bench_mode)
		print_bench(&data, strat);
	free_stack(&data.a);
	free_stack(&data.b);
	return (0);
}