/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgalvez- <fgalvez-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 09:07:08 by fgalvez-          #+#    #+#             */
/*   Updated: 2025/05/11 09:07:08 by fgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inc/push_swap.h"

void	sort_three(t_stack *stack)
{
	int	biggest;

	if (is_sorted(stack) == 1)
		return ;
	biggest = biggest_index(stack);
	if (stack->top->index == biggest)
		ra(stack);
	else if (stack->top->next && stack->top->next->index == biggest)
		rra(stack);
	if (stack->top->index > stack->top->next->index)
		sa(stack);
}
