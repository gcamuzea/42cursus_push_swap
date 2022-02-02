/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gucamuze <gucamuze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 15:55:23 by gucamuze          #+#    #+#             */
/*   Updated: 2022/02/02 02:40:43 by gucamuze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include "libft.h"
#define PRINT_ERR printf("Error\n")

typedef struct s_list_info
{
	int smallest;
	int smallest_pos;
} t_list_info;

typedef struct s_closest
{
	int c_superior;
	int c_inferior;
} t_closest;

typedef struct s_chunks_info
{
	int first_top;
	int top_moves;
	int first_bot;
	int bot_moves;
} t_chunks_info;

typedef struct s_streak
{
	int starting_index;
	int starting_number;
	int streak_len;
} t_streak;

void print_test(void);
// checks
int check_doubles(long long number, int stack_index, t_list *stack);
int is_sorted(t_list *stack, int mode);
void push_swap(t_list **stack_a, int size);
// stack_operations
void swap(t_list **stack);
void push(t_list **stack_1, t_list **stack_2);
void rotate(t_list **stack);
void reverse_rotate(t_list **stack);
// sort_operations
t_list_info	*find_smallest(t_list *stack);
void	find_closest(t_closest *closest, t_list *stack, int number);
void sort_upto_hundred(t_list **stack_a, t_list **results, int size);
void new_sort_hundred(t_list **stack_a, t_list **results, int size);
// sort_upto_five
void sort_two(t_list *stack_a, t_list **results);
void sort_three(t_list **stack_a, t_list **results);
void sort_upto_five(t_list **stack_a, t_list **results, int size);
int	get_closest_pos(t_list **stack, int number, int stacksize);
// closest
void	find_closest(t_closest *closest, t_list *stack, int number);
int		get_closest(t_list *stack, int number, int mode);
int		is_the_smallest(t_list *stack, int number);
int		is_the_biggest(t_list *stack, int number);

// sort_state_operations
void sort_state_0(t_list **stack_a, t_list **results);
void sort_state_1(t_list **stack_a, t_list **results);
void sort_state_2(t_list **stack_a, t_list **results);
void sort_state_3(t_list **stack_a, t_list **results);
void sort_state_4(t_list **stack_a, t_list **results);
//sort_utils
int get_sort_state(t_list *stack);
// utils
void DEBUG__print_lst(t_list *list, char mode);
void print_results(t_list *results);
void pretty_print(t_list *stack_a, t_list *stack_b);
int get_list_biggest(t_list *stack);
int get_list_smallest(t_list *stack);
// chunks_operations
long long int **create_chunks(void);
void populate_chunks(long long int **chunks, t_list **stack);
int chunk_is_empty(long long int *chunk, int chunk_size);
int is_in_chunk(long long int *chunk, int number, int chunk_size);
void	gtfo_my_chunk(long long int *chunk, long long int number, int chunk_size);
// chunks_parsing
int	get_first_top_index(int *stack, int stack_size, long long int *chunk, int chunk_size);
int	get_first_bot_index(int *stack, int stack_size, long long int *chunk, int chunk_size);


#endif