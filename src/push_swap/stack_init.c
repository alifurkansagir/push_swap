/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsagir <alsagir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 20:32:07 by alsagir           #+#    #+#             */
/*   Updated: 2026/01/02 21:43:23 by alsagir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	init_node(t_stack_node *node, int n)
{
	node->value = n;
	node->push_cost = 0;
	node->index = 0;
	node->above_median = false;
	node->cheapest = false;
	node->target_node = NULL;
	node->next = NULL;
	node->prev = NULL;
}

static bool	append_node(t_stack_node **stack, int n)
{
	t_stack_node	*node;
	t_stack_node	*last_node;

	if (!stack)
		return (false);
	node = malloc(sizeof(t_stack_node));
	if (!node)
		return (false);
	init_node(node, n);
	if (!(*stack))
		*stack = node;
	else
	{
		last_node = find_last(*stack);
		last_node->next = node;
		node->prev = last_node;
	}
	return (true);
}

static void	free_and_exit_with_error(t_stack_node **a, char **argv, int argc)
{
	free_stack(a);
	if (argc == 2)
		free_matrix(argv);
	write(2, "Error\n", 6);
	exit(1);
}

static void	process_arg(t_stack_node **a, char **argv, int argc, char *arg)
{
	long	n;

	if (error_syntax(arg))
		free_and_exit_with_error(a, argv, argc);
	n = ft_atol(arg);
	if (n > INT_MAX || n < INT_MIN)
		free_and_exit_with_error(a, argv, argc);
	if (error_duplicate(*a, (int)n))
		free_and_exit_with_error(a, argv, argc);
	if (!append_node(a, (int)n))
		free_and_exit_with_error(a, argv, argc);
}

void	stack_init(t_stack_node **a, char **argv, int argc)
{
	int		i;
	char	**split_argv;

	i = 0;
	if (argc == 2)
		split_argv = ft_split(argv[1], ' ');
	else
		split_argv = argv + 1;
	if (argc == 2 && !split_argv)
		free_and_exit_with_error(a, NULL, 0);
	while (split_argv[i])
	{
		process_arg(a, split_argv, argc, split_argv[i]);
		i++;
	}
	if (argc == 2)
		free_matrix(split_argv);
}
