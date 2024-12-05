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

# include <unistd.h>

int		ft_error(const char *str);

#endif
