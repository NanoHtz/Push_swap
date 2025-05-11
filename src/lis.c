/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgalvez- <fgalvez-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 18:42:07 by fgalvez-          #+#    #+#             */
/*   Updated: 2025/05/11 18:42:07 by fgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inc/push_swap.h"

void	apply_keep_flags(t_stack *stack, int *flags)
{
	t_node	*node;
	int		i;

	node = stack->top;
	i = 0;
	while (node)
	{
		node->keep = flags[i];
		node = node->next;
		i++;
	}
}

int	find_max_index(int *lis, int size)
{
	int	max;
	int	index;
	int	i;

	max = lis[0];
	index = 0;
	i = 1;
	while (i < size)
	{
		if (lis[i] > max)
		{
			max = lis[i];
			index = i;
		}
		i++;
	}
	return (index);
}

int	*get_keep_flags(int *lis, int *prev, int size)
{
	int	*flags;
	int	pos;

	flags = calloc(size, sizeof(int));
	if (!flags)
		return (NULL);
	pos = find_max_index(lis, size);
	while (pos != -1)
	{
		flags[pos] = 1;
		pos = prev[pos];
	}
	return (flags);
}

void	update_lis_entry(t_lis_helper *data)
{
	t_node	*cur_j;
	int		j;

	cur_j = data->stack->top;
	j = 0;
	while (j < data->i)
	{
		if (cur_j->index < data->cur_i->index
			&& data->lis[j] + 1 > data->lis[data->i])
		{
			data->lis[data->i] = data->lis[j] + 1;
			data->prev[data->i] = j;
		}
		cur_j = cur_j->next;
		j++;
	}
}

void	build_lis_data(t_stack *stack, int *lis, int *prev)
{
	t_lis_helper	data;
	t_node			*cur_i;
	int				i;

	data.lis = lis;
	data.prev = prev;
	data.stack = stack;
	cur_i = stack->top;
	i = 0;
	while (cur_i)
	{
		data.i = i;
		data.cur_i = cur_i;
		lis[i] = 1;
		prev[i] = -1;
		update_lis_entry(&data);
		cur_i = cur_i->next;
		i++;
	}
}
