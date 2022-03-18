/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihong <jihong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 20:37:36 by jihong            #+#    #+#             */
/*   Updated: 2022/03/18 20:46:56 by jihong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_puthex(char c_format, int n, int *len)
{
	char	*hex;
	int		i;

	i = 0;
	if(c_format == 'x')
		hex = "0123456789abcdef";
	if(c_format == 'X')
		hex = "0123456789ABCDEF";
	if(n > 15)
	{
		*len += 1;
		ft_puthex(c_format, n/16, len);
		ft_putchar(hex[n % 16], len);
	}
	else
		ft_putchar(hex[n], len);
}

void	ft_put_hex_adr(unsigned long adr, int *len)
{
	char *hex;

	hex = "0123456789abcdef";
	if(adr > 15)
	{
		ft_put_hex_adr(adr/16, len);
		ft_putchar(hex[adr % 16], len);
	}
	else
		ft_putchar(hex[adr], len);
}

int check_form(char c_format)
{
	if(c_format == 'c' || c_format == 's' || c_format == 'p' || c_format == 'd' ||
		c_format == 'i' || c_format == 'u' || c_format == 'x' || c_format == 'X')
			return (1);
	else
		return (0);
}

void check_style(int *len, char c_format, va_list ap)
{
	if(c_format == 'c')
		ft_putchar(va_arg(ap, int), len);
	if(c_format == 's')
		ft_putstr(va_arg(ap, char *), len);
	if(c_format == 'd' || c_format == 'i')
		ft_putnbr(va_arg(ap, int), len);
	if(c_format == 'u')
		ft_put_unsigned_nbr(va_arg(ap, unsigned int), len);
	if(c_format == 'x' || c_format == 'X')
		ft_puthex(c_format, va_arg(ap, int), len);
	if(c_format == 'p')
	{
		write(1,"0x",2);
		*len += 2;
		ft_put_hex_adr(va_arg(ap, unsigned long), len);
	}
}
