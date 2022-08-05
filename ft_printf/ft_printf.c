/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmoussam <nmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 18:57:29 by nmoussam          #+#    #+#             */
/*   Updated: 2022/05/25 18:58:08 by nmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_check_args(char c, va_list args, int nb)
{
	if ((c == 'd') || (c == 'i'))
		nb = ft_putnbr(va_arg(args, int));
	else if (c == 's')
		nb = ft_putstr(va_arg(args, char *));
	else if (c == 'c')
		nb = ft_putchar(va_arg(args, int));
	else if (c == 'x')
		nb = ft_putnbr_lower(va_arg(args, unsigned int));
	else if (c == 'X')
		nb = ft_putnbr_upper(va_arg(args, unsigned int));
	else if (c == 'u')
		nb = ft_putnbr_u(va_arg(args, unsigned int));
	else if (c == 'p')
	{
		nb = write(1, "0x", 2);
		nb += ft_putnbr_p(va_arg(args, unsigned long));
	}
	else if (c == '%')
		nb = ft_putchar(37);
	return (nb);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		cpt;

	i = 0;
	cpt = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if ((ft_strchr("discxXup%", format[i]) == NULL) \
			|| format[i] == '\0')
				continue ;
			cpt += ft_check_args(format[i], args, cpt);
		}
		else
			cpt += ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (cpt);
}
