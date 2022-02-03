/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MISC.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gucamuze <gucamuze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 06:43:30 by gucamuze          #+#    #+#             */
/*   Updated: 2022/02/03 02:52:25 by gucamuze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	prepare_closest_sup(t_list **stack, t_list **results, int c_sup)
{
	int	c_sup_pos;

	c_sup_pos = get_position(*stack, c_sup);
	if (c_sup_pos > ft_lstsize(*stack) / 2)
		while (*(int *)ft_lstlast(*stack)->content != c_sup)
		{
			reverse_rotate(stack);
			ft_lstadd_back(results, ft_lstnew(ft_strdup("rrb")));
		}
	else
		while (*(int *)ft_lstlast(*stack)->content != c_sup)
		{
			rotate(stack);
			ft_lstadd_back(results, ft_lstnew(ft_strdup("rb")));
		}
	return (0);
}

int	prepare_closest_inf(t_list **stack, t_list **results, int c_inf)
{
	int c_inf_pos;

	c_inf_pos = get_position(*stack, c_inf);
	if (c_inf_pos > ft_lstsize(*stack) / 2)
		while (*(int *)(*stack)->content != c_inf)
		{
			reverse_rotate(stack);
			ft_lstadd_back(results, ft_lstnew(ft_strdup("rrb")));
		}
	else
		while (*(int *)(*stack)->content != c_inf)
		{
			rotate(stack);
			ft_lstadd_back(results, ft_lstnew(ft_strdup("rb")));
		}
	return (1);
}

int	prepare_stack(t_list **stack_b, t_list **results, int number)
{
	t_closest	closest;

	if (!*stack_b)
		return (1);
	find_closest(&closest, *stack_b, number);
	if (closest.c_inferior == number)
		return (prepare_closest_sup(stack_b, results, closest.c_superior));
	else
		return (prepare_closest_inf(stack_b, results, closest.c_inferior));
}

void	pull_b(t_list **stack_a, t_list **stack_b, t_list **results)
{
	int	biggest;
	int	big_pos;

	biggest = get_list_biggest(*stack_b);
	big_pos = get_position(*stack_b, biggest);
	if (big_pos > ft_lstsize(*stack_b) / 2)
		while (*(int *)(*stack_b)->content != biggest)
		{
			reverse_rotate(stack_b);
			ft_lstadd_back(results, ft_lstnew(ft_strdup("rrb")));
		}
	else
		while (*(int *)(*stack_b)->content != biggest)
		{
			rotate(stack_b);
			ft_lstadd_back(results, ft_lstnew(ft_strdup("rb")));
		}
	while (*stack_b)
	{
		push(stack_b, stack_a);
		ft_lstadd_back(results, ft_lstnew(ft_strdup("pa")));
	}
}
