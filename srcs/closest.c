/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   closest.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gucamuze <gucamuze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 02:36:25 by gucamuze          #+#    #+#             */
/*   Updated: 2022/02/02 02:37:21 by gucamuze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		is_the_biggest(t_list *stack, int number)
{
	while (stack)
	{
		if (*(int *)stack->content > number)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int		is_the_smallest(t_list *stack, int number)
{
	while (stack)
	{
		if (*(int *)stack->content < number)
			return (0);
		stack = stack->next;
	}
	return (1);
}

/**
 *	MODE 1 for closest superior, mode 0 for closest inferior
**/
int		get_closest(t_list *stack, int number, int mode)
{
	int	closest;

	closest = number;
	if (mode)
	{
		while (stack)
		{
			if (*(int *)stack->content > number)
				if ((closest == number && *(int *)stack->content > number)
					|| (closest != number && *(int *)stack->content < closest))
					closest = *(int *)stack->content;
			stack = stack->next;
		}
	}
	else
	{
		while (stack)
		{
			if (*(int *)stack->content < number)
				if ((closest == number && *(int *)stack->content < number)
					|| (closest != number && *(int *)stack->content > closest))
					closest = *(int *)stack->content;
			stack = stack->next;
		}
	}
	return (closest);
}

void	find_closest(t_closest *closest, t_list *stack, int number)
{
	closest->c_inferior = number;
	closest->c_superior = number;
	if (is_the_biggest(stack, number))
		closest->c_superior = number;
	else
		closest->c_superior = get_closest(stack, number, 1);
	if (is_the_smallest(stack, number))
		closest->c_inferior = number;
	else
		closest->c_inferior = get_closest(stack, number, 0);
}
