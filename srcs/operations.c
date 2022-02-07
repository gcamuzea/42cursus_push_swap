/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gucamuze <gucamuze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 15:45:52 by gucamuze          #+#    #+#             */
/*   Updated: 2022/02/07 15:54:37 by gucamuze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate(t_list **stack, t_list **results, const char *operation)
{
	if (!ft_strncmp(operation, "ra", 2) || !ft_strncmp(operation, "rb", 2))
	{
		rotate(stack);
		ft_lstadd_back(results, ft_lstnew(ft_strdup(operation)));
	}
	else if (!ft_strncmp(operation, "rra", 3)
		|| !ft_strncmp(operation, "rrb", 3))
	{
		reverse_rotate(stack);
		ft_lstadd_back(results, ft_lstnew(ft_strdup(operation)));
	}
}

void	ft_push(t_list **s_1, t_list **s_2, t_list **results,
			const char *operation)
{
	push(s_1, s_2);
	ft_lstadd_back(results, ft_lstnew(ft_strdup(operation)));
}
