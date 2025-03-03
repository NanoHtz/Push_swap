/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgalvez- <fgalvez-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 15:10:23 by fgalvez-          #+#    #+#             */
/*   Updated: 2024/12/07 15:10:23 by fgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inc/push_swap.h"

//Desplaza hacia arriba todos los elementos del stack,
// el primero pasa a ser el último

void	ra(t_stack *a_stack)
{
	t_node	*first;
	t_node	*last;

	if (!a_stack || !a_stack->top || !a_stack->top->next)
		return (ft_void_error(FEW_NODES));
	first = a_stack->top;
	last = a_stack->top;
	while (last->next)
		last = last->next;
	a_stack->top = first->next;
	first->next = NULL;
	last->next = first;
	write(1, "ra\n", 3);
}

void	rb(t_stack *b_stack)
{
	t_node	*first;
	t_node	*last;

	if (!b_stack || !b_stack->top || !b_stack->top->next)
		return (ft_void_error(FEW_NODES));
	first = b_stack->top;
	last = b_stack->top;
	while (last->next)
		last = last->next;
	b_stack->top = first->next;
	first->next = NULL;
	last->next = first;
	write(1, "rb\n", 3);
}

void	rr(t_stack *a_stack, t_stack *b_stack)
{
	ra(a_stack);
	rb(b_stack);
}
