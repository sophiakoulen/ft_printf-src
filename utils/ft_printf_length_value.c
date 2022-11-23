/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_length_value.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 10:51:22 by skoulen           #+#    #+#             */
/*   Updated: 2022/11/07 10:54:09 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_length_value(t_value val, char specifier)
{
	int	res;

	if (specifier == 'i' || specifier == 'd')
		res = ft_nbr_len(val.i, 10);
	else if (specifier == 'u')
		res = ft_nbr_len_unsigned(val.u, 10);
	else if (specifier == 'x' || specifier == 'X')
		res = ft_nbr_len_unsigned(val.u, 16);
	else if (specifier == 'c' || specifier == '%')
		res = 1;
	else if (specifier == 's')
	{
		if (val.s)
			res = ft_strlen(val.s);
		else
			res = ft_strlen("(null)");
	}
	else if (specifier == 'p')
		res = 2 + ft_nbr_len_unsigned((size_t)val.p, 16);
	else
		res = 0;
	return (res);
}
