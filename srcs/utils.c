/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gucamuze <gucamuze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 12:05:07 by gucamuze          #+#    #+#             */
/*   Updated: 2022/01/31 04:38:41 by gucamuze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	DEBUG__print_lst(t_list *list, char mode)
{
	int list_index;

	list_index = 0;
	if (list)
	{
		while (list)
		{
			if (mode == 'd')
				printf("list index %d => %d\n", list_index, *(int *)list->content);
			else if (mode == 'l')
				printf("list index %d => %lld\n", list_index, *(long long *)list->content);
			list = list->next;
		}
	}
	else
		printf("LIST IS EMPTY\n");
}

void	print_results(t_list *results)
{
	while (results)
	{
		printf("%s\n", (char *)results->content);
		results = results->next;
	}
}

void	pretty_print(t_list *stack_a, t_list *stack_b)
{
	printf("________________________\n");
	printf("|\t\t\t|\n| A\t\tB\t|\n");
	printf("|_______________________|\n");
	printf("|_______________________|\n");
	while (stack_a || stack_b)
	{
		// DEBUG__print_lst(stack_a, 'd');
		// printf("coucou ?\n");
		printf("| ");
		if (stack_a)
		{
			printf("%d", *(int *)stack_a->content);
			stack_a = stack_a->next;
		}
		printf("\t\t");
		if (stack_b)
		{
			printf("%d", *(int *)stack_b->content);
			stack_b = stack_b->next;
		}
		printf("\t|\n");
	}
	printf("|_______________________|\n");
}

int	get_list_biggest(t_list *stack)
{
	int max;
	
	max = INT_MIN;
	while (stack)
	{
		if (*(int *)stack->content > max)
			max = *(int *)stack->content;
		stack = stack->next;
	}
	return (max);
}

int	get_list_smallest(t_list *stack)
{
	int min;
	
	min = INT_MAX;
	while (stack)
	{
		if (*(int *)stack->content < min)
			min = *(int *)stack->content;
		stack = stack->next;
	}
	return (min);
}

