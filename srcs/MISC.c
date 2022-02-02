
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

void	pull_b(t_list **stack_a, t_list **stack_b, t_list **results)
{
	// printf("pull b\n");
	while (*stack_b)
	{
		push(stack_b, stack_a);
		ft_lstadd_back(results, ft_lstnew(ft_strdup("pa")));
	}
}

