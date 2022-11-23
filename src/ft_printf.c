/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaakso <malaakso@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 15:47:02 by malaakso          #+#    #+#             */
/*   Updated: 2022/11/23 15:47:40 by malaakso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprintf.h"

int	ft_printf(const char *input, ...)
{
	va_list	args;
	long	n_of_characters_printed;

	va_start(args, input);
	n_of_characters_printed = 0;

	va_end(args);
	return ((int)n_of_characters_printed);
}
