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

//comprobar duplicados
//atoi
//minimos y maximos


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

int limits(const char *str)
{
	char *endptr;
	long nbr = strtol(str, &endptr, 10);

	if (*endptr != '\0') {
		printf("Error: La cadena contiene caracteres no numéricos.\n");
		return 0;
	}
	if (nbr > INT_MAX) {
		printf("Error: El número es mayor que el límite máximo de int (%d)\n", INT_MAX);
		return 0;
	} else if (nbr < INT_MIN) {
		printf("Error: El número es menor que el límite mínimo de int (%ld)\n", INT_MIN);
		return 0;
	}
	return 1;
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
		//if (limits(nbr) == 0)
		push(stack, nbr);
		i++;
	}
	return (1);
}
