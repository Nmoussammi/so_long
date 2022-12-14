/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmoussam <nmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 12:45:27 by nmoussam          #+#    #+#             */
/*   Updated: 2022/05/24 16:37:22 by nmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_file(char *filename)
{
	int	len;

	len = ft_strlen(filename);
	if (filename[len - 1] == 'r' && filename[len - 2] == 'e' \
		&& filename[len - 3] == 'b' && filename[len - 4] == '.')
		return (1);
	return (0);
}

void	ft_print_message_error(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return ;
	while (str[i] != '\0')
		write(1, &str[i++], 1);
	exit(1);
}

void	ft_free(t_map *data)
{
	free(data);
	exit(1);
}
