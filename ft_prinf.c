/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prinf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihong <jihong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 19:21:04 by jihong            #+#    #+#             */
/*   Updated: 2022/03/16 21:08:12 by jihong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
//문자열 개수 리턴해야함.


int ft_printf(const char *format, ...)
{
	int	len;
	int	i;
	va_list ap;

	len = 0;
	i = 0;
	va_start(ap,format);
	while(format[i])
	{
		if(format[i] == '%')
		{
			if(format[i + 1] == '%')
				ft_putchar(format[i + 1], &len);
			else if(check_form(format[i + 1]))
				check_style(&len, format[i + 1], ap);
			else
				ft_putchar(format[i + 1], &len);
		}
		else
			ft_putchar(format[i], &len);
		i ++;
	}
	va_end(ap);
	return (len);
}

int main()
{
	int test = -2147483649;
	int num = printf("%d",test);
	printf("\n");
	printf("%d",num);
}
