/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gucamuze <gucamuze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 18:25:34 by gucamuze          #+#    #+#             */
/*   Updated: 2022/02/07 10:59:51 by gucamuze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_doubles(long long number, int stack_index, t_list *stack)
{
	long long	stack_number;
	int			index;

	index = 0;
	while (stack && index < stack_index)
	{
		stack_number = *(long long *)stack->content;
		if (stack_number == number)
			return (0);
		stack = stack->next;
		index++;
	}
	return (1);
}

// Mode 1 -> classic; 2 -> reverse
int	is_sorted(t_list *stack, int mode)
{
	while (stack)
	{
		if (stack->next)
		{
			if (mode == 1)
			{
				if (*(int *)stack->content > *(int *)stack->next->content)
					return (0);
			}
			else
				if (*(int *)stack->content < *(int *)stack->next->content)
					return (0);
		}
		stack = stack->next;
	}
	return (1);
}
