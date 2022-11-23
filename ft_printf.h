/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 10:50:04 by skoulen           #+#    #+#             */
/*   Updated: 2022/11/23 13:38:24 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

# define DECIMAL	"0123456789"
# define HEX_UPPER	"0123456789ABCDEF"
# define HEX_LOWER	"0123456789abcdef"

typedef union u_value
{
	int				i;
	unsigned int	u;
	char			*s;
	void			*p;
}	t_value;

int		ft_printf(const char *format, ...);
int		ft_vprintf(const char *format, va_list ap);
int		ft_vdprintf(int fd, const char *format, va_list ap);
int		ft_dprintf(int fd, const char *format, ...);

void	ft_printf_get_value(va_list ap, char specifier, t_value *val);
void	ft_printf_print_value(t_value val, char specifier, int fd);
int		ft_printf_length_value(t_value val, char specifier);

#endif