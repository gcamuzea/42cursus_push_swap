/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gucamuze <gucamuze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 04:58:06 by gucamuze          #+#    #+#             */
/*   Updated: 2022/02/03 04:58:31 by gucamuze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int get_position(t_list *stack, int number)
{
	int position;

	position = 0;
	while (stack && *(int *)stack->content != number)
	{
		position++;
		stack = stack->next;
	}
	return (position);
}

int get_rotate_mode(int position, int stack_size)
{
	if (stack_size % 2)
	{
		if (position <= (stack_size + 1) / 2)
			return (1);
	}
	else if (position <= stack_size / 2)
		return (1);
	return (0);
}

/** 
 * mode 1 to start from top, 0 to start from bottom
 */
int get_nb_of_moves(int list_size, int index, int mode)
{
	// if (index + 1 < list_size / 2)
	if (mode)
		return (index);
	else
		return (list_size - index);
}
