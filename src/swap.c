/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgalvez- <fgalvez-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 19:36:57 by fgalvez-          #+#    #+#             */
/*   Updated: 2025/05/09 19:36:57 by fgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inc/push_swap.h"

//Cambia los valores del primer y el segundo elemento.

void	sa(t_stack *a_stack)
{
	t_node	*first;
	t_node	*second;

	if (!a_stack || !a_stack->top || !a_stack->top->next)
		return (ft_void_error(FEW_NODES));
	first = a_stack->top;
	second = first->next;
	first->next = second->next;
	second->next = first;
	a_stack->top = second;
	write(1, "sa\n", 3);
}

void	sb(t_stack *b_stack)
{
	t_node	*first;
	t_node	*second;

	if (!b_stack || !b_stack->top || !b_stack->top->next)
		return (ft_void_error(FEW_NODES));
	first = b_stack->top;
	second = first->next;
	first->next = second->next;
	second->next = first;
	b_stack->top = second;
	write(1, "sb\n", 3);
}
