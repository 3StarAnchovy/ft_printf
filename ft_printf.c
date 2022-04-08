/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihong <jihong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 19:21:04 by jihong            #+#    #+#             */
/*   Updated: 2022/04/08 20:06:16 by jihong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_form(char c_format)
{
	if (c_format == 'c' || c_format == 's' || c_format == 'p'
		|| c_format == 'd' || c_format == 'i'
		|| c_format == 'u' || c_format == 'x' || c_format == 'X')
		return (1);
	else
		return (0);
}

void	print_form(int *len, char c_format, va_list *ap)
{
	if (c_format == 'c')
		ft_putchar(va_arg(*ap, int), len);
	if (c_format == 's')
		ft_putstr(va_arg(*ap, char *), len);
	if (c_format == 'd' || c_format == 'i')
		ft_putnbr(va_arg(*ap, int), len);
	if (c_format == 'u')
		ft_put_unsigned_nbr(va_arg(*ap, unsigned int), len);
	if (c_format == 'x' || c_format == 'X')
		ft_puthex(c_format, va_arg(*ap, unsigned int), len);
	if (c_format == 'p')
	{
		write(1, "0x", 2);
		*len += 2;
		ft_put_hex_adr(va_arg(*ap, unsigned long), len);
	}
}

int	ft_printf(const char *format, ...)
{
	int		len;
	int		i;
	va_list	ap;

	len = 0;
	i = 0;
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == '%')
				ft_putchar(format[i + 1], &len);
			else if (check_form(format[i + 1]))
				print_form(&len, format[i + 1], &ap);
			else
				ft_putchar(format[i + 1], &len);
			i ++;
		}
		else
			ft_putchar(format[i], &len);
		i ++;
	}
	va_end(ap);
	return (len);
}
