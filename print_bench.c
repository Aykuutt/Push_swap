#include "push_swap.h"

static void	put_nbr_fd(long n, int fd)
{
	char	c;

	if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
	}
	if (n >= 10)
		put_nbr_fd(n / 10, fd);
	c = (n % 10) + '0';
	write(fd, &c, 1);
}

static void	print_bench_ops(t_data *data)
{
	write(2, "[bench] sa: ", 12);
	put_nbr_fd(data->ops[OP_SA], 2);
	write(2, " sb: ", 5);
	put_nbr_fd(data->ops[OP_SB], 2);
	write(2, " ss: ", 5);
	put_nbr_fd(data->ops[OP_SS], 2);
	write(2, " pa: ", 5);
	put_nbr_fd(data->ops[OP_PA], 2);
	write(2, " pb: ", 5);
	put_nbr_fd(data->ops[OP_PB], 2);
	write(2, "\n[bench] ra: ", 13);
	put_nbr_fd(data->ops[OP_RA], 2);
	write(2, " rb: ", 5);
	put_nbr_fd(data->ops[OP_RB], 2);
	write(2, " rr: ", 5);
	put_nbr_fd(data->ops[OP_RR], 2);
	write(2, " rra: ", 6);
	put_nbr_fd(data->ops[OP_RRA], 2);
	write(2, " rrb: ", 6);
	put_nbr_fd(data->ops[OP_RRB], 2);
	write(2, " rrr: ", 6);
	put_nbr_fd(data->ops[OP_RRR], 2);
	write(2, "\n", 1);
}

static void	print_bench_strategy(int strat)
{
	write(2, "[bench] strategy: ", 18);
	if (strat == STRAT_SIMPLE)
		write(2, "Simple / O(n^2)\n", 16);
	else if (strat == STRAT_MEDIUM)
		write(2, "Medium / O(n*sqrt(n))\n", 22);
	else if (strat == STRAT_COMPLEX)
		write(2, "Complex / O(n*log(n))\n", 22);
	else
		write(2, "Adaptive\n", 9);
}

void	print_bench(t_data *data, int strat_used)
{
	long	pct_int;
	long	pct_dec;

	pct_int = (long)(data->disorder * 100);
	pct_dec = (long)(data->disorder * 10000) % 100;
	write(2, "[bench] disorder: ", 18);
	put_nbr_fd(pct_int, 2);
	write(2, ".", 1);
	if (pct_dec < 10)
		write(2, "0", 1);
	put_nbr_fd(pct_dec, 2);
	write(2, "%\n", 2);
	print_bench_strategy(strat_used);
	write(2, "[bench] total_ops: ", 19);
	put_nbr_fd(data->total_ops, 2);
	write(2, "\n", 1);
	print_bench_ops(data);
}