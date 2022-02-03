/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gucamuze <gucamuze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 04:53:13 by gucamuze          #+#    #+#             */
/*   Updated: 2022/02/03 04:55:20 by gucamuze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_data	*setup_data(t_list *stack_a, t_list **results, int chnk_nb, int size)
{
	t_data			*data;

	data = malloc(sizeof(t_data));
	if (!data)
		return (0);
	data->chunks = create_chunks(chnk_nb, size);
	populate_chunks(data->chunks, stack_a);
	data->s_a = stack_a;
	data->s_b = NULL;
	data->results = results;
	data->lst_arr = NULL;
	return (data);
}

void	send_to_b(t_data *data, int c, int ret)
{
	if (data->c_info.first_top != 0)
	{
		data->c_info.first_bot = get_first_bot_index(data->lst_arr, ft_lstsize(data->s_a), data->chunks[c], 20);
		data->c_info.bot_moves = get_nb_of_moves(ft_lstsize(data->s_a), data->c_info.first_bot, 0);
		if (data->c_info.top_moves < data->c_info.bot_moves)
			put_on_top(&data->s_a, data->results, 1, data->c_info.top_moves);
		else
			put_on_top(&data->s_a, data->results, 0, data->c_info.bot_moves);
	}
	gtfo_my_chunk(data->chunks[c], *(int *)(data->s_a)->content, 20);
	ret = prepare_stack(&data->s_b, data->results, *(int *)(data->s_a)->content);
	push(&data->s_a, &data->s_b);
	ft_lstadd_back(data->results, ft_lstnew(ft_strdup("pb")));
	if (data->s_a && !ret)
	{
		rotate(&data->s_b);
		ft_lstadd_back(data->results, ft_lstnew(ft_strdup("rb")));
	}
}

void	sort_and_push(t_data *data)
{
	int	c;

	c = 0;
	while (data->s_a)
	{
		data->lst_arr = lst_to_array(data->s_a);
		if (chunk_is_empty(data->chunks[c], 20))
			c++;
		data->c_info.first_top = get_first_top_index(data->lst_arr, ft_lstsize(data->s_a), data->chunks[c], 20);
		data->c_info.top_moves = get_nb_of_moves(ft_lstsize(data->s_a), data->c_info.first_top, 1);
		if (data->c_info.first_top != -1)
			send_to_b(data, c, 0);
		free(data->lst_arr);
	}
}

void sort_upto_hundred(t_list **stack_a, t_list **results)
{
	t_data			*data;

	if (is_sorted(*stack_a, 1))
		return;
	data = setup_data(*stack_a, results, 5, 20);
	sort_and_push(data);
	pull_b(&data->s_a, &data->s_b, data->results);
	free_chunks(data->chunks, 5);
}
