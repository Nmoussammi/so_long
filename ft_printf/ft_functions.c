/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_functions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmoussam <nmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 18:57:00 by nmoussam          #+#    #+#             */
/*   Updated: 2022/05/25 18:57:49 by nmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int nbr)
{
	int	cpt;

	cpt = 1;
	if (nbr == -2147483648)
	{
		write(1, "-2147483648", 11);
		cpt = 11;
	}
	else if (nbr < 0)
	{
		nbr = -nbr;
		ft_putchar(45);
		cpt += ft_putnbr(nbr);
	}
	else if (nbr <= 9)
		ft_putchar(nbr + '0');
	else
	{
		cpt += ft_putnbr(nbr / 10);
		ft_putnbr(nbr % 10);
	}
	return (cpt);
}

int	ft_putnbr_u(unsigned int nbr)
{
	int	cpt;

	cpt = 1;
	if (nbr < 10)
		ft_putchar(nbr + '0');
	else
	{
		cpt += ft_putnbr_u(nbr / 10);
		ft_putnbr_u(nbr % 10);
	}
	return (cpt);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_putstr(char *str)
{
	int	len;
	int	i;

	if (!str)
		str = "(null)";
	len = ft_strlen(str);
	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (len);
}

int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}
