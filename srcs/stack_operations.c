/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gucamuze <gucamuze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 19:10:38 by gucamuze          #+#    #+#             */
/*   Updated: 2022/01/06 18:57:43 by gucamuze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list **stack)
{
	t_list *swap;
	
	swap = (*stack)->next;
	(*stack)->next = swap->next;
	swap->next = (*stack);
	(*stack) = swap;
}

//pa : push a - take the first element at the top of b and put it at the top of a. Do nothing if b is empty.
void	push(t_list **stack_1, t_list **stack_2)
{
	t_list	*swap;
	
	swap = NULL;
	if (*stack_1)
	{
		swap = (*stack_1)->next;
		(*stack_1)->next = *stack_2;
		*stack_2 = *stack_1;
		*stack_1 = swap;
	}
}

//ra, rb, rr : rotate a - shift up all elements of stack a by 1. The first element becomes the last one
void	rotate(t_list **stack)
{
	t_list *swap;
	t_list *list_start;

	swap = NULL;
	list_start = NULL;
	if (*stack)
	{
		swap = *stack;
		list_start = (*stack)->next;
		while ((*stack)->next)
			*stack = (*stack)->next;
		swap->next = NULL;
		(*stack)->next = swap;
	}
	*stack = list_start;
}

//rra : reverse rotate a - shift down all elements of stack a by 1. The last element becomes the first one.
void	reverse_rotate(t_list **stack)
{
	t_list *swap;
	t_list *list_start;

	swap = NULL;	
	list_start = *stack;
	if (*stack)
	{
		swap = (*stack)->next;
		while (swap->next)
		{
			swap = (*stack)->next;
			if (swap->next)
				*stack = (*stack)->next;
			else
				break;
		}
		swap->next = list_start;
		(*stack)->next = NULL;
		*stack = swap;
	}
}
