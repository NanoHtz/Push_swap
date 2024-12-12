/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgalvez- <fgalvez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 14:10:05 by fgalvez-          #+#    #+#             */
/*   Updated: 2024/12/05 15:13:19 by fgalvez-         ###   ########.fr       */
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

int	is_number(char	*av)
{
	int	i;

	i = 0;
	if (av[i] == '-')
		i++;
	while (av[i] != '\0')
	{
		if (ft_isdigit(av[i]) == 0)
			return (-1);
		i++;
	}
	return (1);
}

int	validate_and_push(int ac, char **av, t_stack *stack)
{
	int		i;
	long	l_nbr;
	int		nbr;

	i = 1;
	while (i < ac)
	{
		if (is_number(av[i]) == -1)
			return (ft_error(NO_NUMBER));
		l_nbr = ft_atol(av[i]);
		if (l_nbr < INT_MIN || l_nbr > INT_MAX)
			return (ft_error(OUT_OF_RANGE));
		nbr = (int)l_nbr;
		if (is_duplicate(stack, nbr) == -1)
			return (ft_error(DUPLICATE));
		push(stack, nbr);
		i++;
	}
	return (0);
}
