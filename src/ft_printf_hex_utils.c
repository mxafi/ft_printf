/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaakso <malaakso@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 23:47:51 by malaakso          #+#    #+#             */
/*   Updated: 2022/11/26 01:11:08 by malaakso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_hex_utils.h"
#include "libft.h"

int	ft_int_puthex_lower_fd(unsigned long n, int fd)
{
	int				count;
	int				remainder;
	char			hex[64];

	count = 0;
	while (n && count < 64)
	{
		remainder = n % 16;
		if (remainder < 10)
			remainder += '0';
		else
			remainder += 87;
		n /= 16;
		hex[count] = (char)remainder;
		count++;
	}
	hex[count] = '\0';
	(void)ft_strrev(hex);
	count = ft_int_putstr_fd("0x", fd);
	count += ft_int_putstr_fd(hex, fd);
	return (count);
}
