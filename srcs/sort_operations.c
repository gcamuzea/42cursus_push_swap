/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gucamuze <gucamuze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 19:59:28 by gucamuze          #+#    #+#             */
/*   Updated: 2022/02/01 06:01:14 by gucamuze         ###   ########.fr       */
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

// NEED -> free stack b, info
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

int		is_the_biggest(t_list *stack, int number)
{
	while (stack)
	{
		if (*(int *)stack->content > number)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int		is_the_smallest(t_list *stack, int number)
{
	while (stack)
	{
		if (*(int *)stack->content < number)
			return (0);
		stack = stack->next;
	}
	return (1);
}

/**
 *	MODE 1 for closest superior, mode 0 for closest inferior
**/
int		get_closest(t_list *stack, int number, int mode)
{
	int	closest;

	closest = number;
	if (mode)
	{
		while (stack)
		{
			if (*(int *)stack->content > number)
				if ((closest == number && *(int *)stack->content > number)
					|| (closest != number && *(int *)stack->content < closest))
					closest = *(int *)stack->content;
			stack = stack->next;
		}
	}
	else
	{
		while (stack)
		{
			if (*(int *)stack->content < number)
				if ((closest == number && *(int *)stack->content < number)
					|| (closest != number && *(int *)stack->content > closest))
					closest = *(int *)stack->content;
			stack = stack->next;
		}
	}
	return (closest);
}

void	find_closest(t_closest *closest, t_list *stack, int number)
{
	closest->c_inferior = number;
	closest->c_superior = number;
	if (is_the_biggest(stack, number))
		closest->c_superior = number;
	else
		closest->c_superior = get_closest(stack, number, 1);
	if (is_the_smallest(stack, number))
		closest->c_inferior = number;
	else
		closest->c_inferior = get_closest(stack, number, 0);
}

int	get_streak_len(t_list *stack)
{
	t_closest	closest;
	int			streak_len;

	streak_len = 1;
	find_closest(&closest, stack, *(int *)stack->content);
	// printf("gsl %d closest %d\n", *(int *)stack->content, closest.c_superior);
	while (stack->next && *(int *)stack->next->content == closest.c_superior)
	{
		streak_len++;
		// printf("gsl %d closest %d is here, len++ -> %d\n", *(int *)stack->content, closest.c_superior, streak_len);
		stack = stack->next;
		find_closest(&closest, stack, *(int *)stack->content);
	}
	return (streak_len);
}

int	find_streaks(t_list *stack, t_streak *streak_s)
{
	int			streak_len;
	t_closest	closest;
	int			next_n;
	t_list		*iterator;
	int			streak_index;

	streak_len = 0;
	streak_index = 0;
	iterator = stack;
	// printf("called\n");
	while (iterator->next)
	{
		next_n = *(int *)iterator->next->content;
		find_closest(&closest, stack, *(int *)iterator->content);
		// printf("%d closest next is %d\n", *(int *)iterator->content, closest.c_superior);
		if (next_n == closest.c_superior)
		{
			streak_len = get_streak_len(iterator);
			// printf("match, len is %d\n", streak_len);
			if (streak_len > 2)
			{
				streak_s->starting_number = *(int *)iterator->content;
				streak_s->streak_len = streak_len;
				streak_s->starting_index = streak_index;
				// printf("found a > 2 streak, starting on index %d\n", streak_s->starting_index);
				return (1);
			}
		}
		iterator = iterator->next;
		streak_index++;
	}
	return (0);
}

int		stack_ready(t_list *stack, t_closest *closest)
{
	if (!stack)
		return (1);
	if (*(int *)stack->content == closest->c_inferior)
		return (1);
	return (0);
}

void	prepare_stack(t_list **stack_b, t_list **results, int number)
{
	int	n_index;

	if (!*stack_b)
		return ;
	n_index = get_position(*stack_b, number);
	if (n_index > ft_lstsize(*stack_b) / 2)
	{
		while (*(int *)(*stack_b)->content != number)
		{
			reverse_rotate(stack_b);
			ft_lstadd_back(results, ft_lstnew(ft_strdup("rrb")));
		}
	}
	else
	{
		while (*(int *)(*stack_b)->content != number)
		{
			rotate(stack_b);
			ft_lstadd_back(results, ft_lstnew(ft_strdup("rrb")));
		}
	}
}

void	push_streak(t_streak *streak, t_list **stack_a, t_list **stack_b, t_list **results)
{
	// need to prepare stack_b to receive the streak
	printf("STARTING PUSH STREAK ON %d\n", streak->starting_number);
	t_closest	closest;
	find_closest(&closest, *stack_b, streak->starting_number);
	// printf("%d:\tclosest in stack b is %d\n", streak->starting_number, closest.c_inferior);
	while (*(int *)(*stack_a)->content != streak->starting_number)
	{
		rotate(stack_a);
		ft_lstadd_back(results, ft_lstnew(ft_strdup("ra")));
	}
	while (streak->streak_len--)
	{
		find_closest(&closest, *stack_b, *(int *)(*stack_a)->content);
		// printf("%d:\tclosest in stack b is %d\n", *(int *)(*stack_a)->content, closest.c_inferior);
		if (!stack_ready(*stack_b, &closest))
			prepare_stack(stack_b, results, closest.c_inferior);
		push(stack_a, stack_b);
		ft_lstadd_back(results, ft_lstnew(ft_strdup("pb")));
	}
	// pretty_print(*stack_a, *stack_b);
	streak->streak_len = 0;
	streak->starting_number = 0;
}

void	pull_b(t_list **stack_a, t_list **stack_b, t_list **results)
{
	// printf("pull b\n");
	while (*stack_b)
	{
		push(stack_b, stack_a);
		ft_lstadd_back(results, ft_lstnew(ft_strdup("pa")));
	}
}

long long int	**create_chunks(void)
{
	long long int	**chunks;
	int				c;
	int				i;

	chunks = malloc(5 * sizeof(long long int *));
	if (!chunks)
		return (0);
	c = -1;
	while (++c < 5)
	{
		chunks[c] = malloc(20 * sizeof(long long int));
		if (!chunks[c])
			return (0);
		i = -1;
		while (++i < 20)
			chunks[c][i] = LLONG_MAX;
	}
	return (chunks);
}

void	populate_chunks(long long int **chunks, t_list **stack)
{
	t_list		*iterator;
	t_closest	closest;
	int			c;
	int			i;

	iterator = *stack;
	c = -1;
	while (++c < 5)
	{
		i = -1;
		while (++i < 20)
		{
			if (c == 0 && i == 0)
				chunks[c][i] = find_smallest(*stack)->smallest;
			else if (i == 0)
			{
				find_closest(&closest, *stack, chunks[c - 1][19]);
				if (closest.c_superior == chunks[c - 1][19])
					return ;
				else
					chunks[c][i] = closest.c_superior;
			}
			else
			{
				find_closest(&closest, *stack, chunks[c][i -1]);
				if (closest.c_superior == chunks[c][i - 1])
					return ;
				else
					chunks[c][i] = closest.c_superior;
			}
		}
	}
}

int	chunk_is_empty(long long int *chunk, int chunk_size)
{
	int	c;

	c = -1;
	while (++c < chunk_size)
		if (chunk[c] != LLONG_MAX)
			return (0);
	return (1);
}

int	is_in_chunk(long long int *chunk, int number, int chunk_size)
{
	int c;

	c = -1;
	while (++c < chunk_size)
	{
		if (chunk[c] != LLONG_MAX)
			if (chunk[c] == (long long int)number)
				return (1);
	}
	return (0);
}

int	get_first_top_index(int *stack, int stack_size, long long int *chunk, int chunk_size)
{
	int c;

	c = -1;
	while (++c < stack_size)
	{
		if (is_in_chunk(chunk, stack[c], chunk_size))
			return (c);
	}
	return (-1);
}

int	get_first_bot_index(int *stack, int stack_size, long long int *chunk, int chunk_size)
{
	while (--stack_size > -1)
	{
		if (is_in_chunk(chunk, stack[stack_size], chunk_size))
			return (stack_size);
	}
	return (-1);
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
	printf("%d is now on top !\n", *(int *)(*stack_a)->content);
}

void	gtfo_my_chunk(long long int *chunk, long long int number, int chunk_size)
{
	int	c;

	c = -1;
	while (++c < chunk_size)
	{
		if (chunk[c] == number)
			chunk[c] = LLONG_MAX;
	}
}

void	new_sort_hundred(t_list **stack_a, t_list **results, int size)
{
	(void)results;(void)size;
	t_list			*iterator;
	long long int	**chunks;
	int				c;
	int				*list_array;
	t_list			*stack_b;
	t_chunks_info	infos;

	chunks = create_chunks();
	populate_chunks(chunks, stack_a);
	memset(&infos, 0, sizeof(t_chunks_info));
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
	iterator = *stack_a;
	c = 0;
	int count = 0;
	while (iterator)
	{
		if (count++ > 4)
			return ;
		if (is_sorted(*stack_a, 1))
		{
			if (ft_lstsize(*stack_a) == size)
			{
				printf("done\n");
				return ;
			}
			// printf("need pull b, breaking..\n");
			return ;
			// pull b
		}
		else
		{
			list_array = lst_to_array(*stack_a);
			if (chunk_is_empty(chunks[c], 20))
				c++;
			infos.first_top = get_first_top_index(list_array, ft_lstsize(*stack_a), chunks[c], 20);
			pretty_print(*stack_a, stack_b);
			if (infos.first_top != -1)
			{
				if (infos.first_top != 0)
				{
					infos.first_bot = get_first_bot_index(list_array, ft_lstsize(*stack_a), chunks[c], 20);
					infos.bot_moves = get_required_nb_of_moves(ft_lstsize(*stack_a), infos.first_bot);
					infos.top_moves = get_required_nb_of_moves(ft_lstsize(*stack_a), infos.first_top);
					printf("stack[%d] %d\tand\tstack[%d] %d\n", infos.first_top, list_array[infos.first_top], infos.first_bot, list_array[infos.first_bot]);
					printf("%d needs %d moves vs %d needing %d moves\n", infos.first_top, infos.top_moves, infos.first_bot, infos.bot_moves);
					if (infos.top_moves < infos.bot_moves)
						put_on_top(stack_a, results, 1, get_required_nb_of_moves(ft_lstsize(*stack_a), infos.first_top));
					else
						put_on_top(stack_a, results, 0, get_required_nb_of_moves(ft_lstsize(*stack_a), infos.first_top));
					// return ;
					// pretty_print(*stack_a, stack_b);
				}
				push(stack_a, &stack_b);
				ft_lstadd_back(results, ft_lstnew(ft_strdup("pb")));
			}
			free(list_array);
		}
	}
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