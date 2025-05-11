/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgalvez- <fgalvez-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 19:07:29 by fgalvez-          #+#    #+#             */
/*   Updated: 2025/05/09 19:07:29 by fgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inc/push_swap.h"

static t_stack	*ft_t_stack_error(const char *str)
{
	write(1, "\033[31m", 5);
	ft_strendl(str);
	write(1, "\033[0m", 4);
	return (NULL);
}

t_stack	*init_stack(void)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (ft_t_stack_error(MEM_ERROR));
	stack->size = 0;
	stack->top = NULL;
	return (stack);
}

void	free_stack(t_stack *stack)
{
	t_node	*current;
	t_node	*next;

	if (!stack)
		return ;
	current = stack->top;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	free(stack);
}

int	actualice_size(t_stack *stack)
{
	if (!stack)
		return (0);
	return (stack->size);
}

int	stack_size(t_stack *stack)
{
	t_node	*current;
	int		count;

	if (!stack || !stack->top)
		return (0);
	current = stack->top;
	count = 0;
	while (current)
	{
		count++;
		current = current->next;
	}
	return (count);
}
