/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gucamuze <gucamuze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 04:53:13 by gucamuze          #+#    #+#             */
/*   Updated: 2022/02/08 16:24:59 by gucamuze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	send_to_b(t_data *data, int c, int ret, int chunk_size)
{
	if (data->c_info.first_top != 0)
	{
		data->c_info.first_bot = get_first_bot_index(data->lst_arr,
				ft_lstsize(data->s_a), data->chunks[c], chunk_size);
		data->c_info.bot_moves = get_nb_of_moves(ft_lstsize(data->s_a),
				data->c_info.first_bot, 0);
		if (data->c_info.top_moves < data->c_info.bot_moves)
			put_on_top(&data->s_a, data->results, 1, data->c_info.top_moves);
		else
			put_on_top(&data->s_a, data->results, 0, data->c_info.bot_moves);
	}
	gtfo_my_chunk(data->chunks[c], *(int *)(data->s_a)->content, chunk_size);
	ret = prepare_stack(&data->s_b, data->results,
			*(int *)(data->s_a)->content);
	push(&data->s_a, &data->s_b);
	ft_lstadd_back(data->results, ft_lstnew(ft_strdup("pb")));
	if (data->s_a && !ret)
	{
		rotate(&data->s_b);
		ft_lstadd_back(data->results, ft_lstnew(ft_strdup("rb")));
	}
}

void	sort_and_push(t_data *data, int chunk_size)
{
	int	c;

	c = 0;
	while (data->s_a)
	{
		data->lst_arr = lst_to_array(data->s_a);
		if (chunk_is_empty(data->chunks[c], chunk_size))
			c++;
		data->c_info.first_top = get_first_top_index(data->lst_arr,
				ft_lstsize(data->s_a), data->chunks[c], chunk_size);
		data->c_info.top_moves = get_nb_of_moves(ft_lstsize(data->s_a),
				data->c_info.first_top, 1);
		if (data->c_info.first_top != -1)
			send_to_b(data, c, 0, chunk_size);
		free(data->lst_arr);
	}
}

void	sort_upto_hundred(t_list **stack_a, t_list **results)
{
	t_data			*data;

	if (is_sorted(*stack_a, 1))
		return ;
	data = setup_data(*stack_a, results, 5, 20);
	sort_and_push(data, 20);
	pull_b(&data->s_a, &data->s_b, data->results);
	*stack_a = data->s_a;
	free_chunks(data->chunks, 5);
	free(data);
}

void	sort_upto_five_hundred(t_list **stack_a, t_list **results)
{
	t_data			*data;

	if (is_sorted(*stack_a, 1))
		return ;
	data = setup_data(*stack_a, results, 11, 46);
	sort_and_push(data, 46);
	pull_b(&data->s_a, &data->s_b, data->results);
	*stack_a = data->s_a;
	free_chunks(data->chunks, 11);
	free(data);
}

void	sort_upto_whatever(t_list **stack_a, t_list **results)
{
	t_data			*data;
	int				stack_nb;

	if (is_sorted(*stack_a, 1))
		return ;
	stack_nb = ft_lstsize(*stack_a) / 100 + 1;
	data = setup_data(*stack_a, results, stack_nb, 100);
	sort_and_push(data, 46);
	pull_b(&data->s_a, &data->s_b, data->results);
	*stack_a = data->s_a;
	free_chunks(data->chunks, 11);
	free(data);
}
