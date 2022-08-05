/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmoussam <nmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 18:57:27 by nmoussam          #+#    #+#             */
/*   Updated: 2022/05/25 18:58:21 by nmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
int		ft_putnbr(int nbr);
int		ft_strlen(char *str);
int		ft_putstr(char *str);
int		ft_putchar(int c);
int		ft_putnbr_lower(unsigned int nbr);
int		ft_putnbr_upper(unsigned int nbr);
int		ft_putnbr_p(unsigned long nbr);
int		ft_putnbr_u(unsigned int nbr);
char	*ft_strchr(const char *s, int c);

#endif