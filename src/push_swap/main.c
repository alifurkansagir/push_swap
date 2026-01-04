/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsagir <alsagir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 21:36:55 by alsagir           #+#    #+#             */
/*   Updated: 2026/01/02 21:36:58 by alsagir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;

	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	stack_init(&a, argv, argc);
	if (!stack_sorted(a))
	{
		int len = stack_len(a);
		if (len == 2)
			sa(&a, true);
		else if (len == 3)
			sort_three(&a);
		else if (len <= 100)
			sort_chunks(&a, &b);
		else if (len <= 500)
			sort_radix(&a, &b);
		else
			sort_stacks(&a, &b);
	}
	free_stack(&a);
	free_stack(&b);
	return (0);
}
