/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgalvez- <fgalvez-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 19:03:14 by fgalvez-          #+#    #+#             */
/*   Updated: 2025/05/09 19:03:14 by fgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inc/push_swap.h"

static int	validate_and_push(char **args, int count, t_stack *a_stack)
{
	int		i;
	long	l_nbr;
	int		nbr;

	i = 0;
	while (i < count)
	{
		if (is_number(args[i]) == -1)
			return (-1);
		l_nbr = ft_atol(args[i]);
		if (l_nbr < INT_MIN || l_nbr > INT_MAX)
			return (-1);
		nbr = (int)l_nbr;
		if (is_duplicate(a_stack, nbr) == -1)
			return (-1);
		push_back(a_stack, nbr);
		i++;
	}
	return (0);
}

static char	**get_arguments(int ac, char **av)
{
	char	**args;

	if (ac == 2)
	{
		args = ft_split(av[1], ' ');
		if (!args || !*args)
		{
			ft_free_split(args);
			return (NULL);
		}
	}
	else
		args = av + 1;
	return (args);
}

int	check_arguments(int ac, char **av, t_stack *a_stack)
{
	char	**args;
	int		count;

	if (ac == 1)
		return (-1);
	args = get_arguments(ac, av);
	if (!args)
		return (-1);
	count = count_arguments(args);
	if (validate_and_push(args, count, a_stack) == -1)
	{
		free_args(args, ac);
		return (-1);
	}
	free_args(args, ac);
	return (count);
}
