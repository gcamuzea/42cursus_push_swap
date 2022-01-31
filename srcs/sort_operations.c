/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gucamuze <gucamuze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 19:59:28 by gucamuze          #+#    #+#             */
/*   Updated: 2022/02/01 00:52:42 by gucamuze         ###   ########.fr       */
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

// 1 for rotate, 0 for reverse
void	put_on_top(int biggest, t_list **stack, t_list **results, int mode)
{
	while (*(int *)(*stack)->content != biggest) 
	{
		if (mode == 1)
		{
			rotate(stack);
			ft_lstadd_back(results, ft_lstnew(ft_strdup("ra")));
		}
		else
		{
			reverse_rotate(stack);
			ft_lstadd_back(results, ft_lstnew(ft_strdup("rra")));
		}
	}
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

void	sort_upto_hundred(t_list **stack_a, t_list **results, int size)
{
	(void)size;
	t_closest	closest;
	t_list		*iterator;
	t_streak	streak;
	t_list		*stack_b;

	iterator = *stack_a;
	stack_b = NULL;
	while (iterator)
	{
		if (is_sorted(*stack_a, 1))
		{
			if (ft_lstsize(*stack_a) != size)
				pull_b(stack_a, &stack_b, results);	
			
			pretty_print(*stack_a, stack_b);
			return ;
		}
		// pretty_print(*stack_a, stack_b);
		if (ft_lstsize(*stack_a) > 3)
		{
			find_closest(&closest, *stack_a, *(int *)iterator->content);
			/**
			 * STREAKS
			 * FUCKING USELESS LMAO
			 */
			if (find_streaks(iterator, &streak))
			{
				// printf("\n------------\npushing streak\n");
				// pretty_print(*stack_a, stack_b);
				// printf("closest streak is %d long, starting on number %d\n", streak.streak_len, streak.starting_number);
				push_streak(&streak, stack_a, &stack_b, results);
				// printf("\n------------\ndone\n");
				// pretty_print(*stack_a, stack_b);
				iterator = *stack_a;
			}
			/**
			 * CHUNKS
			 * import logic from medium
			 * import no_honor from fuck_this_project
			 */
			else
			{
				t_list_info *bla = find_smallest(*stack_a);
				// printf("biggest is %d, on position %d\n", bla->smallest, bla->smallest_pos);
				put_on_top(bla->smallest, stack_a, results, get_rotate_mode(bla->smallest_pos, ft_lstsize(*stack_a)));
				push(stack_a, &stack_b);
				ft_lstadd_back(results, ft_lstnew(ft_strdup("pb")));
				// if (ft_lstsize(stack_b) > 1)
				// {
				// 	rotate(&stack_b);
				// 	ft_lstadd_back(results, ft_lstnew(ft_strdup("rb")));
				// }
				iterator = *stack_a;
			}
			iterator = iterator->next;
		}
		else if (ft_lstsize(*stack_a) == 3)
		{
			// printf("sorting 3\n");
			sort_three(stack_a, results);
			// pretty_print(*stack_a, stack_b);
			pull_b(stack_a, &stack_b, results);
			// pretty_print(*stack_a, stack_b);
		}
	}
}