/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gucamuze <gucamuze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 20:17:18 by gucamuze          #+#    #+#             */
/*   Updated: 2022/02/07 11:13:24 by gucamuze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_sort_state(t_list *stack)
{
	int	first;
	int	second;
	int	third;

	first = *(int *)stack->content;
	second = *(int *)stack->next->content;
	third = *(int *)stack->next->next->content;
	if (first > second)
	{
		if (second < third && first < third)
			return (0);
		else if (second > third && first > third)
			return (1);
		else
			return (2);
	}
	else
	{
		if (first < third)
			return (3);
		else
			return (4);
	}
}
