/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_move.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgalvez- <fgalvez-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 21:59:56 by fgalvez-          #+#    #+#             */
/*   Updated: 2025/05/11 21:59:56 by fgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inc/push_swap.h"

static void	do_double_rotate(t_stack *a, t_stack *b, t_node *node)
{
	while (node->a_cost < 0 && node->b_cost < 0)
	{
		rrr(a, b);
		node->a_cost++;
		node->b_cost++;
	}
	while (node->a_cost > 0 && node->b_cost > 0)
	{
		rr(a, b);
		node->a_cost--;
		node->b_cost--;
	}
}

static void	do_single_rotate(t_stack *a, t_stack *b, t_node *node)
{
	while (node->a_cost > 0)
	{
		ra(a);
		node->a_cost--;
	}
	while (node->a_cost < 0)
	{
		rra(a);
		node->a_cost++;
	}
	while (node->b_cost > 0)
	{
		rb(b);
		node->b_cost--;
	}
	while (node->b_cost < 0)
	{
		rrb(b);
		node->b_cost++;
	}
}

void	execute_move(t_stack *a, t_stack *b, t_node *node)
{
	do_double_rotate(a, b, node);
	do_single_rotate(a, b, node);
	pa(a, b);
}
