/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gucamuze <gucamuze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 15:55:23 by gucamuze          #+#    #+#             */
/*   Updated: 2022/02/01 00:23:18 by gucamuze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# define PRINT_ERR printf("Error\n")

typedef struct s_list_info
{
    int smallest;
    int smallest_pos;
}   t_list_info;

typedef struct s_closest
{
    int c_superior;
    int c_inferior;
}   t_closest;

typedef struct s_streak
{
    int starting_index;
    int starting_number;
    int streak_len;
}   t_streak;


void	print_test(void);
// checks
int		check_doubles(long long number, int stack_index, t_list *stack);
int		is_sorted(t_list *stack, int mode);
void	push_swap(t_list **stack_a, int size);
// stack_operations
void	swap(t_list **stack);
void	push(t_list **stack_1, t_list **stack_2);
void	rotate(t_list **stack);
void	reverse_rotate(t_list **stack);
// sort_operations
void	sort_two(t_list *stack_a, t_list **results);
void    sort_three(t_list **stack_a, t_list **results);
void	sort_upto_five(t_list **stack_a, t_list **results, int size);
void	sort_upto_hundred(t_list **stack_a, t_list **results, int size);
// sort_state_operations
void	sort_state_0(t_list **stack_a,t_list **results);
void	sort_state_1(t_list **stack_a,t_list **results);
void	sort_state_2(t_list **stack_a,t_list **results);
void	sort_state_3(t_list **stack_a,t_list **results);
void	sort_state_4(t_list **stack_a,t_list **results);

//sort_utils
int 	get_sort_state(t_list *stack);
// utils
void	DEBUG__print_lst(t_list *list, char mode);
void	print_results(t_list *results);
void	pretty_print(t_list *stack_a, t_list *stack_b);
int	    get_list_biggest(t_list *stack);
int	    get_list_smallest(t_list *stack);

#endif