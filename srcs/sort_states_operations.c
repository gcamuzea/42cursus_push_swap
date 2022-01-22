/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_states_operations.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gucamuze <gucamuze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 20:57:04 by gucamuze          #+#    #+#             */
/*   Updated: 2022/01/07 11:59:48 by gucamuze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_state_0(t_list **stack_a, t_list **results)
{
	swap(stack_a);
	ft_lstadd_back(results, ft_lstnew(ft_strdup("sa")));
}

void	sort_state_1(t_list **stack_a, t_list **results)
{
	swap(stack_a);
	ft_lstadd_back(results, ft_lstnew(ft_strdup("sa")));
	reverse_rotate(stack_a);
	ft_lstadd_back(results, ft_lstnew(ft_strdup("rra")));
}

void	sort_state_2(t_list **stack_a, t_list **results)
{
	rotate(stack_a);
	ft_lstadd_back(results, ft_lstnew(ft_strdup("ra")));
}

void	sort_state_3(t_list **stack_a, t_list **results)
{
	swap(stack_a);
	ft_lstadd_back(results, ft_lstnew(ft_strdup("sa")));
	rotate(stack_a);
	ft_lstadd_back(results, ft_lstnew(ft_strdup("ra")));
}

void	sort_state_4(t_list **stack_a, t_list **results)
{
	reverse_rotate(stack_a);
	ft_lstadd_back(results, ft_lstnew(ft_strdup("rra")));
}
