/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgalvez- <fgalvez-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 08:51:17 by fgalvez-          #+#    #+#             */
/*   Updated: 2025/05/11 08:51:17 by fgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inc/push_swap.h"

int	is_duplicate(t_stack *stack, int nbr)
{
	t_node	*node;

	node = stack->top;
	while (node != NULL)
	{
		if (nbr == node->data)
			return (-1);
		node = node->next;
	}
	return (0);
}

int	is_number(char *av)
{
	int	i;

	i = 0;
	if (av[i] == '-' || av[i] == '+')
		i++;
	if (av[i] == '\0')
		return (-1);
	while (av[i] != '\0' && av[i] != '\n')
	{
		if (ft_isdigit(av[i]) == 0)
			return (-1);
		i++;
	}
	return (0);
}

int	count_arguments(char **args)
{
	int	count;

	count = 0;
	while (args[count])
		count++;
	return (count);
}
