#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

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
	int		count;
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
void	clean_exit(t_data *data, int error);

int		parse_arguments(int argc, char **argv, t_data *data);

#endif