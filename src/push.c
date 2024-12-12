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

void	pa(t_stack *a_stack, t_stack *b_stack)
{
	t_node	*first;

	if (!a_stack || !b_stack || b_stack->top == NULL)
		return (ft_void_error(FEW_NODES));
	first = b_stack->top;
	b_stack->top = first->next;
	first->next = a_stack->top;
	a_stack->top = first;
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
	write(1, "pb\n", 3);
}
