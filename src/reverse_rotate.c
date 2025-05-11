/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgalvez- <fgalvez-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 19:36:04 by fgalvez-          #+#    #+#             */
/*   Updated: 2025/05/09 19:36:04 by fgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inc/push_swap.h"

//Desplaza hacia abajo todos los elementos del stack,
//el ultimo pasa a ser el primero

void	rra(t_stack *a_stack)
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
	write(1, "rra\n", 4);
}

void	rrb(t_stack *b_stack)
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
	write(1, "rrb\n", 4);
}

void	rotate_down_to_target(t_stack *stack, t_node *target)
{
	while (stack->top != target)
		rra(stack);
}
