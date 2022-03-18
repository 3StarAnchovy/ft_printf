/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_arg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihong <jihong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 20:43:59 by jihong            #+#    #+#             */
/*   Updated: 2022/03/18 20:53:26 by jihong           ###   ########.fr       */
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

void ft_put_unsigned_nbr(unsigned int n, int *len)
{
	rec_nb(n, 0, '\0', len);
}
