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
# define FEW_ERROR "Insufficient arguments"
# define FEW_NODES "Insufficient nodes in stack or no stack"
# define OUT_OF_RANGE "The arguments go out of range"
# define DUPLICATE "The arguments are duplicated"
# define VALIDATE "Error in validate function"
# define VALID "All arguments are valid"
# define INT_MIN -2147483648
# define INT_MAX 2147483647

# include <unistd.h>

//Basic
void	ft_strendl(const char *str);
//Errors
int		ft_error(const char *str);
void	ft_void_error(const char *str);
int		*ft_ptr_error(const char *str);
int		ft_max_error(const char *str);
int		ft_min_error(const char *str);
//Warnings
void	ft_warning(const char *str);
//Sucess
void	ft_success(const char *str);

#endif
