/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_upto_five.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gucamuze <gucamuze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 02:31:05 by gucamuze          #+#    #+#             */
/*   Updated: 2022/02/07 15:44:59 by gucamuze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_list *stack_a, t_list **results)
{
	if (*(int *)stack_a->content > *(int *)stack_a->next->content)
		ft_lstadd_back(results, ft_lstnew(ft_strdup("ra")));
}

void	sort_three(t_list **stack_a, t_list **results)
{
	static void	(*state_function[5])(t_list **, t_list **);

	if (is_sorted(*stack_a, 1))
		return ;
	state_function[0] = sort_state_0;
	state_function[1] = sort_state_1;
	state_function[2] = sort_state_2;
	state_function[3] = sort_state_3;
	state_function[4] = sort_state_4;
	state_function[get_sort_state(*stack_a)](stack_a, results);
}

static void	send_smallest(t_list **stack_a, t_list **stack_b, t_list **results)
{
	int	smallest_pos;
	int	rotate_mode;
	int	moves;

	smallest_pos = get_position(*stack_a, get_list_smallest(*stack_a));
	rotate_mode = get_rotate_mode(smallest_pos, ft_lstsize(*stack_a));
	moves = get_nb_of_moves(ft_lstsize(*stack_a), smallest_pos, rotate_mode);
	while (moves--)
	{
		if (rotate_mode)
		{
			rotate(stack_a);
			ft_lstadd_back(results, ft_lstnew(ft_strdup("ra")));
		}
		else
		{
			reverse_rotate(stack_a);
			ft_lstadd_back(results, ft_lstnew(ft_strdup("rra")));
		}
	}
	push(stack_a, stack_b);
	ft_lstadd_back(results, ft_lstnew(ft_strdup("pb")));
}

void	sort_upto_five(t_list **stack_a, t_list **results)
{
	t_list	*stack_b;

	if (is_sorted(*stack_a, 1))
		return ;
	stack_b = NULL;
	while (ft_lstsize(*stack_a) > 3)
		send_smallest(stack_a, &stack_b, results);
	sort_three(stack_a, results);
	pull_b(stack_a, &stack_b, results);
}
