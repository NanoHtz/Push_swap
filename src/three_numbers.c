/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgalvez- <fgalvez-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 14:28:38 by fgalvez-          #+#    #+#             */
/*   Updated: 2024/12/08 14:28:38 by fgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inc/push_swap.h"

void	three_numbers(t_stack *a_stack)
{
	int	top;
	int	middle;
	int	bottom;

	top = a_stack->top->data;
	middle = a_stack->top->next->data;
	bottom = a_stack->top->next->next->data;
	if (top > middle && middle > bottom && bottom < top)
	{
		sa(a_stack);
		rra(a_stack);
	}
	else if (bottom > top && top < middle && bottom < middle)
	{
		sa(a_stack);
		ra(a_stack);
	}
	else if (top > middle && middle < bottom && bottom < top)
		ra(a_stack);
	else if (bottom > middle && middle < top && bottom > top)
		sa(a_stack);
	else if (bottom < top && top < middle && top > bottom)
		rra(a_stack);
}

void	push_swap(t_stack *a_stack, t_stack *b_stack)
{
	while (a_stack->size > 3)
		pb(a_stack, b_stack);
	three_numbers(a_stack);
	while (b_stack->top != NULL)
	{
		objetive_pos(a_stack, b_stack);
	}
		//compare(a_stack, b_stack);
	order(a_stack);
	//get_position es update position

}

int	objetive_pos(t_stack *a, t_stack *b)
{
	t_node	*aux;
	int		pos;

	aux = b->top;
	update_position(a);
	update_position(b);
	pos = 0;
	while (aux != NULL)
	{
		pos = objetive(a, aux->pos, INT_MAX, pos);
		aux->target = pos;
		aux = aux->next;
	}
}

int	objetive(t_stack *a, int index, int target_i, int target)
{
	t_node	*aux;

	aux = *a->top;
	while (aux != NULL)
	{
		if (aux->pos > index && aux->index < target_i)
		{
			target_i = aux->index;
			target = aux->pos;
		}
		aux = aux->next;
	}
	if (target_i != INT_MAX)
		return (target);
	aux = *a;
	while (aux)
	{
		if (aux->index < target_i)
		{
			target_i = aux->index;
			target = aux->pos;
		}
		aux = aux->next;
	}
	return (target);
}
/*POR AQUI*/
void	cost(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*a_aux;
	t_stack	*b_aux;
	//prueba t_node	*a_node;
	//t_node	*b_node;
	int		size_a;
	int		size_b;

	a_aux = *stack_a;
	b_aux = *stack_b;
	size_a = update_size(a_aux);
	size_b = update_size(b_aux);
	while (b_aux)
	{
		b_aux->cost_b = b_node->pos;//b_node no se inicializa en este punto, no apunta a nada
		if (b_node->pos > size_b / 2)
			b_aux->cost_b = (size_b - b_node->pos) * -1;
		b_aux->cost_a = b_aux->target;
		if (b_aux->target > size_a / 2)
			b_aux->cost_a = (size_a - b_aux->target) * -1;
		b_aux = b_aux->next;
	}
}

void	cheapest_move(t_stack *stack_a, t_stack *stack_b)
{
	t_stack		*tmp;
	t_node		*aux;
	int			cheap;
	int			cost_a;
	int			cost_b;

	aux = stack_b->top;
	tmp = stack_b
	cheap = INT_MAX;
	while (tmp != NULL)
	{
		if (abs(stack_b->cost_a) + abs(stack_b->cost_b) < cheap)
		{
			cheap = abs(stack_b->cost_a) + abs(stack_b->cost_b);
			cost_a = stack_b->cost_a;
			cost_b = stack_b->cost_b;
		}
		aux = aux->next;
	}
	do_move(stack_a, stack_b, cost_a, cost_b);
}
