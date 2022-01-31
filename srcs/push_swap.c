/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gucamuze <gucamuze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 19:02:25 by gucamuze          #+#    #+#             */
/*   Updated: 2022/02/01 00:38:28 by gucamuze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_list **stack_a, int size)
{
	t_list **results;

	results = malloc(sizeof(t_list **));
	if (!results)
		exit(0);
	// printf("Sorting list of %d\n", size);
	// DEBUG__print_lst(*stack_a, 'd');
	if (size == 2)
		sort_two(*stack_a, results);
	else if (size == 3)
		sort_three(stack_a, results);
	else if (size <= 5)
		sort_upto_five(stack_a, results, size);
	else if (size <= 100)
		sort_upto_hundred(stack_a, results, size);
	// else
	// 	sort_big(*stack_a, size);
	// printf("final stack =>\n");
	// pretty_print(*stack_a, NULL);
	print_results(*results);
	// printf("1\n");
	ft_lstclear(stack_a, free);
	// printf("2\n");
	ft_lstsize(*results);
	// printf("3\n");
	// ft_lstclear(results, free);
	// printf("4\n");
	free(results);
}