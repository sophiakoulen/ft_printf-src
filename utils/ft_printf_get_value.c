/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_get_value.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 10:51:05 by skoulen           #+#    #+#             */
/*   Updated: 2022/11/07 10:51:16 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_get_value(va_list ap, char specifier, t_value *val)
{
	if (specifier == 'i' || specifier == 'd' || specifier == 'c')
		val->i = va_arg(ap, int);
	else if (specifier == 'u' || specifier == 'x' || specifier == 'X')
		val->u = va_arg(ap, unsigned);
	else if (specifier == 's')
		val->s = va_arg(ap, char *);
	else if (specifier == 'p')
		val->p = va_arg(ap, void *);
}
