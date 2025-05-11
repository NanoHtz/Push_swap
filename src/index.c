/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgalvez- <fgalvez-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 13:12:22 by fgalvez-          #+#    #+#             */
/*   Updated: 2025/05/10 13:12:22 by fgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inc/push_swap.h"

void	assign_indices(t_stack *stack)
{
	t_node	*current;
	t_node	*other;
	int		index;

	current = stack->top;
	while (current)
	{
		index = 0;
		other = stack->top;
		while (other)
		{
			if (other->data < current->data)
				index++;
			other = other->next;
		}
		current->index = index;
		current = current->next;
	}
}

t_node	*find_min_index(t_stack *stack)
{
	t_node	*current;
	t_node	*min_node;

	if (!stack || !stack->top)
		return (NULL);
	current = stack->top;
	min_node = current;
	while (current)
	{
		if (current->index < min_node->index)
			min_node = current;
		current = current->next;
	}
	return (min_node);
}

int	biggest_index(t_stack *stack)
{
	t_node	*current;
	int		index;

	if (!stack || !stack->top)
		return (-1);
	current = stack->top;
	index = current->index;
	while (current)
	{
		if (current->index > index)
			index = current->index;
		current = current->next;
	}
	return (index);
}

int	is_biggest_or_smallest(t_stack *stack, int index)
{
	t_node	*current;
	int		is_biggest;
	int		is_smallest;

	is_biggest = 1;
	is_smallest = 1;
	if (!stack || !stack->top)
		return (0);
	current = stack->top;
	while (current)
	{
		if (index < current->index)
			is_biggest = 0;
		if (index > current->index)
			is_smallest = 0;
		current = current->next;
	}
	if (is_biggest)
		return (1);
	else if (is_smallest)
		return (-1);
	return (0);
}

t_node	*get_directly_above_index(t_stack *stack, int value)
{
	t_node	*current;
	t_node	*closest;

	closest = NULL;
	if (!stack || !stack->top)
		return (NULL);
	current = stack->top;
	while (current)
	{
		if (current->index > value)
		{
			if (!closest)
				closest = current;
			else if (current->index < closest->index)
				closest = current;
		}
		current = current->next;
	}
	if (!closest)
		closest = find_min_index(stack);
	return (closest);
}
