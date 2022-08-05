/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_functions2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmoussam <nmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 18:57:31 by nmoussam          #+#    #+#             */
/*   Updated: 2022/05/25 18:58:00 by nmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#define BASE1 "0123456789ABCDEF"
#define BASE2 "0123456789abcdef"

int	ft_putnbr_lower(unsigned int nbr)
{
	int	cpt;

	cpt = 1;
	if (nbr < 16)
		ft_putchar(BASE2[nbr]);
	else
	{
		cpt += ft_putnbr_lower(nbr / 16);
		ft_putnbr_lower(nbr % 16);
	}
	return (cpt);
}

int	ft_putnbr_upper(unsigned int nbr)
{
	int	cpt;

	cpt = 1;
	if (nbr < 16)
		ft_putchar(BASE1[nbr]);
	else
	{
		cpt += ft_putnbr_upper(nbr / 16);
		ft_putnbr_upper(nbr % 16);
	}
	return (cpt);
}

int	ft_putnbr_p(unsigned long nbr)
{
	int	cpt;

	cpt = 1;
	if (nbr < 16)
		ft_putchar(BASE2[nbr]);
	else
	{
		cpt += ft_putnbr_p(nbr / 16);
		ft_putnbr_p(nbr % 16);
	}
	return (cpt);
}

char	*ft_strchr(const char *s, int c)
{
	char	ch;
	char	*pchr;

	pchr = (char *)s;
	ch = (char)c;
	while (*pchr != '\0')
	{
		if (*pchr == ch)
			return (pchr);
		pchr++;
	}
	if (*pchr == ch)
		return (pchr);
	return (NULL);
}
