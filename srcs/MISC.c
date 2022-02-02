/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MISC.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gucamuze <gucamuze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 06:43:30 by gucamuze          #+#    #+#             */
/*   Updated: 2022/02/02 07:25:57 by gucamuze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_closest(t_closest *closest)
{
	closest->c_inferior = 0;
	closest->c_superior = 0;
}

void	prepare_stack(t_list **stack_b, t_list **results, int number)
{
	t_closest	closest;
	int			pos;

	set_closest(&closest);
	if (!*stack_b)
		return ;
	find_closest(&closest, *stack_b, number);
	// printf("closest to %d in b is %d\n", number, closest.c_inferior);
	pos = get_position(*stack_b, closest.c_inferior);
	if (closest.c_inferior == number)
		return ;
	if (pos > ft_lstsize(*stack_b) / 2)
		while (*(int *)(*stack_b)->content != closest.c_inferior)
		{
			reverse_rotate(stack_b);
			ft_lstadd_back(results, ft_lstnew(ft_strdup("rrb")));
		}
	else
		while (*(int *)(*stack_b)->content != closest.c_inferior)
		{
			rotate(stack_b);
			ft_lstadd_back(results, ft_lstnew(ft_strdup("rb")));
		}
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
