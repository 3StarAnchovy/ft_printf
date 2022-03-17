/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihong <jihong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 20:37:36 by jihong            #+#    #+#             */
/*   Updated: 2022/03/17 22:35:42 by jihong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_putchar(char c_format, int *len)
{
	write(1, &c_format, 1);
	*len += 1;
}

void ft_putstr(char *str, int *len)
{
	int i;

	i = 0;
	if(str == NULL)
	{
		write(1,"(null)",6);
		*len += 6;
	}
	while(str[i] != '\0')
	{
		write(1, &str[i], 1);
		i ++;
		*len += 1;
	}
}

void	rec_nb(int div, int mod, char str, int *len)
{
	*len += 1;
	mod = div % 10;
	div /= 10;
	if (div != 0)
		rec_nb(div, mod, str, len);
	str = '0' + mod;
	write(1, &str, 1);
}

void	ft_putnbr(int n, int *len)
{
	char	str;
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		*len += 11;
	}
	else if (n < 0)
	{
		write(1, "-", 1);
		*len += 1;
		n *= -1;
		str = '\0';
		rec_nb(n, 0, str, len);
	}
	else
		rec_nb(n, 0, '\0', len);
}

// cspdiuxX%
int check_form(char c_format)
{
	if(c_format == 'c' || c_format == 's' || c_format == 'p' || c_format == 'd' ||
		c_format == 'i' || c_format == 'u' || c_format == 'x' || c_format == 'X')
			return (1);
	else
		return (0);
}

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

void check_style(int *len, char c_format, va_list ap)
{
	if(c_format == 'c')
		ft_putchar(va_arg(ap, int), len);
	if(c_format == 's')
		ft_putstr(va_arg(ap, char *), len);
	if(c_format == 'd')
		ft_putnbr(va_arg(ap, int), len);
	if(c_format == 'x' || c_format == 'X')
		ft_puthex(c_format, va_arg(ap, int), len);
	// if(c_format == 'p')
	// 	ft_hex_add(va_arg(ap, void *), len);
}
