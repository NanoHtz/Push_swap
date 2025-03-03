/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgalvez- <fgalvez-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 15:08:29 by fgalvez-          #+#    #+#             */
/*   Updated: 2024/12/07 15:08:29 by fgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inc/push_swap.h"

//Pone el primer elemento de b en a como primer elemento (pa)

void	push(t_stack *stack, int value)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return (ft_void_error(PUSH_ERROR));
	new_node->data = value;
	new_node->next = stack->top;
	stack->top = new_node;
}

void	pa(t_stack *a_stack, t_stack *b_stack)
{
	t_node	*first;

	if (!a_stack || !b_stack || b_stack->top == NULL)
		return (ft_void_error(FEW_NODES));
	first = b_stack->top;
	b_stack->top = first->next;
	first->next = a_stack->top;
	a_stack->top = first;
	a_stack->size += 1;
	b_stack->size -= 1;
	write(1, "pa\n", 3);
}

void	pb(t_stack *a_stack, t_stack *b_stack)
{
	t_node	*first;

	if (!a_stack || !b_stack || a_stack->top == NULL)
		return (ft_void_error(FEW_NODES));
	first = a_stack->top;
	a_stack->top = first->next;
	first->next = b_stack->top;
	b_stack->top = first;
	b_stack->size += 1;
	a_stack->size -= 1;
	write(1, "pb\n", 3);
}
