/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgalvez- <fgalvez-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 14:28:38 by fgalvez-          #+#    #+#             */
/*   Updated: 2024/12/08 14:28:38 by fgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inc/push_swap.h"

int	take_last(t_stack *a_stack)
{
	t_node	*node;

	node = a_stack->top;
	while (node->next != NULL)
	{
		node = node->next;
	}
	return (node->data);
}

int three_numbers(t_stack *a_stack)
{
	int top;
	int middle;
	int bottom;
	int moves;

	top = a_stack->top->data;
	middle = a_stack->top->next->data;
	bottom = a_stack->top->next->next->data;
	moves = 0;
	if (top > middle && middle > bottom)
	{
		sa(a_stack);
		ra(a_stack);
		ra(a_stack);
		moves += 3;
	}
	else if (top > middle)
	{
		sa(a_stack);
		moves++;
	}
	else if (middle > bottom)
	{
		ra(a_stack);
		moves++;
	}
	return moves;
}

/*
int insertion_sort(t_stack *a_stack, t_stack *b_stack)
{
	int	top;
	int	moves;

	moves = 0;
	while (a_stack->top != NULL)
	{
		top = a_stack->top->data;
		pb(a_stack, b_stack);
		moves++;
		while (b_stack->top != NULL && b_stack->top->data > top)
		{
			rb(b_stack);
			moves++;
		}
	}
	while (b_stack->top != NULL)
	{
		pa(a_stack, b_stack);
		moves++;
	}
	return (moves);
}
*/
/*
int insertion_sortb(t_stack *a_stack, t_stack *b_stack)
{
	int		top;
	t_node	*last;
	int		last_value;
	int		moves;

	moves = 0;
	while (a_stack->top != NULL)
	{
		top = a_stack->top->data;//Almacenamos el valor de top.
		if (a_stack->top->next->data < top)
		{
			sa(a_stack);
			moves++;
		}
		last = a_stack->top;
		while (last->next != NULL)
			last = last->next;
		last_value = last->data;
		if (top < last_value)
			ra(a_stack);
	}
	return (moves);
}*/
