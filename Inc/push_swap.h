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
	struct Node	*next;
}				t_node;

typedef struct Stack
{
	t_node	*top;
	int		size;
}				t_stack;

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
//Algoritm
int insertion_sort(t_stack *a_stack, t_stack *b_stack);
int three_numbers(t_stack *a_stack);
//int insertion_sortb(t_stack *a_stack, t_stack *b_stack);
#endif
