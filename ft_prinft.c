/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prinft.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihong <jihong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 19:21:04 by jihong            #+#    #+#             */
/*   Updated: 2022/03/12 20:52:37 by jihong           ###   ########.fr       */
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
			{

			}
			else
				ft_putchar(format[i], &len);
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
	int num = ft_printf("%%");
	printf("\n");
	printf("%d",num);
}
