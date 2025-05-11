/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   silent_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgalvez- <fgalvez-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 18:16:42 by fgalvez-          #+#    #+#             */
/*   Updated: 2025/05/11 18:16:42 by fgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inc/push_swap.h"

void	silent_rra(t_stack *a_stack)
{
	t_node	*last;
	t_node	*second_last;

	if (!a_stack || !a_stack->top || !a_stack->top->next)
		return ;
	last = a_stack->top;
	while (last->next)
	{
		second_last = last;
		last = last->next;
	}
	second_last->next = NULL;
	last->next = a_stack->top;
	a_stack->top = last;
}

void	silent_rrb(t_stack *b_stack)
{
	t_node	*last;
	t_node	*second_last;

	if (!b_stack || !b_stack->top || !b_stack->top->next)
		return ;
	last = b_stack->top;
	while (last->next)
	{
		second_last = last;
		last = last->next;
	}
	second_last->next = NULL;
	last->next = b_stack->top;
	b_stack->top = last;
}

void	silent_ra(t_stack *a_stack)
{
	t_node	*first;
	t_node	*last;

	if (!a_stack || !a_stack->top || !a_stack->top->next)
		return ;
	first = a_stack->top;
	last = a_stack->top;
	while (last->next)
		last = last->next;
	a_stack->top = first->next;
	first->next = NULL;
	last->next = first;
}

void	silent_rb(t_stack *b_stack)
{
	t_node	*first;
	t_node	*last;

	if (!b_stack || !b_stack->top || !b_stack->top->next)
		return ;
	first = b_stack->top;
	last = b_stack->top;
	while (last->next)
		last = last->next;
	b_stack->top = first->next;
	first->next = NULL;
	last->next = first;
}
