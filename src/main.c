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

/*
Para pocos argumentos, bubble sort o insertion sort
Para mas argumentos, quick sort o merge sort
-Crear la segunda pila-check
-Implementar als operaciones-check
-Algoritmo
-Pruebas de rendimiento
*/
//Es posible que no nos interese para nada el tamaño de la pila.
//Manejar los errores implica
//Funciones free, espabila./psh
#include "../Inc/push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*a_stack;
	t_stack	*b_stack;
	int		i;
	int		moves;

	i = 0;
	moves = 0;
	if (ac < 3)
		return (ft_error(ARGS_ERROR));
	while (i < (ac - 1))
		i++;
	printf("Se han introducido %d argumentos\n", i);
	a_stack = init_stack(i);
	if (validate_and_push(ac, av, a_stack) == -1)
		return (ft_error(VALIDATE));
	ft_success(VALID);
	b_stack = init_stack(i);
	printf("stack a:\n");
	print_stack(a_stack);
	if (i == 3)
		moves = three_numbers(a_stack);
	printf("stack a:\n");
	print_stack(a_stack);
	/*
	pb(a_stack, b_stack);
	pb(a_stack, b_stack);
	print_stack(a_stack);
	printf("stack b\n");
	*/
	printf("stack b:\n");
	print_stack(b_stack);
	printf("movimientos:%d\n", moves);
	//(void)b_stack;
}
