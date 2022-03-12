/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihong <jihong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 20:37:36 by jihong            #+#    #+#             */
/*   Updated: 2022/03/12 20:49:23 by jihong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_putchar(char c_format, int *len)
{
	write(1, &c_format, 1);
	*len += 1;
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
