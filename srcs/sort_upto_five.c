/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_upto_five.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gucamuze <gucamuze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 02:31:05 by gucamuze          #+#    #+#             */
/*   Updated: 2022/02/02 02:34:36 by gucamuze         ###   ########.fr       */
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

int	get_closest_pos(t_list **stack, int number, int stacksize)
{
	t_list	*ptr;
	int		lst_nbr;
	int		closest;
	int		closest_pos;

	closest = INT_MAX;
	closest_pos = 0;
	ptr = *stack;
	while (ptr)
	{
		lst_nbr = *(int *)ptr->content;
		if (lst_nbr - number > 0 && lst_nbr < closest)
			closest = lst_nbr;
		ptr = ptr->next;
	}
	ptr = *stack;
	if (closest != INT_MAX)
		while (*(int *)ptr->content != closest)
		{
			closest_pos++;
			ptr = ptr->next;
		}
	else
		closest_pos = -1;
	printf("closest = %d on pos %d, stacksize %d\n", closest, closest_pos,stacksize);
	return (closest_pos);
}

// NEED -> freeinfo
void	sort_upto_five(t_list **stack_a, t_list **results, int size)
{
	t_list *stack_b;

	if (is_sorted(*stack_a, 1))
		return ;
	stack_b = NULL;
	while (size-- > 3)
	{
		push(stack_a, &stack_b);
		ft_lstadd_back(results, ft_lstnew(ft_strdup("pb")));
	}
	sort_three(stack_a, results);
	pretty_print(*stack_a, stack_b);
	while (stack_b)
	{
		int ret = get_closest_pos(stack_a, *(int *)stack_b->content, ft_lstsize(*stack_a));
		if (ret == -1)
		{
			push(&stack_b, stack_a);
			ft_lstadd_back(results, ft_lstnew(ft_strdup("pa")));
			rotate(stack_a);
			ft_lstadd_back(results, ft_lstnew(ft_strdup("ra")));
		}
		else
		{
			push(&stack_b, stack_a);
			ft_lstadd_back(results, ft_lstnew(ft_strdup("pa")));
			if (ret == 1)
			{	
				swap(stack_a);
				ft_lstadd_back(results, ft_lstnew(ft_strdup("sa")));
			}
		}
		pretty_print(*stack_a, stack_b);
		printf("test lstcpy\n");
		pretty_print(ft_lstcpy(*stack_a), stack_b);
	}
}