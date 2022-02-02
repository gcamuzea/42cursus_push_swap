
// void	push_streak(t_streak *streak, t_list **stack_a, t_list **stack_b, t_list **results)
// {
// 	// need to prepare stack_b to receive the streak
// 	printf("STARTING PUSH STREAK ON %d\n", streak->starting_number);
// 	t_closest	closest;
// 	find_closest(&closest, *stack_b, streak->starting_number);
// 	// printf("%d:\tclosest in stack b is %d\n", streak->starting_number, closest.c_inferior);
// 	while (*(int *)(*stack_a)->content != streak->starting_number)
// 	{
// 		rotate(stack_a);
// 		ft_lstadd_back(results, ft_lstnew(ft_strdup("ra")));
// 	}
// 	while (streak->streak_len--)
// 	{
// 		find_closest(&closest, *stack_b, *(int *)(*stack_a)->content);
// 		// printf("%d:\tclosest in stack b is %d\n", *(int *)(*stack_a)->content, closest.c_inferior);
// 		if (!stack_ready(*stack_b, &closest))
// 			prepare_stack(stack_b, results, closest.c_inferior);
// 		push(stack_a, stack_b);
// 		ft_lstadd_back(results, ft_lstnew(ft_strdup("pb")));
// 	}
// 	// pretty_print(*stack_a, *stack_b);
// 	streak->streak_len = 0;
// 	streak->starting_number = 0;
// }

// int	get_streak_len(t_list *stack)
// {
// 	t_closest	closest;
// 	int			streak_len;

// 	streak_len = 1;
// 	find_closest(&closest, stack, *(int *)stack->content);
// 	// printf("gsl %d closest %d\n", *(int *)stack->content, closest.c_superior);
// 	while (stack->next && *(int *)stack->next->content == closest.c_superior)
// 	{
// 		streak_len++;
// 		// printf("gsl %d closest %d is here, len++ -> %d\n", *(int *)stack->content, closest.c_superior, streak_len);
// 		stack = stack->next;
// 		find_closest(&closest, stack, *(int *)stack->content);
// 	}
// 	return (streak_len);
// }

// int	find_streaks(t_list *stack, t_streak *streak_s)
// {
// 	int			streak_len;
// 	t_closest	closest;
// 	int			next_n;
// 	t_list		*iterator;
// 	int			streak_index;

// 	streak_len = 0;
// 	streak_index = 0;
// 	iterator = stack;
// 	// printf("called\n");
// 	while (iterator->next)
// 	{
// 		next_n = *(int *)iterator->next->content;
// 		find_closest(&closest, stack, *(int *)iterator->content);
// 		// printf("%d closest next is %d\n", *(int *)iterator->content, closest.c_superior);
// 		if (next_n == closest.c_superior)
// 		{
// 			streak_len = get_streak_len(iterator);
// 			// printf("match, len is %d\n", streak_len);
// 			if (streak_len > 2)
// 			{
// 				streak_s->starting_number = *(int *)iterator->content;
// 				streak_s->streak_len = streak_len;
// 				streak_s->starting_index = streak_index;
// 				// printf("found a > 2 streak, starting on index %d\n", streak_s->starting_index);
// 				return (1);
// 			}
// 		}
// 		iterator = iterator->next;
// 		streak_index++;
// 	}
// 	return (0);
// }

// int		stack_ready(t_list *stack, t_closest *closest)
// {
// 	if (!stack)
// 		return (1);
// 	if (*(int *)stack->content == closest->c_inferior)
// 		return (1);
// 	return (0);
// }