/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gucamuze <gucamuze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 19:59:28 by gucamuze          #+#    #+#             */
/*   Updated: 2022/02/07 11:12:02 by gucamuze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_smallest(t_list *stack)
{
	t_list	*iterator;
	int		smallest;

	smallest = *(int *)stack->content;
	iterator = stack;
	while (iterator)
	{
		if (*(int *)iterator->content < smallest)
			smallest = *(int *)iterator->content;
		iterator = iterator->next;
	}
	return (smallest);
}

int	*lst_to_array(t_list *lst)
{
	int	*array;
	int	c;
	int	lstsize;

	lstsize = ft_lstsize(lst);
	array = malloc(lstsize * sizeof(int));
	if (!array)
		return (0);
	c = -1;
	while (++c < lstsize)
	{
		array[c] = *(int *)lst->content;
		lst = lst->next;
	}
	return (array);
}

/**
 * mode 1 to use ra, mode 0 to use rra
 */
void	put_on_top(t_list **stack_a, t_list **results, int mode,
			int nb_of_moves)
{
	if (mode)
	{
		while (nb_of_moves--)
		{
			rotate(stack_a);
			ft_lstadd_back(results, ft_lstnew(ft_strdup("ra")));
		}
	}
	else
	{
		while (nb_of_moves--)
		{
			reverse_rotate(stack_a);
			ft_lstadd_back(results, ft_lstnew(ft_strdup("rra")));
		}
	}
}
