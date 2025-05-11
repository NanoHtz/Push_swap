/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sorts.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgalvez- <fgalvez-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 20:39:48 by fgalvez-          #+#    #+#             */
/*   Updated: 2025/05/09 20:39:48 by fgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inc/push_swap.h"

int	steps_from_top(t_stack *stack, t_node *target)
{
	t_node	*current;
	int		steps;

	current = stack->top;
	steps = 0;
	while (current && current != target)
	{
		steps++;
		current = current->next;
	}
	if (!current)
		return (-1);
	return (steps);
}

void	move_in_range_to_top(t_stack *stack, t_node *target)
{
	int	top_steps;
	int	bottom_steps;

	if (!stack || !target)
		return ;
	top_steps = steps_from_top(stack, target);
	if (top_steps == -1)
		return ;
	bottom_steps = stack->size - top_steps;
	if (top_steps <= bottom_steps)
		rotate_up_to_target(stack, target);
	else
		rotate_down_to_target(stack, target);
}

void	final_rotate_to_min(t_stack *a_stack)
{
	t_node	*target;

	if (a_stack && a_stack->size > 0)
	{
		target = find_min_index(a_stack);
		if (target)
			move_in_range_to_top(a_stack, target);
	}
}

void	smart_insert_from_b(t_stack *a_stack, t_stack *b_stack)
{
	t_node	*best_node;

	while (b_stack && b_stack->size > 0)
	{
		calculate_costs(a_stack, b_stack);
		best_node = find_cheapest_move(b_stack);
		execute_move(a_stack, b_stack, best_node);
	}
}

void	small_sort(t_stack *a_stack, t_stack *b_stack)
{
	if (a_stack->size == 2)
		sa(a_stack);
	else if (a_stack->size == 3)
		sort_three(a_stack);
	else
	{
		push_all_but_three_to_b(a_stack, b_stack);
		sort_three(a_stack);
		smart_insert_from_b(a_stack, b_stack);
		final_rotate_to_min(a_stack);
	}
}
