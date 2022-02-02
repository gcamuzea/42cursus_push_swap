/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks_parsing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gucamuze <gucamuze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 02:12:49 by gucamuze          #+#    #+#             */
/*   Updated: 2022/02/02 02:30:45 by gucamuze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_first_top_index(int *stack, int stack_size, long long int *chunk, int chunk_size)
{
	int c;

	c = -1;
	while (++c < stack_size)
	{
		if (is_in_chunk(chunk, stack[c], chunk_size))
			return (c);
	}
	return (-1);
}

int	get_first_bot_index(int *stack, int stack_size, long long int *chunk, int chunk_size)
{
	while (--stack_size > -1)
	{
		if (is_in_chunk(chunk, stack[stack_size], chunk_size))
			return (stack_size);
	}
	return (-1);
}
