/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gucamuze <gucamuze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 12:05:07 by gucamuze          #+#    #+#             */
/*   Updated: 2022/02/03 05:44:56 by gucamuze         ###   ########.fr       */
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

t_data	*setup_data(t_list *stack_a, t_list **results, int chnk_nb, int size)
{
	t_data			*data;

	data = malloc(sizeof(t_data));
	if (!data)
		return (0);
	data->chunks = create_chunks(chnk_nb, size);
	populate_chunks(data->chunks, stack_a, chnk_nb, size);
	data->s_a = stack_a;
	data->s_b = NULL;
	data->results = results;
	data->lst_arr = NULL;
	return (data);
}
