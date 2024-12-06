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

int	main(int ac, char **av)
{
	t_stack	*stack;
	int		i;

	i = 0;
	if (ac < 3)
		return (ft_error(ARGS_ERROR));
	while (i < (ac - 1))
		i++;
	stack = malloc(sizeof(stack) * i);
	if (!stack)
		return (ft_error(MEM_ERROR));
	printf("Han sido %d argumentos.\n", i);
	stack->size = i;
	stack->top = NULL;
	stack->size = 0;
	validate(ac, av, stack);
	printf_stack(stack);
}
