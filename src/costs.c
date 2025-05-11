/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   costs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgalvez- <fgalvez-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 18:04:09 by fgalvez-          #+#    #+#             */
/*   Updated: 2025/05/11 18:04:09 by fgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inc/push_swap.h"

int	total_cost(t_node *node)
{
	int	abs_a;
	int	abs_b;

	abs_a = abs_val(node->a_cost);
	abs_b = abs_val(node->b_cost);
	if ((node->a_cost >= 0 && node->b_cost >= 0)
		|| (node->a_cost < 0 && node->b_cost < 0))
	{
		if (abs_a > abs_b)
			return (abs_a);
		else
			return (abs_b);
	}
	return (abs_a + abs_b);
}

static int	calc_b_cost(int pos, int size)
{
	if (pos <= size / 2)
		return (pos);
	else
		return (pos - size);
}

static void	assign_target_and_a_cost(t_stack *a, t_node *node_b, int size_a)
{
	t_node	*target;
	int		pos_a;

	if (is_biggest_or_smallest(a, node_b->index))
		target = find_min_index(a);
	else
	{
		target = get_directly_above_index(a, node_b->index);
		if (!target)
			target = find_min_index(a);
	}
	node_b->target = target;
	pos_a = steps_from_top(a, target);
	if (pos_a <= size_a / 2)
		node_b->a_cost = pos_a;
	else
		node_b->a_cost = (pos_a - size_a);
}

void	calculate_costs(t_stack *a_stack, t_stack *b_stack)
{
	t_node	*node_b;
	int		pos_b;
	int		size_a;
	int		size_b;

	size_a = a_stack->size;
	size_b = b_stack->size;
	node_b = b_stack->top;
	pos_b = 0;
	while (node_b)
	{
		node_b->b_cost = calc_b_cost(pos_b, size_b);
		assign_target_and_a_cost(a_stack, node_b, size_a);
		node_b = node_b->next;
		pos_b++;
	}
}

t_node	*find_cheapest_move(t_stack *b_stack)
{
	t_node	*current;
	t_node	*cheapest;
	int		min_cost;
	int		cost;

	if (!b_stack || !b_stack->top)
		return (NULL);
	current = b_stack->top;
	cheapest = current;
	min_cost = total_cost(current);
	while (current)
	{
		cost = total_cost(current);
		if (cost < min_cost)
		{
			min_cost = cost;
			cheapest = current;
		}
		current = current->next;
	}
	return (cheapest);
}
