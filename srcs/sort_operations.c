/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gucamuze <gucamuze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 19:59:28 by gucamuze          #+#    #+#             */
/*   Updated: 2022/02/02 07:28:08 by gucamuze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list_info	*find_smallest(t_list *stack)
{
	t_list_info	*info;
	t_list		*iterator;

	info = malloc(sizeof(t_list_info));
	if (!info)
		return (NULL);
	info->smallest = *(int *)stack->content;
	info->smallest_pos = 1;
	iterator = stack;
	while (iterator)
	{
		if (*(int *)iterator->content < info->smallest)
			info->smallest = *(int *)iterator->content;
		iterator = iterator->next;
	}
	while (*(int *)stack->content != info->smallest)
	{
		stack = stack->next;
		info->smallest_pos++;
	}
	return (info);
}

int		get_position(t_list *stack, int number)
{
	int	position;

	position = 0;
	while (stack && *(int *)stack->content != number)
	{
		position++;
		stack = stack->next;
	}
	return (position);
}

int		get_rotate_mode(int position, int stack_size)
{
	if (stack_size % 2)
	{
		if (position <= (stack_size + 1) / 2)
			return (1);
	}
	else
		if (position <= stack_size / 2)
			return (1);
	return (0);
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

int	get_required_nb_of_moves(int list_size, int index)
{
	if (index + 1 < list_size / 2)
		return (index);
	else
		return (list_size - index);
}

/**
 * mode 1 to use ra, mode 0 to use rra
 */
void	put_on_top(t_list **stack_a, t_list **results, int mode, int nb_of_moves)
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
	// printf("%d is now on top !\n", *(int *)(*stack_a)->content);
}

void	new_sort_hundred(t_list **stack_a, t_list **results, int size)
{
	(void)results;(void)size;
	long long int	**chunks;
	int				c;
	int				*list_array;
	t_list			*stack_b;
	t_chunks_info	infos;

	chunks = create_chunks();
	stack_b = NULL;
	populate_chunks(chunks, stack_a);
	memset(&infos, 0, sizeof(t_chunks_info));
	if (is_sorted(*stack_a, 1))
		return ;
	// for (size_t i = 0; i < 5; i++)
	// {
	// 	if (chunk_is_empty(chunks[i], 20))
	// 		printf("chunk %zu is empty !\n", i);
	// 	else
	// 	{
	// 		printf("chunk %zu is not empty !\n", i);
	// 		for (size_t c = 0; c < 20; c++)
	// 		{
	// 			printf("chunk[%zu][%zu] is %lld\n", i, c, chunks[i][c]);
	// 		}
			
	// 	}
	// }
	// return;
	c = 0;
	int count = 0;
	while ((*stack_a)) //stop at 1
	{
		count++;
		// if (count++ > 30)
		// 	return ;
			list_array = lst_to_array(*stack_a);
			if (chunk_is_empty(chunks[c], 20))
			{
				// printf("empty chunk %d, now +1\n", c);
				c++;
			}
			infos.first_top = get_first_top_index(list_array, ft_lstsize(*stack_a), chunks[c], 20);
			// printf("first top %d\n", infos.first_top);
			// pretty_print(*stack_a, stack_b);
			if (infos.first_top != -1)
			{
				if (infos.first_top != 0)
				{
					infos.first_bot = get_first_bot_index(list_array, ft_lstsize(*stack_a), chunks[c], 20);
					infos.bot_moves = get_required_nb_of_moves(ft_lstsize(*stack_a), infos.first_bot);
					infos.top_moves = get_required_nb_of_moves(ft_lstsize(*stack_a), infos.first_top);
					// printf("move %d, stack[%d] %d\tand\tstack[%d] %d\n", count, infos.first_top, list_array[infos.first_top], infos.first_bot, list_array[infos.first_bot]);
					// printf("%d needs %d moves vs %d needing %d moves\n", infos.first_top, infos.top_moves, infos.first_bot, infos.bot_moves);
					if (infos.top_moves < infos.bot_moves)
						put_on_top(stack_a, results, 1, get_required_nb_of_moves(ft_lstsize(*stack_a), infos.first_top));
					else
						put_on_top(stack_a, results, 0, get_required_nb_of_moves(ft_lstsize(*stack_a), infos.first_bot));
					// return ;
					// pretty_print(*stack_a, stack_b);
				}
				// printf("deleting %d in chunk %d\n", *(int *)(*stack_a)->content, c);
				gtfo_my_chunk(chunks[c], *(int *)(*stack_a)->content, 20);
				prepare_stack(&stack_b, results, *(int *)(*stack_a)->content);
				push(stack_a, &stack_b);
				ft_lstadd_back(results, ft_lstnew(ft_strdup("pb")));
			}
			else
				return ;
			free(list_array);
	}
	pull_b(stack_a, &stack_b, results);
	// pretty_print(*stack_a, stack_b);
}

// void	sort_upto_hundred(t_list **stack_a, t_list **results, int size)
// {
// 	(void)size;
// 	t_closest	closest;
// 	t_list		*iterator;
// 	t_streak	streak;
// 	t_list		*stack_b;
// 	t_chunks	*chunks;

// 	chunks = create_chunks(stack_a, size);
// 	iterator = *stack_a;
// 	stack_b = NULL;
// 	while (iterator)
// 	{
// 		if (is_sorted(*stack_a, 1))
// 		{
// 			if (ft_lstsize(*stack_a) != size)
// 				pull_b(stack_a, &stack_b, results);	
			
// 			pretty_print(*stack_a, stack_b);
// 			return ;
// 		}
// 		// pretty_print(*stack_a, stack_b);
// 		if (ft_lstsize(*stack_a) > 3)
// 		{
// 			find_closest(&closest, *stack_a, *(int *)iterator->content);
// 			/**
// 			 * STREAKS
// 			 * FUCKING USELESS LMAO
// 			 */
// 			if (find_streaks(iterator, &streak))
// 			{
// 				// printf("\n------------\npushing streak\n");
// 				// pretty_print(*stack_a, stack_b);
// 				// printf("closest streak is %d long, starting on number %d\n", streak.streak_len, streak.starting_number);
// 				push_streak(&streak, stack_a, &stack_b, results);
// 				// printf("\n------------\ndone\n");
// 				// pretty_print(*stack_a, stack_b);
// 				iterator = *stack_a;
// 			}
// 			/**
// 			 * CHUNKS
// 			 * import logic from medium
// 			 * import no_honor from fuck_this_project
// 			 */
// 			else
// 			{
// 				t_list_info *bla = find_smallest(*stack_a);
// 				// printf("biggest is %d, on position %d\n", bla->smallest, bla->smallest_pos);
// 				put_on_top(bla->smallest, stack_a, results, get_rotate_mode(bla->smallest_pos, ft_lstsize(*stack_a)));
// 				push(stack_a, &stack_b);
// 				ft_lstadd_back(results, ft_lstnew(ft_strdup("pb")));
// 				// if (ft_lstsize(stack_b) > 1)
// 				// {
// 				// 	rotate(&stack_b);
// 				// 	ft_lstadd_back(results, ft_lstnew(ft_strdup("rb")));
// 				// }
// 				iterator = *stack_a;
// 			}
// 			iterator = iterator->next;
// 		}
// 		else if (ft_lstsize(*stack_a) == 3)
// 		{
// 			// printf("sorting 3\n");
// 			sort_three(stack_a, results);
// 			// pretty_print(*stack_a, stack_b);
// 			pull_b(stack_a, &stack_b, results);
// 			// pretty_print(*stack_a, stack_b);
// 		}
// 	}
// }