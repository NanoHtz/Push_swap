/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgalvez- <fgalvez-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 09:51:50 by fgalvez-          #+#    #+#             */
/*   Updated: 2024/12/06 09:51:50 by fgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inc/push_swap.h"

t_stack	*init_stack(int size)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (ft_t_stack_error(MEM_ERROR));
	stack->size = size;
	stack->top = NULL;
	return (stack);
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

int	print_stack(t_stack *stack)
{
	int		i;
	t_node	*node;

	node = stack->top;
	i = 1;
	while (node != NULL)
	{
		printf("El elemento %d es: %d\n ", i, node->data);
		node = node->next;
		i++;
	}
	return (i);
}
