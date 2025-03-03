/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgalvez- <fgalvez-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 17:33:15 by fgalvez-          #+#    #+#             */
/*   Updated: 2024/12/22 17:33:15 by fgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inc/push_swap.h"

int	tidy(t_stack *stack)
{
	t_node	*current;

	current = stack->top;
	while (current != NULL && current->next != NULL)
	{
		if (current->data > current->next->data)
		{
			ft_warning(NO_ORDER);
			return (0);
		}
		current = current->next;
	}
	ft_success(ORDER);
	return (1);
}

int	update_size(t_stack	*stack)
{
	t_node	*aux;
	int		i;

	i = 0;
	aux = stack->top;
	while (aux != NULL)
	{
		aux = aux->next;
		i++;
	}
	return (i);
}

void	update_position(t_stack	*stack)
{
	t_node	*aux;
	int		i;

	i = 0;
	aux = stack->top;
	while (aux != NULL)
	{
		aux->pos = i;
		aux = aux->next;
		i++;
	}
}

int	min_index(t_stack *stack)
{
	t_node	*aux;
	int		min;
	int		i;

	aux = stack->top;
	i = INT_MAX;
	min = 0;
	update_position(stack);
	while (aux != NULL)
	{
		if (aux->data < i)
		{
			i = aux->data;
			min = aux->pos;
		}
		aux = aux->next;
	}
	return (min);
}

void	order(t_stack *stack)
{
	int	min_pos;
	int	size;

	size = update_size(stack);
	min_pos = min_index(stack);
	if (min_pos > size / 2)
	{
		while (min_pos < size)
		{
			rra(stack);
			min_pos++;
		}
	}
	else
	{
		while (min_pos > 0)
		{
			ra(stack);
			min_pos--;
		}
	}
}

void	put_in_middle(t_stack *a_stack, t_stack *b_stack, t_group *nodes)
{
	int	i;

	i = 0;
	while (nodes->b_init->data > nodes->a_init->data
		&& nodes->b_init->data < nodes->a_last->data)
	{
		ra(a_stack);
		i++;
		nodes->a_init = a_stack->top;
	}
	pa(a_stack, b_stack);
	while (i > 0)
	{
		rra(a_stack);
		i--;
	}
}

void	compare(t_stack *a_stack, t_stack *b_stack)
{
	t_group	*nodes;

	nodes = init_nodes(a_stack, b_stack);
	if (nodes->b_init->data < nodes->a_init->data)
		pa(a_stack, b_stack);
	else if (nodes->b_init->data > nodes->a_last->data)
		pa(a_stack, b_stack);
	else if (nodes->b_last->data < nodes->a_init->data)
	{
		rrb(b_stack);
		pa(a_stack, b_stack);
	}
	else if (nodes->b_last->data > nodes->a_last->data)
	{
		rrb(b_stack);
		pa(a_stack, b_stack);
	}
	else
		put_in_middle(a_stack, b_stack, nodes);
	free (nodes);
}
