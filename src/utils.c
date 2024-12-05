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
#include <stdio.h>

//comprobar duplicados
//atoi
//

int	is_number(char	*av)
{
	int	i;

	i = 0;
	if (av[i] == '-')
		i++;
	while (av[i] != '\0')
	{
		if (ft_isdigit(av[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}


int	validate(int ac, char **av, t_stack *stack)
{
	int	i;
	int	nbr;

	i = 1;
	while (i < ac)
	{
		if (is_number(av[i]) == 0)
			return (ft_error(NO_NUMBER));
		nbr = ft_atoi(av[i]);
		push(stack, nbr);
		i++;
	}
	return (1);
}

