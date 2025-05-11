/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgalvez- <fgalvez-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 19:06:17 by fgalvez-          #+#    #+#             */
/*   Updated: 2025/05/09 19:06:17 by fgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inc/push_swap.h"

void	push_back(t_stack *stack, int value)
{
	t_node	*new_node;
	t_node	*current;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return ;
	new_node->data = value;
	new_node->index = -1;
	new_node->next = NULL;
	new_node->a_cost = 0;
	new_node->b_cost = 0;
	new_node->keep = 0;
	new_node->target = NULL;
	if (!stack->top)
	{
		stack->top = new_node;
		stack->size++;
		return ;
	}
	current = stack->top;
	while (current->next)
		current = current->next;
	current->next = new_node;
	stack->size++;
}

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
		return ;
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
		return ;
	first = a_stack->top;
	a_stack->top = first->next;
	first->next = b_stack->top;
	b_stack->top = first;
	b_stack->size += 1;
	a_stack->size -= 1;
	write(1, "pb\n", 3);
}

void	push_all_but_three_to_b(t_stack *a_stack, t_stack *b_stack)
{
	while (a_stack->size > 3)
		pb(a_stack, b_stack);
}
