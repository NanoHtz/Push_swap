/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgalvez- <fgalvez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 21:16:53 by fgalvez-          #+#    #+#             */
/*   Updated: 2024/12/05 15:09:58 by fgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "utils/errors.h"
# include "libft/libft.h"

typedef struct Node
{
	int			data;
	struct Node	*next;
}				t_node;

typedef struct Stack
{
	t_node	*top;
	int		size;
}				t_stack;

int		validate(int ac, char **av, t_stack *stack);
int		is_number(char	*av);

#endif