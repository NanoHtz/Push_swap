/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgalvez- <fgalvez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 11:15:22 by fgalvez-          #+#    #+#             */
/*   Updated: 2024/12/05 14:58:44 by fgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

# define ARGS_ERROR "There must be 2 or more arguments."
# define NO_NUMBER "The argument entered is not a number"
# define MEM_ERROR "Error in allocate stack"
# define PUSH_ERROR "Error in push function"
# define MIN_ERROR "A number less than the minimum has been entered"
# define MAX_ERROR "A number greater than the maximum has been entered"
# define INT_MIN -2147483648
# define INT_MAX 2147483647

# include <unistd.h>

int		ft_error(const char *str);
void	ft_void_error(const char *str);

#endif
