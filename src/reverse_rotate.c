/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgalvez- <fgalvez-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 15:10:00 by fgalvez-          #+#    #+#             */
/*   Updated: 2024/12/07 15:10:00 by fgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inc/push_swap.h"

void	rra(t_stack *a_stack)
{
	t_node	*last;
	t_node	*second_last;

	if (!a_stack || !a_stack->top || !a_stack->top->next)
		return (ft_void_error(FEW_NODES));
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

void	rrb(t_stack *b_stack)
{
	t_node	*last;
	t_node	*second_last;

	if (!b_stack || !b_stack->top || !b_stack->top->next)
		return (ft_void_error(FEW_NODES));
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

void	rrr(t_stack *a_stack, t_stack *b_stack)
{
	rra(a_stack);
	rrb(b_stack);
}
