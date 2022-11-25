/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaakso <malaakso@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 15:47:02 by malaakso          #+#    #+#             */
/*   Updated: 2022/11/26 01:12:39 by malaakso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_utils.h"
#include "ft_printf_hex_utils.h"

static int	resolve_flag_hex(const char *flag, va_list args)
{
	int	count;

	count = 0;
	if (*flag == 'p')
		count = ft_int_puthex_lower_fd((unsigned long)va_arg(args, void *), 1);
	return (count);
}

static int	resolve_flag_2(const char *flag, va_list args)
{
	int	count;

	count = 0;
	if (*flag == 'p')
		count = resolve_flag_hex(flag, args);
	// else if (*flag == 'x')
	// else if (*flag == 'X')
	return (count);
}

static int	resolve_flag_1(const char *flag, va_list args)
{
	int	count;

	count = 0;
	if (*flag == '%')
		count = ft_int_putchar_fd('%', 1);
	else if (*flag == 'c')
		count = ft_int_putchar_fd((char)va_arg(args, int), 1);
	else if (*flag == 's')
	{
		count = ft_int_putstr_fd(va_arg(args, char *), 1);
		if (count == -1)
			count = ft_int_putstr_fd("(null)", 1);
	}
	else if (*flag == 'd')
		count = ft_int_putnbr_fd(va_arg(args, int), 1);
	else if (*flag == 'i')
		count = ft_int_putnbr_fd(va_arg(args, int), 1);
	else if (*flag == 'u')
		count = ft_int_putnbr_uint_fd((unsigned int)va_arg(args, unsigned int),
				1);
	else
		count = resolve_flag_2(flag, args);
	return (count);
}

int	ft_printf(const char *input, ...)
{
	va_list	args;
	long	n_of_characters_printed;

	va_start(args, input);
	n_of_characters_printed = 0;
	while (*input)
	{
		while (*input != '%')
		{
			n_of_characters_printed += ft_int_putchar_fd(*input, 1);
			input++;
			if (!*input)
				break ;
		}
		if (*input == '%')
		{
			input++;
			n_of_characters_printed += resolve_flag_1(input, args);
		}
		if (!*input)
			break ;
		input++;
	}
	va_end(args);
	return ((int)n_of_characters_printed);
}
