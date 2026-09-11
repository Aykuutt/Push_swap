#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

# define STRAT_ADAPTIVE 0
# define STRAT_SIMPLE   1
# define STRAT_MEDIUM   2
# define STRAT_COMPLEX  3

# define OP_SA  0
# define OP_SB  1
# define OP_SS  2
# define OP_PA  3
# define OP_PB  4
# define OP_RA  5
# define OP_RB  6
# define OP_RR  7
# define OP_RRA 8
# define OP_RRB 9
# define OP_RRR 10

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_data
{
	t_node	*a;
	t_node	*b;
	int		size_a;
	int		size_b;
	int		bench_mode;
	int		strategy;
	int		ops[11];
	int		total_ops;
	double	disorder;
}	t_data;


void	sa(t_data *data, int print);
void	sb(t_data *data, int print);
void	ss(t_data *data, int print);
void	pa(t_data *data, int print);
void	pb(t_data *data, int print);
void	ra(t_data *data, int print);
void	rb(t_data *data, int print);
void	rr(t_data *data, int print);
void	rra(t_data *data, int print);
void	rrb(t_data *data, int print);
void	rrr(t_data *data, int print);

t_node	*node_new(int value);
void	node_add_back(t_node **stack, t_node *new_node);
void	free_stack(t_node **stack);
t_node	*node_last(t_node *stack);

char	**ft_split(char const *s, char c);
int		parse_and_add(t_data *data, char *str);
int		process_args(t_data *data, int argc, char **argv);

void	sort_small(t_data *data);
void	sort_three(t_data *data);
void	sort_simple(t_data *data);
void	sort_large(t_data *data);
void	sort_complex(t_data *data);

int		is_sorted(t_node *stack);
void	set_i(t_node *stack);
double	compute_disorder(t_node *stack, int size);
void	print_bench(t_data *data, int strat_used);

#endif