/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gucamuze <gucamuze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 16:29:44 by gucamuze          #+#    #+#             */
/*   Updated: 2022/02/03 05:49:57 by gucamuze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_number(char *str)
{
	if (*str == '-' || *str == '+')
		str++;
	while (*str)
		if (!ft_isdigit(*str++))
			return (0);
	return (1);
}

int	check_args(int ac, char **av)
{
	int n;

	n = 1;
	while (n < ac)
	{
		if (!is_number(av[n]))
			return (0);
		n++;
	}
	return (1);
}

t_list *create_stack(int ac, char **av)
{
	t_list			*begin;
	t_list			*current;
	long long int	*content;
	int				n;

	begin = NULL;
	current = NULL;
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
		{
			printf("error: %lld not an int\n", number);
			return (0);
		}
		if (stack_index > 0)
			if (!check_doubles(number, stack_index, stack))
			{
				printf("Error: a number is doubled\n");
				return (0);
			}
		current = current->next;
		stack_index++;
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_list *stack_a;

	if (ac < 3)
		PRINT_ERR;
	else
	{
		if (!check_args(ac, av))
		{
			printf("args\n");
			PRINT_ERR;
			return (-1);
		}
		stack_a = create_stack(ac, av);
		if (!check_stack(stack_a))
		{
			printf("stack\n");
			PRINT_ERR;
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
}