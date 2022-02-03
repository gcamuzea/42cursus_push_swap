/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gucamuze <gucamuze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 02:07:47 by gucamuze          #+#    #+#             */
/*   Updated: 2022/02/03 04:38:29 by gucamuze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long long int **create_chunks(int nb_of_chunks, int sizeof_chunk)
{
	long long int **chunks;
	int c;
	int i;

	chunks = malloc(nb_of_chunks * sizeof(long long int *));
	if (!chunks)
		return (0);
	c = -1;
	while (++c < 5)
	{
		chunks[c] = malloc(sizeof_chunk * sizeof(long long int));
		if (!chunks[c])
			return (0);
		i = -1;
		while (++i < 20)
			chunks[c][i] = LLONG_MAX;
	}
	return (chunks);
}

void	populate_chunks(long long int **chunks, t_list *stack)
{
	t_closest closest;
	int c;
	int i;

	c = -1;
	while (++c < 5)
	{
		i = -1;
		while (++i < 20)
		{
			if (c == 0 && i == 0)
				chunks[c][i] = find_smallest(stack);
			else if (i == 0)
			{
				find_closest(&closest, stack, chunks[c - 1][19]);
				if (closest.c_superior == chunks[c - 1][19])
					return;
				else
					chunks[c][i] = closest.c_superior;
			}
			else
			{
				find_closest(&closest, stack, chunks[c][i - 1]);
				if (closest.c_superior == chunks[c][i - 1])
					return;
				else
					chunks[c][i] = closest.c_superior;
			}
		}
	}
}

void	gtfo_my_chunk(long long int *chunk, long long int number, int chunk_size)
{
	int	c;

	c = -1;
	while (++c < chunk_size)
	{
		if (chunk[c] == number)
			chunk[c] = LLONG_MAX;
	}
}

void	free_chunks(long long int **chunks, int nb_chunks)
{
	int	c;

	c = -1;
	if (chunks)
	{
		while (++c < nb_chunks)
		{
			if (chunks[c])
				free(chunks[c]);
		}
		free(chunks);
	}
}