/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gucamuze <gucamuze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 16:29:44 by gucamuze          #+#    #+#             */
/*   Updated: 2022/02/08 18:47:57 by gucamuze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_number(char *str)
{
	if (*str == '-' || *str == '+')
	{
		str++;
		if (*str == 0)
			return (0);
	}
	while (*str)
		if (!ft_isdigit(*str++))
			return (0);
	return (1);
}

int	check_args(int ac, char **av)
{
	int	n;

	n = 1;
	while (n < ac)
	{
		if (!is_number(av[n]))
			return (0);
		n++;
	}
	return (1);
}

t_list	*create_stack(int ac, char **av)
{
	t_list			*begin;
	t_list			*current;
	long long int	*content;
	int				n;

	begin = NULL;
	n = 1;
	while (n < ac)
	{
		content = malloc(sizeof(long long int));
		if (!content)
			return (NULL);
		*content = ft_atol(av[n++]);
		if (!begin)
		{
			begin = ft_lstnew((void *)content);
			current = begin;
		}
		else
		{
			current->next = ft_lstnew((void *)content);
			current = current->next;
		}
	}
	return (begin);
}

int	check_stack(t_list *stack)
{
	t_list		*current;
	long long	number;
	int			stack_index;

	current = stack;
	stack_index = 0;
	while (current)
	{
		number = *(long long *)current->content;
		if (number > INT_MAX || number < INT_MIN)
			return (0);
		if (stack_index > 0)
			if (!check_doubles(number, stack_index, stack))
				return (0);
		current = current->next;
		stack_index++;
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_list	*stack_a;

	if (!check_args(ac, av))
	{
		ft_putstr_fd("Error\n", STDERR_FILENO);
		return (-1);
	}
	stack_a = create_stack(ac, av);
	if (!check_stack(stack_a))
	{
		ft_putstr_fd("Error\n", STDERR_FILENO);
		ft_lstclear(&stack_a, free);
	}
	else
	{
		if (is_sorted(stack_a, 1))
			ft_lstclear(&stack_a, free);
		else
			push_swap(&stack_a, ac - 1);
	}
}
