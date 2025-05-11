/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   combine_moves.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgalvez- <fgalvez-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 18:14:35 by fgalvez-          #+#    #+#             */
/*   Updated: 2025/05/11 18:14:35 by fgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inc/push_swap.h"

void	rrr(t_stack *a_stack, t_stack *b_stack)
{
	silent_rra(a_stack);
	silent_rrb(b_stack);
	write(1, "rrr\n", 4);
}

void	rr(t_stack *a_stack, t_stack *b_stack)
{
	silent_ra(a_stack);
	silent_rb(b_stack);
	write(1, "rr\n", 3);
}
