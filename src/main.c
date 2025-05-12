/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgalvez- <fgalvez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 14:10:05 by fgalvez-          #+#    #+#             */
/*   Updated: 2024/12/05 15:14:50 by fgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inc/push_swap.h"

void	push_swap(t_stack *a_stack, t_stack *b_stack)
{
	if (!is_sorted(a_stack))
	{
		if (a_stack->size <= 5)
			small_sort(a_stack, b_stack);
		else
			big_sort(a_stack, b_stack);
	}
}

int	main(int ac, char **av)
{
	t_stack	*a_stack;
	t_stack	*b_stack;

	a_stack = init_stack();
	b_stack = init_stack();
	a_stack->size = check_arguments(ac, av, a_stack);
	if (a_stack->size == -1)
	{
		write(2, "Error\n", 6);
		free_stack(a_stack);
		free_stack(b_stack);
		return (-1);
	}
	assign_indices(a_stack);
	mark_lis(a_stack);
	push_swap(a_stack, b_stack);
	free_stack(a_stack);
	free_stack(b_stack);
}
