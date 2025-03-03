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

//$>ARG="3 1 5 2 4"; ./push_swap $ARG | wc -l
//ARG="3 1 5 2 4"; ./push_swap $ARG | ./checker_linux $ARG
//Que es la Complejidad
//Para pocos argumentos, bubble sort o insertion sort
//Para mas argumentos, quick sort o merge sort
//Es posible que no nos interese para nada el tamaño de la pila.
//Creacion de la pila 1- check
//Argumentos duplicados- check
//Argumentos int- check
//Argumentos duplicados-check
//Creación de la pila vacia b-check
//Creación y comprobación de las operaciones-check
//Para 3 argumentos-check
//Para 5 argumentos-En proceso
//Para 100 argumentos-?
//Para 500 argumentos-?
//Bonus checker-?

#include "../Inc/push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*a_stack;
	t_stack	*b_stack;
	int		i;

	i = 0;
	if (ac <= 3)
		return (ft_error(ARGS_ERROR));
	while (i < (ac - 1))
		i++;
	a_stack = init_stack(i);
	if (validate_and_push(ac, av, a_stack) == -1)
		return (ft_error(VALIDATE));
	b_stack = init_stack(0);
	print_stack(a_stack);
	if (tidy(a_stack) == 0)
	{
		if (i == 3)
			three_numbers(a_stack);
		else if (i > 3)
			push_swap(a_stack, b_stack);
	}
	print_stack(a_stack);
	tidy(a_stack);
	free_stack(a_stack);
	free_stack(b_stack);
}
