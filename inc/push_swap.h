/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsagir <alsagir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 20:32:07 by alsagir           #+#    #+#             */
/*   Updated: 2026/01/02 21:43:22 by alsagir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

typedef struct s_stack_node
{
	int					value;
	int					index;
	int					push_cost;
	bool				above_median;
	bool				cheapest;
	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}	t_stack_node;

/*
** Handle errors and memory freeing
*/
void			free_stack(t_stack_node **stack);
void			free_errors(t_stack_node **a);
int				error_syntax(char *str_n);
int				error_duplicate(t_stack_node *a, int n);
void			free_matrix(char **argv);

/*
** Stack creation and initialization
*/
void			stack_init(t_stack_node **a, char **argv, int argc);
long			ft_atol(const char *s);
void			init_nodes_a(t_stack_node *a, t_stack_node *b);
void			init_nodes_b(t_stack_node *a, t_stack_node *b);
void			current_index(t_stack_node *stack);
void			set_cheapest(t_stack_node *stack);
t_stack_node	*get_cheapest(t_stack_node *stack);
void			prep_for_push(t_stack_node **stack,
					t_stack_node *top_node, char stack_name);

/*
** Stack Utils
*/
int				stack_len(t_stack_node *stack);
t_stack_node	*find_last(t_stack_node *stack);
bool			stack_sorted(t_stack_node *stack);
t_stack_node	*find_min(t_stack_node *stack);
t_stack_node	*find_max(t_stack_node *stack);

/*
** Commands
*/
void			sa(t_stack_node **a, bool print);
void			sb(t_stack_node **b, bool print);
void			ss(t_stack_node **a, t_stack_node **b, bool print);
void			ra(t_stack_node **a, bool print);
void			rb(t_stack_node **b, bool print);
void			rr(t_stack_node **a, t_stack_node **b, bool print);
void			rra(t_stack_node **a, bool print);
void			rrb(t_stack_node **b, bool print);
void			rrr(t_stack_node **a, t_stack_node **b, bool print);
void			pa(t_stack_node **a, t_stack_node **b, bool print);
void			pb(t_stack_node **b, t_stack_node **a, bool print);

/*
** Algorithm
*/
void			sort_three(t_stack_node **a);
void			sort_stacks(t_stack_node **a, t_stack_node **b);
void			sort_chunks(t_stack_node **a, t_stack_node **b);
void			sort_radix(t_stack_node **a, t_stack_node **b);
/*
** Shared sort helpers (kept minimal for norm rules)
*/
void			quick_sort(int *arr, int left, int right);
int			*build_sorted_array(t_stack_node *a, int len);
int			rank_of(int *arr, int len, int value);
void			map_indices(t_stack_node *a);
int			get_max_bits(int len);

/*
** Init helpers
*/
void			calculate_cost(t_stack_node *a, int len_a, int len_b);
void			cost_analysis_a(t_stack_node *a, t_stack_node *b);
void			set_target_a(t_stack_node *a, t_stack_node *b);

#endif
