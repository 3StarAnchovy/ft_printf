/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_arg2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihong <jihong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 20:37:36 by jihong            #+#    #+#             */
/*   Updated: 2022/04/08 20:11:26 by jihong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_puthex(char c_format, unsigned int n, int *len)
{
	char	*hex;
	int		i;

	i = 0;
	if (c_format == 'x')
		hex = "0123456789abcdef";
	if (c_format == 'X')
		hex = "0123456789ABCDEF";
	if (n > 15)
	{
		ft_puthex(c_format, n / 16, len);
		ft_putchar(hex[n % 16], len);
	}
	else
		ft_putchar(hex[n], len);
}

void	ft_put_hex_adr(unsigned long adr, int *len)
{
	char	*hex;

	hex = "0123456789abcdef";
	if (adr > 15)
	{
		ft_put_hex_adr(adr / 16, len);
		ft_putchar(hex[adr % 16], len);
	}
	else
		ft_putchar(hex[adr], len);
}
