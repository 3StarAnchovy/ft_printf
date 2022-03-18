/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihong <jihong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 19:30:51 by jihong            #+#    #+#             */
/*   Updated: 2022/03/18 20:53:50 by jihong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>

void	ft_putchar(char c_format, int *len);
void	ft_putstr(char *str, int *len);
void	rec_nb(int div, int mod, char str, int *len);
void	ft_put_unsigned_nbr(unsigned int n, int *len);
void	ft_putnbr(int n, int *len);
int		ft_printf(const char *, ...);
int		check_form(char c_format);
void	printf_form(int *len, char c_format, va_list ap);
void	ft_puthex(char c_format, int n, int *len);
void	ft_put_hex_adr(unsigned long adr, int *len);
