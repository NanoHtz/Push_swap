/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgalvez- <fgalvez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 21:16:53 by fgalvez-          #+#    #+#             */
/*   Updated: 2024/12/05 15:09:58 by fgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "utils/errors.h"
# include "libft/libft.h"
# include <stdlib.h>//malloc
# include <stdio.h>//Para pruebas de printf, de momento, borrar al terminar.

typedef struct Node
{
	int			data;
	int			pos;
	int			index;
	int			keep;
	struct Node	*next;
	struct Node	*target;
	int			a_cost;
	int			b_cost;
}				t_node;

typedef struct Stack
{
	t_node	*top;
	int		size;
	int		target;
}				t_stack;

typedef struct s_lis_helper
{
	int		i;
	int		*lis;
	int		*prev;
	t_stack	*stack;
	t_node	*cur_i;
}	t_lis_helper;

//Stacks.
t_stack	*init_stack(void);

//Arguments
int		check_arguments(int ac, char **av, t_stack *a_stack);
int		is_duplicate(t_stack *stack, int nbr);
int		is_number(char *av);
int		count_arguments(char **args);
//Index
void	assign_indices(t_stack *stack);
t_node	*find_min_index(t_stack *stack);
int		biggest_index(t_stack *stack);
int		is_biggest_or_smallest(t_stack *stack, int index);
t_node	*get_directly_above_index(t_stack *stack, int value);
//Sort_three
void	sort_three(t_stack *stack);
//Memory
void	free_args(char **args, int ac);
void	free_stack(t_stack *stack);
//Stack_utils
int		stack_size(t_stack *stack);
int		actualice_size(t_stack *stack);
//Small_sort
void	small_sort(t_stack *a_stack, t_stack *b_stack);
void	move_in_range_to_top(t_stack *stack, t_node *target);
void	final_rotate_to_min(t_stack *a_stack);
void	smart_insert_from_b(t_stack *a_stack, t_stack *b_stack);
//big sort
void	big_sort(t_stack *a_stack, t_stack *b_stack);
void	sort_chunk(t_stack *a_stack, t_stack *b_stack,
			int chunk_start, int chunk_end);
int		has_node_in_chunk(t_stack *stack, int chunk_start, int chunk_end);
//Sorted
int		is_sorted(t_stack *stack);
//Moves
void	push(t_stack *stack, int value);
void	push_back(t_stack *stack, int value);
void	push_all_but_three_to_b(t_stack *a_stack, t_stack *b_stack);
void	rotate_up_to_target(t_stack *stack, t_node *target);
void	rotate_down_to_target(t_stack *stack, t_node *target);
void	silent_rra(t_stack *a_stack);
void	silent_rrb(t_stack *b_stack);
void	silent_ra(t_stack *a_stack);
void	silent_rb(t_stack *b_stack);
void	ss(t_stack *a_stack, t_stack *b_stack);
void	sb(t_stack *b_stack);
void	sa(t_stack *a_stack);
void	rr(t_stack *a_stack, t_stack *b_stack);
void	rb(t_stack *b_stack);
void	ra(t_stack *a_stack);
void	rrr(t_stack *a_stack, t_stack *b_stack);
void	rrb(t_stack *b_stack);
void	rra(t_stack *a_stack);
void	pb(t_stack *a_stack, t_stack *b_stack);
void	pa(t_stack *a_stack, t_stack *b_stack);
//Costs
void	calculate_costs(t_stack *a_stack, t_stack *b_stack);
t_node	*find_cheapest_move(t_stack *b_stack);
void	execute_move(t_stack *a_stack, t_stack *b_stack, t_node *node);
void	mark_lis(t_stack *stack);
int		steps_from_top(t_stack *stack, t_node *target);
void	apply_keep_flags(t_stack *stack, int *flags);
int		find_max_index(int *lis, int size);
int		*get_keep_flags(int *lis, int *prev, int size);
void	update_lis_entry(t_lis_helper *data);
void	build_lis_data(t_stack *stack, int *lis, int *prev);
int		abs_val(int x);

#endif
