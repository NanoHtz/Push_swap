/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgalvez- <fgalvez-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 11:14:00 by fgalvez-          #+#    #+#             */
/*   Updated: 2025/05/11 11:14:00 by fgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inc/push_swap.h"

int	has_node_in_chunk(t_stack *stack, int chunk_start, int chunk_end)
{
	t_node	*current;

	current = stack->top;
	while (current)
	{
		if (current->index >= chunk_start && current->index < chunk_end
			&& current->keep == 0)
			return (1);
		current = current->next;
	}
	return (0);
}

t_node	*find_closest_in_chunk(t_stack *stack, int chunk_start, int chunk_end)
{
	t_node	*current;

	current = stack->top;
	while (current)
	{
		if (current->index >= chunk_start && current->index < chunk_end
			&& current->keep == 0)
			return (current);
		current = current->next;
	}
	return (NULL);
}

void	sort_chunk(t_stack *a_stack, t_stack *b_stack,
	int chunk_start, int chunk_end)
{
	t_node	*target;
	int		mid_chunk;

	mid_chunk = (chunk_start + chunk_end) / 2;
	while (has_node_in_chunk(a_stack, chunk_start, chunk_end))
	{
		target = find_closest_in_chunk(a_stack, chunk_start, chunk_end);
		if (!target)
			break ;
		move_in_range_to_top(a_stack, target);
		pb(a_stack, b_stack);
		if (target->index < mid_chunk)
			rb(b_stack);
	}
}

void	big_sort(t_stack *a_stack, t_stack *b_stack)
{
	int		chunk_count;
	int		chunk_size;
	int		chunk_start;
	int		chunk_end;
	int		max_index;

	if (!a_stack)
		return ;
	if (a_stack->size <= 100)
		chunk_count = 5;
	else
		chunk_count = 10;
	max_index = biggest_index(a_stack);
	chunk_size = (max_index + 1) / chunk_count;
	chunk_start = 0;
	while (chunk_start <= max_index)
	{
		chunk_end = chunk_start + chunk_size;
		if (chunk_end > max_index + 1)
			chunk_end = max_index + 1;
		sort_chunk(a_stack, b_stack, chunk_start, chunk_end);
		chunk_start += chunk_size;
	}
	smart_insert_from_b(a_stack, b_stack);
	final_rotate_to_min(a_stack);
}
