/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gucamuze <gucamuze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 19:02:25 by gucamuze          #+#    #+#             */
/*   Updated: 2022/02/07 11:09:46 by gucamuze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_list **stack_a, int size)
{
	t_list	**results;

	results = malloc(sizeof(t_list **));
	*results = NULL;
	if (!results)
		exit(0);
	if (size == 2)
		sort_two(*stack_a, results);
	else if (size == 3)
		sort_three(stack_a, results);
	else if (size <= 5)
		sort_upto_five(stack_a, results, size);
	else if (size <= 100)
		sort_upto_hundred(stack_a, results);
	else if (size <= 500)
		sort_upto_five_hundred(stack_a, results);
	print_results(*results);
	ft_lstclear(stack_a, free);
	ft_lstsize(*results);
	ft_lstclear(results, free);
	free(results);
}
