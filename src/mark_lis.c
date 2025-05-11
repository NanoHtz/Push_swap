/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mark_lis.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgalvez- <fgalvez-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 21:57:11 by fgalvez-          #+#    #+#             */
/*   Updated: 2025/05/11 21:57:11 by fgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inc/push_swap.h"

void	mark_lis(t_stack *stack)
{
	int	*lis_length;
	int	*prev_index;
	int	*keep_flags;
	int	size;

	if (!stack || stack->size == 0)
		return ;
	size = stack->size;
	lis_length = malloc(sizeof(int) * size);
	prev_index = malloc(sizeof(int) * size);
	if (!lis_length || !prev_index)
		return ;
	build_lis_data(stack, lis_length, prev_index);
	keep_flags = get_keep_flags(lis_length, prev_index, size);
	apply_keep_flags(stack, keep_flags);
	free(lis_length);
	free(prev_index);
	free(keep_flags);
}
