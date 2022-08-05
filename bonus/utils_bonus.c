/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmoussam <nmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 19:07:55 by nmoussam          #+#    #+#             */
/*   Updated: 2022/05/25 16:51:48 by nmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	nbr_chr(long int n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		n = -1 * n;
		i++;
	}
	while (n > 9)
	{
		n = n / 10;
		i++;
	}
	if (n <= 9)
		i++;
	return (i);
}

char	*ft_itoa(int n)
{
	char	*str;
	long	nb;
	int		p;
	int		len ;

	nb = n;
	len = nbr_chr(n);
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	p = 0;
	if (nb < 0)
	{
		str[0] = '-';
		nb *= -1;
		p = 1;
	}
	str[len] = '\0';
	while (--len >= p)
	{
		str[len] = (nb % 10) + '0';
		nb /= 10;
	}
	return (str);
}

void	*ft_memcpy(void *dst, const void *src, int n)
{
	int				i;
	unsigned char	*pdst;
	unsigned char	*psrc;

	if (!src && !dst)
		return (NULL);
	psrc = (unsigned char *)src;
	pdst = (unsigned char *)dst;
	i = 0;
	while (i < n)
	{
		pdst[i] = psrc[i];
		i++;
	}
	return (dst);
}

void	*ft_memmove(void *dst, const void *src, int len)
{
	unsigned char	*psrc;
	unsigned char	*pdst;

	if (src == dst)
	{
		return (dst);
	}
	else if (src > dst)
	{
		return (ft_memcpy(dst, src, len));
	}
	psrc = (unsigned char *)src;
	pdst = (unsigned char *)dst;
	while (len--)
	{
		pdst[len] = psrc[len];
	}
	return (dst);
}

char	*ft_join(char *s1, char *s2)
{
	char	*t;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	i = ft_strlen(s1);
	j = ft_strlen(s2);
	t = malloc((i + j + 1) * sizeof(char));
	if (!t)
		return (NULL);
	ft_memmove(t, s1, i);
	ft_memmove(t + i, s2, j);
	t[i + j] = 0;
	return (t);
}
