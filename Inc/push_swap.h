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
	struct Node	*next;
}				t_node;

typedef struct Stack
{
	t_node	*top;
	int		size;
	int		target;
	int		a_cost;
	int		b_cost;
}				t_stack;

typedef struct group
{
	t_node	*a_init;
	t_node	*b_init;
	t_node	*a_last;
	t_node	*b_last;
}	t_group;

//Arguments
int		validate_and_push(int ac, char **av, t_stack *stack);
int		is_number(char	*av);
int		limits(const char *str);
//Stacks
void	push(t_stack *stack, int value);
t_stack	*init_stack(int size);
int		print_stack(t_stack *stack);
//operators
void	sa(t_stack *a_stack);
void	sb(t_stack *b_stack);
void	ss(t_stack *a_stack, t_stack *b_stack);
void	pa(t_stack *a_stack, t_stack *b_stack);
void	pb(t_stack *a_stack, t_stack *b_stack);
void	ra(t_stack *a_stack);
void	rb(t_stack *b_stack);
void	rr(t_stack *a_stack, t_stack *b_stack);
void	rra(t_stack *a_stack);
void	rrb(t_stack *b_stack);
void	rrr(t_stack *a_stack, t_stack *b_stack);
//utils
t_stack	*ft_t_stack_error(const char *str);
void	free_stack(t_stack *stack);
//Algoritm
t_group	*init_nodes(t_stack *a_stack, t_stack *b_stack);
//int		min_pos(t_stack *a_stack);
void	order(t_stack *stack);
void	three_numbers(t_stack *a_stack);
void	push_swap(t_stack *a_stack, t_stack *b_stack);
//int calculate_insert_position(t_stack *a_stack, int value);
void	compare(t_stack *a_stack, t_stack *b_stack);
//order
int		tidy(t_stack *stack);
#endif
