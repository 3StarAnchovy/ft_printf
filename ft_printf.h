/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihong <jihong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 19:30:51 by jihong            #+#    #+#             */
/*   Updated: 2022/03/16 19:47:11 by jihong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>

void	ft_putchar(char c_format, int *len);
int		ft_printf(const char *, ...);
int		check_form(char c_format);
void	check_style(int *len, char c_format, va_list ap);
