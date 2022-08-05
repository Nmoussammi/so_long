/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_move.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmoussam <nmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 18:07:24 by nmoussam          #+#    #+#             */
/*   Updated: 2022/05/24 19:10:15 by nmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	print_mouvement(t_map *data)
{
	data->move = ft_itoa(data->nb_move);
	data->string = ft_join("Number of movements :", data->move);
	mlx_string_put(data->mlx, data->mlx_win, 20, 20, 0x000000, data->string);
	free(data->move);
	free(data->string);
}
