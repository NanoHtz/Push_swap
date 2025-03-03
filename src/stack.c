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

t_node	*last(t_stack *stack)
{
	t_node	*last;

	last = stack->top;
	while (last != NULL && last->next != NULL)
		last = last->next;
	return (last);
}

t_group	*init_nodes(t_stack *a_stack, t_stack *b_stack)
{
	t_group	*nodes;

	nodes = (t_group *)malloc(sizeof(t_group));
	if (nodes == NULL)
		return (NULL);
	nodes->a_init = a_stack->top;
	nodes->b_init = b_stack->top;
	nodes->a_last = last(a_stack);
	nodes->b_last = last(b_stack);
	return (nodes);
}

void	free_stack(t_stack *stack)
{
	t_node	*current;
	t_node	*next;

	if (!stack)
		return ;
	current = stack->top;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	free(stack);
}
